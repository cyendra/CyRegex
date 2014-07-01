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
	std::vector<DfaNode*> NodePool;
};

