#ifndef __INFO_H__
#define __INFO_H__
class Character;
class Item;
struct Info {
  int xPos, yPos;
  //change later
  char display;
  bool addedToChamber;
  Character *charOnTile = nullptr;
  Item *itemOnTile = nullptr;
};

#endif

