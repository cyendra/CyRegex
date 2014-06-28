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
	start = NodeManager::newStatus();
	end = NodeManager::newFinalStatus();
	NodeManager::addCharEdge(start, end, c);
}

void Group::Series(Group* g)
{
	NodeManager::addEdge(end, g->start);
}

void Group::ReadyToParallel()
{

}

void Group::Parallel(Group* g)
{

}

void Group::Repeat(Group* g)
{

}

void Group::Optional(Group* g)
{

}
