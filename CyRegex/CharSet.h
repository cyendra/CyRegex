#pragma once
#include "std.h"
class CharSet
{
public:
	CharSet();
	CharSet(char c);
	~CharSet();
	bool inSet(char c);
	void setChar(char c);
	char getText();
private:
	char chr;
};

