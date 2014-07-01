#pragma once

class DfaNode
{
public:
	DfaNode();
	~DfaNode();
	DfaNode* next[256];
	bool finalStatus;
	void addEdge(int c, DfaNode* d);
};

