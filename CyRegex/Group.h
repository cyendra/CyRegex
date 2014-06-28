#pragma once
#include "std.h"
#include "Node.h"
class Group
{
public:
	Group();
	Group(Status* st, Status* ed);
	~Group();
	void add(Group* g);
	void readyToOr();
	void or(Group* g);
private:
	Status* start;
	Status* end;
};

