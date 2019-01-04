#include "ActionDisplay.h"
#include <sstream>
#include <string>
#include <iomanip>
#include "Character.h"
using namespace std;

	string ActionDisplay:: moveDirection="";
	string ActionDisplay:: potionDescription="";
	string ActionDisplay:: enemyDescription="";
	string ActionDisplay:: damageTook="";
	string ActionDisplay:: race = "";
	string ActionDisplay:: hpDescription = "";
	string ActionDisplay:: atkDescription = "";
	string ActionDisplay:: defDescription = "";
	string ActionDisplay:: goldDescription = "";
	string ActionDisplay:: special = "";
	string ActionDisplay:: floor = "";

ActionDisplay::ActionDisplay(){
}

ActionDisplay::~ActionDisplay(){}

void ActionDisplay::setMoveDescription(string direction){
	moveDirection = "PC moves ";
	string displayDirection = "";
	if(direction=="no") displayDirection = "north";
	else if(direction=="so") displayDirection = "south";
	else if(direction=="ea") displayDirection = "east";
	else if(direction=="we") displayDirection = "west";
	else if(direction=="nw") displayDirection = "north west";
	else if(direction=="ne") displayDirection = "north east";
	else if(direction=="se") displayDirection = "south east";
	else if(direction=="so") displayDirection = "south west";
	else {
		moveDirection = "PC attemps to move";
	}
	moveDirection+=displayDirection;
}

void ActionDisplay::setPotion(string potion,bool use){
	if(!use)potionDescription = "sees " + potion;
	else potionDescription = "use " + potion;
}

void ActionDisplay::setSpecial (string str){
	special = str;
}

void ActionDisplay::setRace(string raceType){
	race= "Race: " + raceType;
}

void ActionDisplay::setFloor(int level){
	floor="Floor: " +to_string(level);
}

void ActionDisplay::setCharacterStats(Character &pc){
	hpDescription = "HP: "+to_string(pc.getHP());
	defDescription = "Def: " + to_string(pc.getDefense());
	atkDescription = "Atk: " + to_string(pc.getAttack());
	goldDescription = "Gold: " + to_string(pc.getGold());

}

void ActionDisplay::setAttack(int damage , string character){
	if(character=="@") character = "PC";
	damageTook += character;
	damageTook += " deals ";
	damageTook += to_string(damage);
	damageTook += " damage. ";
}
std::string ActionDisplay::setAction(){
	stringstream s{};
	string basicInfo = race + "  " + goldDescription;
	s << left << setw(71) << basicInfo<<floor<< endl;
	s << hpDescription << endl;
	s << atkDescription << endl;
	s << defDescription << endl;
	s << "Action: ";
	if(special !=""){
		s << special;
	}
	else if(moveDirection !=""){
		s << moveDirection;
		if(potionDescription != ""){
			s << " and " <<potionDescription ;
		}
			s << ". "; 
		
	}else if(potionDescription != ""){
		s << "PC "<< potionDescription << ". ";
	}

	s<<damageTook;
	s<<endl;
	return s.str();
}

void ActionDisplay::clearAction(){
	moveDirection = "";
	potionDescription = "";
	enemyDescription = "";

	hpDescription = "";
	atkDescription = "";
	defDescription = "";
	goldDescription = "";
	damageTook = "";
	special = "";
}



