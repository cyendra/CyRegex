#include "std.h"
#include "Group.h"
#include "Parser.h"
#include "Epsilon.h"
#include "std.h"
int main()
{
	//Parser p("(ab|cd)*");
	Parser p("abc(a|b|c)*cba");
	Group* g = p.Parse();
	Manager::showAll();
	Epsilon eps(g);
	eps.solve();
	//Manager::clearNotEffect(g->start);
	//Manager::clearEmpty();
	Manager::showAll();
	Manager::clearDel();
	Manager::showAll();
	getchar();
	
}