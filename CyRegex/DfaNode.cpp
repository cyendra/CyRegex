#include "DfaNode.h"


DfaNode::DfaNode()
{
	idx = ++NodeNumber;
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
	if (c>=0&&c<256) next[c] = d;
}

int DfaNode::NodeNumber = 0;

int DfaNode::getIdx()
{
	return idx;
}

void DfaNode::reset()
{
	NodeNumber = 0;
}