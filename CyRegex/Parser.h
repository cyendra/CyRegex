#pragma once

#include "std.h"
#include "Group.h"

class Parser
{
public:
	Parser();
	Parser(std::string s);
	~Parser();
	void ready(std::string s);
	void setManager(Manager* mana);
	Group* Parse();
	void clearAll();
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
	Manager* manager;
};

