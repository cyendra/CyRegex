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
	Status(bool fin);
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
	Edge(CharSet c);
	CharSet MatchContent;
	std::vector<Action> Actions;
	Status* Start;
	Status* End;
};

