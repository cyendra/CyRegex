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
	ans.clear();
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
	root = ntd.root;
	dfa.setRoot(root);
}

bool Regex::go(std::string s)
{
	str = s;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		int R = dfa.go(s, i);
		if (R != -1)
		{
			ans.push_back(std::make_pair(i, R));
		}
	}
	if (ans.size() > 0) return true;
	return false;
}

void Regex::showAns()
{
	for (int i = 0; i < (int)ans.size(); i++)
	{
		std::cout << str.substr(ans[i].first, ans[i].second - ans[i].first + 1) << std::endl;
	}
}