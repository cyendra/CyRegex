#pragma once
#include "std.h"
#include "Manager.h"

class NfaToDfa
{
public:
	NfaToDfa();
	~NfaToDfa();


	std::set<std::set<Status*>> D;
	std::queue<std::set<Status*>> L;
	//std::map < std::set<Status*>, > ;


};

