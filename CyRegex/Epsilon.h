#pragma once

#include "Group.h"

class Epsilon
{
public:
	Epsilon(Group* p);
	~Epsilon();
	void solve();
private:
	std::vector<Status*> effectStatus;
	void findEffect();
	Group* g;
	void getClose();
	void close(Status* p, Status* s);
	void getEnd(Status* s);
};

