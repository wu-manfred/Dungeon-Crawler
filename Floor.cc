#include "Floor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "stdlib.h"
using namespace std;
#include "Doorway.h"
#include "Passage.h"
#include "FloorTile.h"
#include "Wall.h"
#include "EmptyCell.h"
#include "Shade.h"
#include "Dwarf.h"
#include "Vampire.h"
#include "Human.h"
#include "Goblin.h"
#include "Drow.h"
#include "Troll.h"
#include "generateEnemy.h"
#include "generateItem.h"
#include <cstdlib>
#include <ctime>

// used to calculate the new positions based on direction
void Floor::calculateDirection (int &x, int &y,string direction,int gen){
	if (direction == "no" || gen == 0){
		x = x-1;
	}else if(direction=="so" || gen == 1){
		x = x+1;
	}else if(direction == "ea" || gen == 2){
		y = y+1;
	}else if(direction == "we"|| gen == 3){
		y = y-1;
	}else if(direction == "ne"|| gen == 4){
		x = x-1;
		y = y+1;
	}else if(direction=="se"|| gen == 5){
		x = x+1;
		y = y+1;
	}else if(direction=="nw"|| gen == 6){
		x = x-1;
		y = y-1;
	}else if(direction=="sw"|| gen == 7){
		x = x+1;
		y = y-1;
	}
}


Floor :: Floor(ifstream &file):file{file}{}			

Floor :: ~Floor(){}

bool Floor::validFloorTile(Cell * c){
	// check to see if a cell is a floortile that has not been added in a chamber yet
	char cdisplay = c->getInfo().display;
	if (cdisplay != ' ' &&
            cdisplay != '|' &&
            cdisplay != '-' &&
            cdisplay != '#' &&
            cdisplay != '+' &&
            cdisplay != '\\' &&
	    !(c->getInfo().addedToChamber)){
		return true;
	} else {
		return false;
	}
}

void Floor::createChambers(){
	// for loop to search for the start of a new chamber
	for (int i = 0; i<len; ++i){
		for (int j = 0; j<width; ++j){
			// create a new chamber
			vector <pair <int, int>> temp;
			Cell * curcell = theFloor[i][j];
			singleChamber(temp,curcell);
			if (temp.size() > 0){
				// if block only reached if a chamber was created in temp
				Chamber.push_back(temp); // add the chamber to the vector of chambers in floor
			} 
		}
	}
}

void Floor::singleChamber(vector<pair<int, int>> &chamber, Cell* curcell){
	if (!validFloorTile(curcell)){
		return;
	} // quit function if the current cell is not a valid floortile
	// add current cell to the chamber given as a parameter in the form of a pair int
	int x = curcell->getInfo().xPos;
	int y = curcell->getInfo().yPos;
	pair <int, int> tile = make_pair(x, y);
	chamber.push_back(tile);
	curcell->flipAddedToChamber();
	// recursively call function on cells around the current one
	singleChamber(chamber, theFloor[x][y-1]);
	singleChamber(chamber, theFloor[x+1][y]);
	singleChamber(chamber, theFloor[x][y+1]);
	singleChamber(chamber, theFloor[x-1][y]);
}

