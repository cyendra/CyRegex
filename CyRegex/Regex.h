#pragma once
#include "std.h"
#include "Group.h"
#include "Parser.h"
#include "Epsilon.h"
#include "std.h"
#include "NfaToDfa.h"
#include "DfaNodeManager.h"
class Regex
{
public:
	Regex();
	~Regex();
	void match(std::string s);
private:
	Parser p;
	Epsilon eps;
	DfaNodeManager mana;
	NfaToDfa ntd;
	Manager manager;
};

