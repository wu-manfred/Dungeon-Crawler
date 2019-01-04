#ifndef ACTIONDISPLAY_H
#define ACTIONDISPLAY_H
#include <string>
#include <sstream>
class Character;
class ActionDisplay{
	
	static std::string moveDirection;
	static std::string potionDescription;
	static std::string enemyDescription;
	static std::string damageTook;
	static std::string race;
	static std::string hpDescription;
	static std::string atkDescription;
	static std::string defDescription;
	static std::string goldDescription;
	static std::string special;
	static std::string floor;

public:
	ActionDisplay();
	~ActionDisplay();
	static void setMoveDescription(std::string direction);
	static void setRace (std::string raceType);
	static void setSpecial (std::string str);
	static void setAttack(int damage , std::string character = "PC");
	static void setPotion(std::string potion,bool use);
	static std::string setAction();
	static void setFloor(int level);
	static void setCharacterStats(Character &pc);
	static void clearAction();

};

#endif
