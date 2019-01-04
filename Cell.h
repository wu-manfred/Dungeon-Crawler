#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <utility>
#include "Subject.h"
#include "Observers.h"
#include "Subscription.h"
#include "Info.h"
#include "Character.h"
#include "Item.h"
#include "PC.h"

class Character;
class Enemy;
class Cell : public Subject, public Observer{
	protected:
	Character * charOnTile;
	Item * itemOnTile;
	int xPos, yPos;
	bool walkable;
	public:
	Cell(int xPos, int yPos);
	virtual ~Cell()=0;
	virtual SubscriptionType subType() const = 0;
	virtual void notify(Subject &whoNotified)=0;
	virtual void setDisplay(char newDisplay);
	void emptyCell();
	void deleteCell();
	bool moveTo(Character *pc);
	bool placeItem(Item * item);
	bool useItem(Character *&pc);
	int cellContents() const;
	virtual void flipAddedToChamber();
};

#endif
