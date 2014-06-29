#include "std.h"
#include "Group.h"
#include "Parser.h"
#include "Epsilon.h"

int main()
{
	Parser p("(ab|cd)*");
	Group* g = p.Parse();
	Manager::showAll();
	Epsilon eps(g);
	Manager::clearNotEffect(g->start);
	Manager::clearEmpty();
	Manager::showAll();
	getchar();
	
}