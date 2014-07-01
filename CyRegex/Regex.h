#pragma once
#include "std.h"
#include "Group.h"
#include "Parser.h"
#include "Epsilon.h"
#include "std.h"
#include "NfaToDfa.h"
#include "DfaNodeManager.h"
#include "DFA.h"

class Regex
{
public:
	Regex();
	~Regex();
	void match(std::string s);
	bool go(std::string s);
	std::vector<std::pair<int, int>> ans;
	void showAns();
private:
	Parser p;
	Epsilon eps;
	DfaNodeManager mana;
	NfaToDfa ntd;
	Manager manager;
	DfaNode* root;
	DFA dfa;
	std::string str;
};

