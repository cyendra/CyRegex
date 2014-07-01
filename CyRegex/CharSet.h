#pragma once
#include "std.h"
class CharSet
{
public:
	CharSet();
	CharSet(char c);
	~CharSet();
	bool inSet(char c);
	bool isSp();
	bool isSp(char c);
	void setChar(char c);
	char getText();
	void removeSp();
	static CharSet EndOfFile;
	bool isEof();
	bool isEmpty();
	int getCharIdx();
private:
	char chr;
	bool sp;
	void checkSp();
};

