#pragma once

#include "Manager.h"

class Group
{
public:
	Group();
	Group(Status* st, Status* ed);
	~Group();
	void MakeCharSet(CharSet c);
	void Series(Group* g);
	void ReadyToParallel();
	void Parallel(Group* g);
	void Repeat(Group* g);
	void Optional(Group* g);
	Status* start;
	Status* end;
};

