#include "Subject.h"
#include "Observers.h"
#include "Subscription.h"

void Subject::attach(Observer *o){
	observers.emplace_back(o);
}

void Subject::notifyObservers(SubscriptionType t){
	for (auto c : observers){
			c->notify(*this);
	}
}

