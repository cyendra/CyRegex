#include "CharSet.h"

CharSet::CharSet()
{
	chr = 0;
	checkSp();
}

CharSet::CharSet(char c)
{
	chr = c;
	checkSp();
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

char CharSet::getText()
{
	return chr;
}

void CharSet::checkSp()
{
	switch (chr)
	{
	case 0:
	case '|':
	case '(':
	case ')':
	case '{':
	case '}':
	case '[':
	case ']':
	case '+':
	case '*':
	case '.':
	case '-':
		sp = true;
		break;
	default:
		sp = false;
		break;
	}
}

void CharSet::removeSp()
{
	sp = false;
}

bool CharSet::isSp()
{
	return sp;
}

bool CharSet::isSp(char c)
{
	return sp && c == chr;
}

CharSet CharSet::EndOfFile(-1);

bool CharSet::isEof()
{
	return chr == -1;
}