#pragma once

#include "std.h"
#include "CharSet.h"
#include "Action.h"

class Edge;
class Status;

class Status
{
	std::vector<Edge*> InEdges;
	std::vector<Edge*> OutEdges;
	bool FinalStatus;
};

class Edge
{
	CharSet chr;
	std::vector<Action> Actions;
	Status* Start;
	Status* End;
};

