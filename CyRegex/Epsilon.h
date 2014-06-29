#pragma once

#include "Group.h"

class Epsilon
{
public:
	Epsilon();
	~Epsilon();
	void solve();
private:
	std::vector<Status*> effectStatus;
	void findEffect();
	Group* g;
	void getClose();
	void close(Status* p, Status* s);
};

