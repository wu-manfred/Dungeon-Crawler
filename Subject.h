#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "Subscription.h"
class Observer;
class Info;

class Subject {
  std::vector<Observer*> observers;
public:
  void attach(Observer *o);
  void notifyObservers(SubscriptionType t);
  virtual Info getInfo() const = 0;
};

#endif
