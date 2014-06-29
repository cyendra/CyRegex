#include "std.h"
#include "Group.h"
#include "Parser.h"

int main()
{
	Parser p("((aa|bb)|((ab|ba)(aa|bb)*(ab|ba)))*");
	p.Parse();
	Manager::showAll();

	getchar();
	
}