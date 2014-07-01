#include "DFA.h"


DFA::DFA()
{
}


DFA::~DFA()
{
}

void DFA::setRoot(DfaNode* rt)
{
	root = rt;
}

int DFA::go(std::string s, int pos)
{
	int ans = -1;
	pt = root;
	if (pt->finalStatus) ans = pos;
	while (pos < (int)s.length() && next(s[pos++]))
	{
		if (pt->finalStatus) ans = pos - 1;
	}
	//std::cout << std::endl;
	return ans;
}

bool DFA::next(int c)
{
	if (pt->next[c] != nullptr)
	{
		pt = pt->next[c];
		//std::cout << (char)c << " ";
		return true;
	}
	return false;
}