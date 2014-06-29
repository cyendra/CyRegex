#pragma once

#include "std.h"
#include "Group.h"

class Parser
{
public:
	Parser(std::string s);
	~Parser();
	Group* Parse();
private:
	std::string lex;
	bool move();
	CharSet look;
	int pos;
	Group* expr();
	Group* add();
	Group* factor();
	bool match(char c);
	Group* newGroup();
	std::vector<Group*> groupPool;
};

