#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "Cell.h"
#include "Subscription.h"
class Character;
class EmptyCell : public Cell{
	bool addedToChamber = true;
	const char display = ' ';
	public:
		EmptyCell(int xPos, int yPos);
		~EmptyCell()override;
		SubscriptionType subType() const override;
		void notify(Subject &whoNotified) override;
		Info getInfo() const override;
};
#endif
