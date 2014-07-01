#include "std.h"
#include "Regex.h"

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
	Regex r;
	r.match(s);
	r.go("abccccaa--abcabccba");
	r.showAns();
	std::cout << "--------------" << std::endl;
	r.match("a|bc");
	r.go("rrrrrrrbcaaa");
	r.showAns();
	getchar();
	
}

/*





void ttt()
{
	std::string s = "abc(a|b|c)*cba";
	Parser p;
	Epsilon eps;
	DfaNodeManager mana;
	NfaToDfa ntd;
	Manager manager;
	p.setManager(&manager);
	p.ready(s);
	Group* g = p.Parse();

	eps.ready(g);
	eps.setManager(&manager);
	eps.solve();
	manager.clearDel();
	manager.showAll();


	ntd.setManager(&mana);
	ntd.ready(g->start);
	ntd.solve();
	mana.showAll();

}
*/