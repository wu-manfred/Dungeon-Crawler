#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Floor.h"
#include "ActionDisplay.h"
using namespace std;

int main(int argc, char *argv[]){
  srand(time(NULL));
  cin.exceptions(ios::eofbit|ios::failbit);
  try{
  string s;
  if (argc > 1){
	s = argv[1];
  } else {
  	s = "default.txt";
  }
  ifstream file {s};
  string characterType = "";
  string cmd;
  Floor board {file};
  
	
  	cout << "Please pick a race: ";
  	cin >> cmd; 
  	if(cin.eof()){return 0;}
  	if(cmd == "s" || cmd == "g" || cmd == "v" || cmd == "t" || cmd == "d") {
  		board.setPC(cmd);
  		characterType = cmd;
  	}
  	else if(cmd == "q") return 0; //quits the game automatically
  	else board.setPC("s"); 
  	
  	board.readFloor();
	board.init();
	if (argc <= 1){
		board.setBoard();
	}
	cout << board << endl;
	
		while(true){
			cin >> cmd;
			if(cin.eof()){return 0;}
			if(cmd == "f"){
				board.stopEnemy();
			}
			else if (cmd == "u"){
				cin >> cmd;
				if(cin.eof()){return 0;}
				board.useItem(cmd);
				cout << board << endl;  
			}
			else if(cmd == "q"){
				break;
			}
			else if(cmd == "a"){ //attacking
				cin >> cmd;
				bool result = board.attackEnemy(cmd);
				if(!result){
					cout <<setw(35)<< "YOU DIED :(" << endl;
					int score = board.getScore();
					if(characterType=="s"){
						score*=1.5;
					}	
					cout <<  setw(32) << "Score: ";
					cout << score << endl;
					break;
				}else
				cout << board << endl;  
			}else if(cmd == "r"){
				board.clearFloor();
				board.init();
				cout << "Please pick a race: ";
	  			cin >> cmd; 
	  			if(cmd == "s" || cmd == "g" || cmd == "v" || cmd == "t" || cmd == "d") {
	  				board.setPC(cmd);
	  				characterType = cmd;
	  			}
	  			else board.setPC("s");
			
				//board.init();
				//board.createChambers();
				cout << board << endl;
			}else{
				int result = board.movePC(cmd);
				if(result==1){
					cout << board << endl;
					continue;
				}
				else if(result == 0){
					cout <<setw(35)<< "YOU DIED :(" << endl;
				}else if (result == -1){
					cout << setw(35)<< "YOU WON :D" << endl;
				}
				int score = board.getScore();
				if(characterType=="s"){
					score*=1.5;
				}	
				cout <<  setw(32) << "Score: ";
				cout << score << endl;
				break;
			}
		}
	}
	catch(ios::failure &){}

}

	//catch	   

