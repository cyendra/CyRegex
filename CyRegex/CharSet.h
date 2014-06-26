#pragma once
class CharSet
{
public:
	CharSet();
	CharSet(char c);
	~CharSet();
	bool inSet(char c);
	void setChar(char c);
private:
	char chr;
};

