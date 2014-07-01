#include "Regex.h"


Regex::Regex()
{
	p.setManager(&manager);
	eps.setManager(&manager);
	ntd.setManager(&mana);
}


Regex::~Regex()
{
}

void Regex::match(std::string s)
{
	p.clearAll();
	eps.clearAll();
	mana.clearAll();
	ntd.clearAll();
	manager.clearAll();
	Edge::reset();
	Status::reset();
	DfaNode::reset();
	p.ready(s);
	Group* g = p.Parse();
	//manager.showAll();
	eps.ready(g);
	
	eps.solve();
	//manager.showAll();
	manager.clearDel();
	//manager.showAll();

	ntd.ready(g->start);
	ntd.solve();
	//mana.showAll();
}