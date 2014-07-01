#pragma once
#include "DfaNode.h"
#include "std.h"

class DFA
{
public:
	DFA();
	~DFA();
	void setRoot(DfaNode* rt);
	int go(std::string s, int pos = 0);
private:
	DfaNode* root;
	DfaNode* pt;
	bool next(int c);
};

