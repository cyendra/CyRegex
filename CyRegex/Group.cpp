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
	start = Manager::NewStatus();
	end = Manager::NewFinalStatus();
	Manager::AddCharEdge(start, end, c);
}

void Group::Series(Group* g)
{
	end->setFinalStatus(false);
	Manager::AddEdge(end, g->start);
	end = g->end;
}

void Group::ReadyToParallel()
{
	Status* L = Manager::NewStatus();
	Status* R = Manager::NewFinalStatus();
	end->setFinalStatus(false);
	Manager::AddEdge(L, start);
	Manager::AddEdge(end, R);
	start = L;
	end = R;
}

void Group::Parallel(Group* g)
{
	g->end->setFinalStatus(false);
	Manager::AddEdge(start, g->start);
	Manager::AddEdge(g->end, end);
}

void Group::Repeat(Group* g)
{
	g->end->setFinalStatus(false);
	Manager::AddEdge(end, g->start);
	Manager::AddEdge(g->end, end);
}

void Group::Optional(Group* g)
{
	end->setFinalStatus(false);
	Manager::AddEdge(end, g->start);
	Manager::AddEdge(g->start, g->end);
	end = g->end;
}

void Group::SelfRepeat()
{
	Status* p = Manager::NewFinalStatus();
	end->setFinalStatus(false);
	Manager::AddEdge(p, start);
	Manager::AddEdge(end, p);
	start = p;
	end = p;
}

void Group::SelfOptional()
{
	Manager::AddEdge(start, end);
}