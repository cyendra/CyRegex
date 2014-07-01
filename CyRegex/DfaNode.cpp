#include "DfaNode.h"


DfaNode::DfaNode()
{
	finalStatus = false;
	for (int i = 0; i < 256; i++)
	{
		next[i] = nullptr;
	}
}


DfaNode::~DfaNode()
{
}

void DfaNode::addEdge(int c, DfaNode* d)
{
	if (c<256) next[c] = d;
}