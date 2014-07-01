#include "Group.h"


Group::Group(Manager* mana)
{
	start = nullptr;
	end = nullptr;
	manager = mana;
}


Group::~Group()
{
}

Group::Group(Manager* mana, Status* st, Status* ed)
{
	start = st;
	end = ed;
	manager = mana;
}

void Group::MakeCharSet(CharSet c)
{
	start = manager->NewStatus();
	end = manager->NewFinalStatus();
	manager->AddCharEdge(start, end, c);
}

void Group::Series(Group* g)
{
	end->setFinalStatus(false);
	manager->AddEdge(end, g->start);
	end = g->end;
}

void Group::ReadyToParallel()
{
	Status* L = manager->NewStatus();
	Status* R = manager->NewFinalStatus();
	end->setFinalStatus(false);
	manager->AddEdge(L, start);
	manager->AddEdge(end, R);
	start = L;
	end = R;
}

void Group::Parallel(Group* g)
{
	g->end->setFinalStatus(false);
	manager->AddEdge(start, g->start);
	manager->AddEdge(g->end, end);
}

void Group::Repeat(Group* g)
{
	g->end->setFinalStatus(false);
	manager->AddEdge(end, g->start);
	manager->AddEdge(g->end, end);
}

void Group::Optional(Group* g)
{
	end->setFinalStatus(false);
	manager->AddEdge(end, g->start);
	manager->AddEdge(g->start, g->end);
	end = g->end;
}

void Group::SelfRepeat()
{
	Status* p = manager->NewFinalStatus();
	end->setFinalStatus(false);
	manager->AddEdge(p, start);
	manager->AddEdge(end, p);
	start = p;
	end = p;
}

void Group::SelfOptional()
{
	manager->AddEdge(start, end);
}