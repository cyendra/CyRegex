#pragma once

#include "std.h"

class Node
{
public:
	enum Type
	{
		empty, charset, action
	};
	Node();
	Node(char c);
	~Node();
	Type getType();
	char getChar();
	int size();
	std::vector<Node*>::iterator begin();
	std::vector<Node*>::iterator end();
	void removeChild();
private:
	std::vector<Node*> next;
	Type type;
	char chr;
	int act;
};

