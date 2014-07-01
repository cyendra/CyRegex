#include "NfaToDfa.h"

NfaToDfa::NfaToDfa()
{
	root = nullptr;
	manager = nullptr;
}

NfaToDfa::NfaToDfa(DfaNodeManager* mana)
{
	manager = mana;
	root = nullptr;
}

void NfaToDfa::setManager(DfaNodeManager* mana)
{
	manager = mana;
}

NfaToDfa::~NfaToDfa()
{
}

void NfaToDfa::ready(Status* s)
{
	if (manager == nullptr) return;
	std::set<Status*> set;
	set.insert(s);
	root = manager->newDfaNode();
	D.insert(std::make_pair(set, root));
	L.push(set);
}

void NfaToDfa::solve()
{
	if (manager == nullptr) return;
	while (!L.empty())
	{
		//std::cout << "---" << std::endl;
		std::set<Status*> set = L.front();
		L.pop();
		std::set<Status*> arr[256];
		DfaNode* fu = D.find(set)->second;
		//std::cout << " top id = " << fu->getIdx() << std::endl;
		for (auto it = set.begin(); it != set.end(); it++)
		{
			Status* p = (*it);
			//std::cout << "set have :" << p->getIdx() << std::endl;
			for (auto e = p->OutEdges.begin(); e != p->OutEdges.end(); e++)
			{
				Status* v = (*e)->End;

				int c = (*e)->MatchContent.getCharIdx();
				//std::cout << " to :" << v->getIdx() << "  c = " << c << std::endl;
				if (c >= 0 && c < 256)
				{
					arr[c].insert(v);	
				}
			}
		}
		for (int i = 0; i < 256; i++)
		{
			if (arr[i].size() > 0)
			{
				//std::cout << "find c = " << i << std::endl;
				auto pt = D.find(arr[i]);
				if (pt != D.end())
				{
					//std::cout << "find !" << std::endl;
					DfaNode* fv = pt->second;
					manager->addEdge(fu, fv, i);
					//std::cout << "add Edge " << fu->getIdx() << " ---> " << fv->getIdx() << " c = "<< i << std::endl;
				}
				else
				{
					//std::cout << "not find !" << std::endl;
					DfaNode* nd = manager->addEdge(fu, i);
					//std::cout << "add Edge " << fu->getIdx() << " ---> " << nd->getIdx() << " c = " << i << std::endl;
					L.push(arr[i]);
					D.insert(std::make_pair(arr[i], nd));
				}
			}
		}
	}
	for (auto it = D.begin(); it != D.end(); it++)
	{
		DfaNode* nd = (*it).second;
		for (auto p = (*it).first.begin(); p != (*it).first.end(); p++)
		{
			if ((*p)->isFinalStatus()) nd->finalStatus = true;
		}
	}
}

void NfaToDfa::clearAll()
{
	D.clear();
	while (!L.empty()) L.pop();
}