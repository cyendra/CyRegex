#include "Group.h"


Group::Group()
{
	start = nullptr;
	end = nullptr;
}


Group::~Group()
{
}

Group::Group(Status* st, Status* ed)
{
	start = st;
	end = ed;
}

void Group::MakeCharSet(CharSet c)
{
	start = NodeManager::NewStatus();
	end = NodeManager::NewFinalStatus();
	NodeManager::AddCharEdge(start, end, c);
}

void Group::Series(Group* g)
{
	end->setFinalStatus(false);
	NodeManager::AddEdge(end, g->start);
}

void Group::ReadyToParallel()
{
	Status* L = NodeManager::NewStatus();
	Status* R = NodeManager::NewFinalStatus();
	end->setFinalStatus(false);
	NodeManager::AddEdge(L, start);
	NodeManager::AddEdge(end, R);
}

void Group::Parallel(Group* g)
{
	g->end->setFinalStatus(false);
	NodeManager::AddEdge(start, g->start);
	NodeManager::AddEdge(g->end, end);
}

void Group::Repeat(Group* g)
{
	g->end->setFinalStatus(false);
	NodeManager::AddEdge(end, g->start);
	NodeManager::AddEdge(g->end, end);
}

void Group::Optional(Group* g)
{
	end->setFinalStatus(false);
	NodeManager::AddEdge(end, g->start);
	NodeManager::AddEdge(g->start, g->end);
}
