#pragma once
#include "DfaNode.h"
#include "std.h"

class DfaNodeManager
{
public:
	DfaNodeManager();
	~DfaNodeManager();
	DfaNode* newDfaNode();
	DfaNode* addEdge(DfaNode* s, int c);
	DfaNode* addEdge(DfaNode* s, DfaNode* e, int c);
	std::vector<DfaNode*> NodePool;
	void showAll();
	void clearAll();

};