void Floor::readFloor(){
	if (read == false){
		read = true;
	}
	char c;
	//reading in the file to create the initial board and initialize the different types of cells	
	width = 79; 
	len = 25;
	for (int i = 0; i<len; ++i){
		vector<Cell*> temp;
		for (int j = 0; j<width; ++j){
			file.get(c);
			if(c=='|') temp.push_back(new Wall(i,j,true));
            else if(c=='-') temp.push_back(new Wall(i,j,false));
            else if(c=='#') temp.push_back(new Passage(i,j));
            else if(c=='+') temp.push_back(new Doorway(i,j));
            else if(c==' ') temp.push_back(new EmptyCell(i,j));
            else if(c=='\\'){
            	Cell *t = new FloorTile(i,j); 
            	t->setDisplay('\\');
            	temp.push_back(t);
            }else{
				temp.push_back(new FloorTile(i,j));
				if (c!='.'){
					Character *character = nullptr;
					Item *item = nullptr;
					if (c=='H')character = new Human();
					else if (c=='W')character = new Dwarf();
					else if (c=='E')character = new Elf();
					else if (c=='L')character = new Halfling();
					else if (c=='M')character = new Merchant();
					else if (c=='O')character = new Orc();
					else if (c=='@')temp[j]->moveTo(pc);
					else if (c=='0')item = new RH(i, j);
					else if (c=='1')item = new BA(pc, i, j);
					else if (c=='2')item = new BD(pc, i, j);
					else if (c=='3')item = new PH(i, j);
					else if (c=='4')item = new WA(pc, i, j);
					else if (c=='5')item = new WD(pc, i, j);
					else if (c=='6')item = new Treasure(i, j, 2);
					else if (c=='7')item = new Treasure(i, j, 1);
					else if (c=='8')item = new Treasure(i, j, 4); 
					//missing dragon
					if (character){
						temp[j]->moveTo(character);
					} else if (item){
						temp[j]->placeItem(item);
					}
				}
			}
		}
		theFloor.push_back(temp);
		file.get(c);	
	}
	
}

void Floor::init(){
	level = 1;

	ActionDisplay::setFloor(level);
	td = new TextDisplay{theFloor};
	for (int i = 0; i < len ; ++i){
		for (int j = 0 ; j < width ; ++j){
			if (i!=0){
				theFloor[i][j]->attach(theFloor[i-1][j]); // the ones above
			}
			if(i!=len-1){
				theFloor[i][j]->attach(theFloor[i+1][j]); //the ones below
			}
			if(j!=0){
				theFloor[i][j]->attach(theFloor[i][j-1]); //the ones on the left
			}
			if(j!=width-1){
				theFloor[i][j]->attach(theFloor[i][j+1]); // the ones on the right
			}
			if(i!=0 && j !=0){
				theFloor[i][j]->attach(theFloor[i-1][j-1]); // the NW one
			}
			if(i!=0 && j!=width-1){
				theFloor[i][j]->attach(theFloor[i-1][j+1]); //the NE one
			}
			if(i!=len-1 && j!= 0){
				theFloor[i][j]->attach(theFloor[i+1][j-1]); // the SW one
			}
			if(i!=len-1 && j!= width-1){
				theFloor[i][j]->attach(theFloor[i+1][j+1]);
			}
		}
	}
	createChambers();
}

void Floor::setBoard(){
	int pcCham = 0;
	int scCham = 0;
	while(pcCham==scCham){
		pcCham = genChamberNum();
		scCham = genChamberNum();
	}
	generatePC(pcCham);
	genStairCase(scCham);
	generateEnemies();
	generatePotions();
	generateGold();
}

int Floor::whatOnCell(Cell *c){
	// returns 0 if nothing on cell, 1 if item, 2 if character
	return c->cellContents();
}

void Floor::dropGold(int x, int y, char type){
	if (type == 'H'){
		Item * pile1 = new Treasure(x,y, smallGold);
                theFloor[x][y]->placeItem(pile1);
		int newX = x;
		int newY = y;
		while(true){
			int gen = rand() % 8;
                        calculateDirection(newX,newY,"",gen);
                        if(theFloor[newX][newY]->getInfo().display== '.'){
				Item * pile2 = new Treasure(newX, newY, smallGold);
				theFloor[newX][newY]->placeItem(pile2);
                        	break;
                        }else{
				newX = x;
				newY = y;
			}
		}
	}
	else if (type == 'M'){
		Item * pile1 = new Treasure(x,y, normalGold);
                theFloor[x][y]->placeItem(pile1);
	}
}

int Floor::getScore(){
	return pc->getGold();
}
	
