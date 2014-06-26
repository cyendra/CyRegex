#include "CharSet.h"

CharSet::CharSet()
{
	chr = 0;
}

CharSet::CharSet(char c)
{
	chr = c;
}


CharSet::~CharSet()
{
}

bool CharSet::inSet(char c)
{
	return c == chr;
}

void CharSet::setChar(char c)
{
	chr = c;
}