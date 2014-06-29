#include "Epsilon.h"


Epsilon::Epsilon()
{
}


Epsilon::~Epsilon()
{
}

void Epsilon::solve()
{
	findEffect();
	getClose();
}

void Epsilon::findEffect()
{
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
			(*it)->Start = p;
		}
	}
}