bool Floor::attackEnemy(string direction){
	int x = pc->getX();
	int y = pc->getY();

	int posX = x;
	int posY = y;

	calculateDirection(posX,posY,direction);

	bool result = (theFloor[posX][posY]->cellContents()==2) ? true: false;
	if(result){
		Character *theEnemy = theFloor[posX][posY]->getInfo().charOnTile;
		char type = theEnemy->getDisplay();
		if(theEnemy->beStruckBy(*pc)){
			theFloor[posX][posY]->emptyCell();
			if(type == 'H'){
				dropGold(posX, posY, 'H');
			} else if(type == 'M'){
				dropGold(posX, posY, 'M');
			}
			else {
				int goldEarned = 1 + rand() % 1; 
				pc->setGold(pc->getGold() + goldEarned);
			}

		}		
		
		//get rid of switch only later
		theFloor[x][y]->notifyObservers(SubscriptionType::SwitchOnly);
	}
	if(pc->getHP()<=0)return false;
	moveEnemy();
	ActionDisplay::setCharacterStats(*pc);
	return true;
}
void Floor::useItem(string direction){
	int x = pc->getX();
	int y = pc->getY();

	int itemX = x;
	int itemY = y;

	calculateDirection(itemX,itemY,direction);
	Cell * itemCell = theFloor[itemX][itemY];
	bool result = ((itemCell->cellContents()==1) && (itemCell->getInfo().itemOnTile->getDisplay() == 'P')) ? true: false;
	if(result){
		itemCell->useItem(pc);
		if(itemCell->getInfo().itemOnTile->getDisplay() == 'P'){
			string type = itemCell->getInfo().itemOnTile->getName();
			ActionDisplay::setPotion(type,true);
		}
		itemCell->emptyCell();
	}

	ActionDisplay::setCharacterStats(*pc);
}

void Floor::removePotions(){
	pc = pc->removeDec();
}

int Floor::movePC(string direction){

	//getting the current pc's positions
	int x = pc->getX();
	int y = pc->getY();
	// new postitions
	int newX = x;
	int newY = y;
	calculateDirection(newX,newY,direction);

	if (theFloor[newX][newY]->getInfo().display=='\\'){
		if(level == 5){
			return -1;
		}
		theFloor[x][y]->emptyCell();
		theFloor[newX][newY]->setDisplay('.');
		clearFloor();

	}else{

		bool result = theFloor[newX][newY]->moveTo(pc);
		//if sucessfully moved
		if (result){
			theFloor[x][y]->emptyCell();
			// the x and y here are the new position of the character
			theFloor[newX][newY]->notifyObservers(SubscriptionType::SwitchOnly);

			if (pc->getHP()<=0){
				return 0;
			}
			moveEnemy();
		}
		ActionDisplay::setMoveDescription(direction);
		ActionDisplay::setCharacterStats(*pc);
}
	
	return 1;

}
void Floor::genStairCase(int chamberNum){
	int x = 0;
	int y = 0;
	genCellPos(x,y,chamberNum);
	theFloor[x][y]->setDisplay('\\');
}

int Floor :: genChamberNum (){
	int theChamber = rand() % numChambers;
	return theChamber;
}

//Finds a Cell which is not occupied by an item or Character
void Floor::genCellPos(int &x, int &y, int chamberNum){
	int theChamber = chamberNum; 
	int chamberSize, theCell;
        while(true){
        	if(chamberNum==-1)theChamber = genChamberNum();
                chamberSize = Chamber[theChamber].size();
                theCell = rand() % chamberSize;
                x = Chamber[theChamber][theCell].first;
                y = Chamber[theChamber][theCell].second;
                if (theFloor[x][y]->cellContents() == 0){
                    break;
                }
        }
       
}
void Floor::placePotion(){
	int x = 0;
	int y = 0;
	genCellPos(x,y);
	Item * newPotion = generateItem::generatePotion(pc, x, y);
	theFloor[x][y]->placeItem(newPotion);
}


void Floor::placeEnemy(){
	int x = 0;
	int y = 0;
	Character * newEnemy = generateEnemy::generate();
	genCellPos(x,y);
	theFloor[x][y]->moveTo(newEnemy);
}

void Floor::placeGold(){
	int x = 0;
	int y = 0;
	genCellPos(x,y);
	Item * newGold = generateItem::generateGold(x,y);
	string type = newGold->getName();
	if (type == "gold"){theFloor[x][y]->placeItem(newGold);}
	if (type == "hoard"){
		theFloor[x][y]->placeItem(newGold);
		DHoard * theHoard = reinterpret_cast<DHoard *>(newGold);
		int newX = x;
		int newY = y;
		while(true){
                        int gen = rand() % 8;
                        calculateDirection(newX,newY,"",gen);
                        if(theFloor[newX][newY]->getInfo().display== '.'){
                                theFloor[newX][newY]->moveTo(theHoard->getDrag());
                                break;
                        }else{
                                newX = x;
                                newY = y;
                        }
                }
	}	
}	

