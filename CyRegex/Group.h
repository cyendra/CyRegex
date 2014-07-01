#pragma once

#include "Manager.h"

class Group
{
public:
	Group(Manager* mana);
	Group(Manager* mana, Status* st, Status* ed);
	~Group();
	void MakeCharSet(CharSet c);
	void Series(Group* g);
	void ReadyToParallel();
	void Parallel(Group* g);
	void Repeat(Group* g);
	void Optional(Group* g);
	void SelfRepeat();
	void SelfOptional();
	Status* start;
	Status* end;
private:
	Manager* manager;
};

