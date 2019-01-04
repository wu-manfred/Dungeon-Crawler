#ifndef PASSAGE_H
#define PASSAGE_H
#include "Cell.h"
class Character;

class Passage : public Cell{
	bool addedToChamber = true;
	const char display = '#';
	public:
		Passage(int xPos, int yPos);
		~Passage() override;
		SubscriptionType subType() const override;
		void notify(Subject &whoNotified) override;
		Info getInfo () const override;
};
#endif
		
	
