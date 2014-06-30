#pragma once

#include "CharSet.h"
#include "Action.h"

class Edge;
class Status;

class Status
{
public:
	Status();
	Status(bool fin);
	~Status();
	void addInEdge(Edge* e);
	void addOutEdge(Edge* e);
	bool isFinalStatus();
	void setFinalStatus(bool b);
	static int getStatusNumber();
	int getIdx();
	bool isEffect();
	std::vector<Edge*> InEdges;
	std::vector<Edge*> OutEdges;
	bool effect;
	void clearNullEdge();
	bool del;
private:
	static int StatusNumber;
	int idx;
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
	static int getEdgeNumber();
	int getIdx();
	bool isEmpty();
	bool del;
private:
	int idx;
	static int EdgeNumber;
};

