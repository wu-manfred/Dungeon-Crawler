#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "TextDisplay.h"
#include "Cell.h"

const int numChambers = 5;

class Character;
class PC;
class Floor {
	std::vector<std::vector<std::pair<int,int>>> Chamber;
	std::vector<std::vector<Cell*>> theFloor;
	int level, len, width; //Current level
	TextDisplay *td; // The text display
	std::ifstream &file;
	Character *pc = nullptr;
	void calculateDirection (int &x, int &y,std::string,int gen = -1);
	bool read = false;
	bool enemyStop = false;
public:
	void createChambers();
	void singleChamber(std::vector<std::pair<int, int>> &, Cell*);
	Floor(std::ifstream &file);
	~Floor();
	void init();
	void setBoard();
	void readFloor();
	int genChamberNum();
	bool validFloorTile(Cell *);
	void generatePC(int chamberNum);
	void genCellPos(int &x, int &y , int chamberNum = -1);
	void placeEnemy();
	void placePotion();
	int getScore();
	void placeGold();
	void generateGold();
	void stopEnemy();
	void generatePotions();
	void generateEnemies();
	void dropGold(int x, int y, char type);
	void setPC(std::string race);
	void useItem(std::string direction);
	int movePC(std::string direction);
	bool attackEnemy(std::string direction);
	void genStairCase(int chamberNum);
	int whatOnCell(Cell *);
	void moveEnemy();
	void removePotions();
	void clearFloor(); //frees the Floor
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};


#endif
