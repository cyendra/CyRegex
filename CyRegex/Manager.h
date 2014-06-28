#pragma once

#include "std.h"
#include "Node.h"
#include "CharSet.h"

namespace NodePool
{
	std::vector<Status*> StatusPool;
	std::vector<Edge*> EdgePool;
	Status* newStatus()
	{
		Status* p = new Status();
		StatusPool.push_back(p);
	}
	Status* newFinalStatus()
	{
		Status* p = new Status(true);
		StatusPool.push_back(p);
	}
	Edge* newEmptyEdge()
	{
		Edge* p = new Edge();
		EdgePool.push_back(p);
	}
	Edge* newCharEdge(CharSet c)
	{
		Edge* p = new Edge(c);
		EdgePool.push_back(p);
	}
	void addEdge(Status* S, Status* T, Edge* E)
	{
		S->addOutEdge(E);
		T->addInEdge(E);
	}
	void addEdge(Status* S, Status* T)
	{
		Edge* E = newEmptyEdge();
		S->addOutEdge(E);
		T->addInEdge(E);
	}
}