void Floor::generateGold(){
	for(int i = 0; i < 10; ++ i){
		placeGold();
	}
}

void Floor::generatePotions(){
	for(int i = 0; i < 10; ++ i){
		placePotion();
	}
}

void Floor::generateEnemies(){
	for (int i = 0; i < 20; ++ i){
		placeEnemy();
	}
}
			
void Floor::stopEnemy(){
	enemyStop=!enemyStop;
}		
		
	
void Floor::moveEnemy(){
	if(enemyStop)return; 

	vector<pair<int,int>> movedEnemies;

	for (int i = 0; i < len; ++i){
		for (int j = 0; j < width; ++j){
			
			if(theFloor[i][j]->getInfo().charOnTile){
				char c = theFloor[i][j]->getInfo().charOnTile->getDisplay();
				
				// if it's an enemy 
				if(c=='H' || c=='W'|| c=='E' || c=='O' || c=='L' || c=='M'){
					Character * temp = theFloor[i][j]->getInfo().charOnTile;

					// if it's never been moved 
					if(temp->getMoved()){movedEnemies.push_back(make_pair(i,j));}
					else{
						int newX = i;
						int newY = j;
						bool result = false;
						// repeat until its possible to move to the cell
						while(!result){
						int gen = rand() % 8;
						calculateDirection(newX,newY,"",gen);
							if(theFloor[newX][newY]->getInfo().display== '.'){
								result = theFloor[newX][newY]->moveTo(temp);
							}else result = false;
							if(!result){
								newX = i;
								newY = j;
							}
						}

						theFloor[newX][newY]->getInfo().charOnTile->setMoved();
						movedEnemies.push_back(make_pair(newX,newY));
						theFloor[i][j]->emptyCell();	
						
					}
				}
			}
		}
	}

	for (int i = 0; i < movedEnemies.size(); ++i){

		int x = movedEnemies[i].first;
		int y = movedEnemies[i].second;
		theFloor[x][y]->getInfo().charOnTile->setMoved();
	}

}

void Floor::setPC(string race){
	Character *temp = nullptr;
	if(pc){
		temp = pc;
	}
	string type = "";
	if(race == "v"){
		pc = new Vampire();
		type = "Vampire";
	}else if (race=="d"){
		pc = new Drow();
		type = "Drow";
	}else if (race == "g"){
		pc = new Goblin();
		type = "Goblin";
	}else if (race == "t"){
		pc = new Troll();
		type = "Troll";
	}else{
		pc = new Shade();
		type = "Shade";
	}
	ActionDisplay::setRace(type);
	delete temp;
	
}

void Floor::generatePC(int chamberNum){
	int x = 0; 
	int y = 0;
	genCellPos(x,y,chamberNum);

	theFloor[x][y]->moveTo(pc);	
	ActionDisplay::setSpecial("Player character has spawned");
	ActionDisplay::setCharacterStats(*pc);
}


void Floor :: clearFloor(){
	// int x = pc->getX();
	// int y = pc->getY();
	// theFloor[x][y]->emptyCell();
	// cout << "one" << endl;
	for (int i = 0 ; i < len; ++i){
		for (int j = 0; j < width; ++j){
			//cout << i << " " << j << " ";
			//cout << theFloor[i][j]->getInfo().display << endl;
			theFloor[i][j]->emptyCell();
		}
	}
	//cout << "two" << endl;
	level ++;
		ActionDisplay::setFloor(level);
		ActionDisplay::clearAction();
		//removePotions();
		if (read == false){
			setBoard();
		} else {
			theFloor.clear();
			Chamber.clear();
			readFloor();
			ActionDisplay::setSpecial("Player character has spawned.");
			ActionDisplay::setCharacterStats(*pc);
		}
		
	
}

ostream &operator<<(ostream &out, const Floor &f){
	out << *(f.td);
	return out;
}

