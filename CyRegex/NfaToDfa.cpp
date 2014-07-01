#include "NfaToDfa.h"


NfaToDfa::NfaToDfa(DfaNodeManager* mana)
{
	manager = mana;
	root = nullptr;
}


NfaToDfa::~NfaToDfa()
{
}

void NfaToDfa::ready(Status* s)
{
	std::set<Status*> set;
	set.insert(s);
	root = manager->newDfaNode();
	D.insert(std::make_pair(set, root));
	L.push(set);
}

void NfaToDfa::solve()
{
	while (!L.empty())
	{
		std::set<Status*> set = L.front();
		L.pop();
		std::set<Status*> arr[256];
		DfaNode* fu = D.find(set)->second;
		for (auto it = set.begin(); it != set.end(); it++)
		{
			Status* p = (*it);
			for (auto e = p->OutEdges.begin(); e != p->OutEdges.end(); e++)
			{
				Status* v = (*e)->End;
				int c = (*e)->MatchContent.getCharIdx();
				if (c >= 0 && c < 256)
				{
					if (arr[c].find(v) != arr[c].end())
					{
						arr[c].insert(v);
					}
				}
			}
		}
		for (int i = 0; i < 256; i++)
		{
			if (arr[i].size() > 0)
			{
				auto pt = D.find(arr[i]);
				if (pt != D.end())
				{
					DfaNode* fv = pt->second;
					manager->addEdge(fu, fv, i);
				}
				else
				{
					DfaNode* nd = manager->addEdge(fu, i);
					L.push(arr[i]);
					D.insert(std::make_pair(arr[i], nd));
				}
			}
		}
	}
}

