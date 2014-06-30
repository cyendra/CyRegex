#pragma once

#include "Group.h"

class Epsilon
{
public:
	Epsilon(Group* p);
	~Epsilon();
	void solve();
	std::vector<Status*> effectStatus;
private:
	void findEffect();
	Group* g;
	void getClose();
	void close(bool vis[], Status* p, Status* s);
	void getEnd(Status* s);
	std::vector<std::pair<Status*, Status*>> ans;
	std::vector<CharSet> vchr;
	void dfs(Status* p, Status* u);
	bool* vis;
};

