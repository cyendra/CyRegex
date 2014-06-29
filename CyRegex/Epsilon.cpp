#include "Epsilon.h"


Epsilon::Epsilon(Group* p)
{
	g = p;
}


Epsilon::~Epsilon()
{
}

void Epsilon::solve()
{
	getEnd(g->end);
	findEffect();
	getClose();
}

void Epsilon::findEffect()
{
	effectStatus.push_back(g->start);
	for (auto it = Manager::statusPool.begin(); it != Manager::statusPool.end(); it++)
	{
		if ((*it)->isEffect())
		{
			effectStatus.push_back(*it);
		}
	}
}

void Epsilon::getClose()
{
	for (auto it = effectStatus.begin(); it != effectStatus.end(); it++)
	{
		close(*it, *it);
	}
}

void Epsilon::close(Status* p, Status* s)
{
	for (auto it = s->OutEdges.begin(); it != s->OutEdges.end(); it++)
	{
		if ((*it)->isEmpty())
		{

			close(p, (*it)->End);
		}
		else if (s != p)
		{
			Manager::AddCharEdge(p, (*it)->End, (*it)->MatchContent);
		}
	}
}

void Epsilon::getEnd(Status* s)
{
	for (auto it = s->InEdges.begin(); it != s->InEdges.end(); it++)
	{
		if ((*it)->isEmpty())
		{
			getEnd((*it)->Start);
		}
	}
	s->setFinalStatus(true);
}