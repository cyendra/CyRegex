#pragma once
#include "std.h"
#include "Manager.h"
#include "DfaNodeManager.h"

class NfaToDfa
{
public:
	NfaToDfa();
	NfaToDfa(DfaNodeManager* mana);
	~NfaToDfa();

	void setManager(DfaNodeManager* mana);

	void ready(Status* s);
	void solve();
	std::queue<std::set<Status*>> L;
	std::map<std::set<Status*>, DfaNode*> D;

	DfaNode* root;
	DfaNodeManager* manager;
};

