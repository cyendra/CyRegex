#include "std.h"
#include "Group.h"
#include "Parser.h"
#include "Epsilon.h"
#include "std.h"
#include "NfaToDfa.h"
#include "DfaNodeManager.h"

void test()
{
	std::set<int>st;
	st.insert(1);
	st.insert(1);
	st.insert(1);
	std::cout << st.size() << std::endl;

}

int main()
{

	std::string s = "abc(a|b|c)*cba";
	Parser p;
	Epsilon eps;
	DfaNodeManager mana;
	NfaToDfa ntd;

	p.ready(s);
	Group* g = p.Parse();
	
	eps.ready(g);
	eps.solve();
	Manager::clearDel();
	Manager::showAll();
	

	ntd.setManager(&mana);
	ntd.ready(g->start);
	ntd.solve();
	mana.showAll();

	getchar();
	
}