#include "DfaNodeManager.h"


DfaNodeManager::DfaNodeManager()
{
}


DfaNodeManager::~DfaNodeManager()
{
}

DfaNode* DfaNodeManager::newDfaNode()
{
	DfaNode* p = new DfaNode();
	NodePool.push_back(p);
	return p;
}

DfaNode* DfaNodeManager::addEdge(DfaNode* s, int c)
{
	DfaNode* p = newDfaNode();
	s->addEdge(c, p);
	return p;
}

DfaNode* DfaNodeManager::addEdge(DfaNode* s, DfaNode* e, int c)
{
	s->addEdge(c, e);
	return e;
}

void DfaNodeManager::showAll()
{
	for (auto it = NodePool.begin(); it != NodePool.end(); it++)
	{
		std::cout<< "------- U :" << (*it)->getIdx() << "final = " << (*it)->finalStatus << std::endl;
		for (int i = 0; i < 256; i++)
		{
			auto t = (*it)->next[i];
			if (t != nullptr) std::cout << t->getIdx() << " ";
		}
		std::cout << std::endl;
	}

}