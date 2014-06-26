#pragma once

#include "std.h"
#include "CharSet.h"
#include "Action.h"

class Edge;
class Status;

class Status
{
public:
	Status();
	void addInEdge(Edge* e);
	void addOutEdge(Edge* e);
	bool isFinalStatus();
	void setFinalStatus(bool b);
private:
	std::vector<Edge*> InEdges;
	std::vector<Edge*> OutEdges;
	bool FinalStatus;
};

class Edge
{
public:
	Edge();
	CharSet MatchContent;
	std::vector<Action> Actions;
	Status* Start;
	Status* End;
};

