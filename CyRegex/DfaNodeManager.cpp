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