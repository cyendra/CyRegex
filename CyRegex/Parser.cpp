#include "Parser.h"


Parser::Parser(std::string s)
{
	lex = s;
	pos = 0;
	move();
}


Parser::~Parser()
{
}

bool Parser::move()
{
	if (pos == (int)lex.length())
	{
		look = CharSet::EndOfFile;
		return false;
	}
	look = lex[pos++];
	return true;
}

Group* Parser::Parse()
{
	Group* g = expr();
	return g;
}

Group* Parser::expr()
{
	Group* g = add();
	if (look.isSp('|')) g->ReadyToParallel();
	while (look.isSp('|'))
	{
		move();
		Group* p = add();
		g->Parallel(p);
	}
	return g;
}

Group* Parser::add()
{
	Group* g = factor();
	while (!look.isSp()||look.isSp('('))
	{
		if (!move()) break;
		Group* p = factor();
		if (look.isSp('*')) 
		{
			g->Repeat(p);
			move();
		}
		else if (look.isSp('?'))
		{
			g->Optional(p);
			move();
		}
		else g->Series(p);
	}
	return g;
}

Group* Parser::factor()
{
	Group* g = nullptr;
	if (look.isSp('('))
	{
		move();
		g = expr();
		match(')');
		return g;
	}
	else if (!look.isSp())
	{
		g = newGroup();
		g->MakeCharSet(look);
	}
	throw std::exception("bad factor");
	
}


bool Parser::match(char c)
{
	if (look.isSp(c)) return move();
	throw std::exception("error");
}

Group* Parser::newGroup()
{
	Group* g = new Group();
	groupPool.push_back(g);
	return g;
}