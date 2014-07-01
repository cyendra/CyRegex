#include "Epsilon.h"

Epsilon::Epsilon()
{

}

Epsilon::Epsilon(Group* p)
{
	ready(p);
}

void Epsilon::ready(Group* p)
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
	for (int i = 0; i < (int)ans.size(); i++)
	{
		//std::cout << ans[i].first->getIdx() << " " << ans[i].second->getIdx() << std::endl;
		Manager::AddCharEdge(ans[i].first, ans[i].second, vchr[i]);
	}
}

void Epsilon::findEffect()
{
	for (auto it = Manager::statusPool.begin(); it != Manager::statusPool.end(); it++)
	{
		if ((*it)->isEffect() || (*it)==g->start)
		{
			effectStatus.push_back(*it);
		}
		else
		{
			(*it)->del = true;
		}
	}
}

void Epsilon::getClose()
{
	ans.clear();
	vchr.clear();
	int n = Manager::statusPool.size();
	vis = new bool[n+1];
	//std::cout << n << " = n " << std::endl;
	for (auto it = effectStatus.begin(); it != effectStatus.end(); it++)
	{
		for (int i = 0; i <= n; i++) vis[i] = false;
		//std::cout << (*it)->getIdx() << " **********" << std::endl;
		//close(vis, *it, *it);
		dfs(*it, *it);
		//std::cout << std::endl;
		//break;

	}
	
	delete[] vis;
}

void Epsilon::close(bool vis[], Status* p, Status* s)
{
	//std::cout << s->getIdx() << "  " << std::endl;
	vis[s->getIdx()] = true;
	for (auto it = s->OutEdges.begin(); it != s->OutEdges.end(); it++)
	{
		if ((*it)->isEmpty())
		{
			if (!vis[(*it)->End->getIdx()]) close(vis, p, (*it)->End);
		}
	}
	//std::cout << std::endl;

	/*
	vis[s->getIdx()] = true;
	std::vector<Edge*>Es = s->OutEdges;

	for (auto it = Es.begin(); it != Es.end(); it++)
	{
		std::cout << "s = " << s->getIdx() << ": " << (*it)->End->getIdx() << " char = " << (*it)->MatchContent.getText() << std::endl;
		if ( !vis[(*it)->End->getIdx()] && (*it)->isEmpty())
		{
			close(vis, p, (*it)->End);
		}
		else if (s != p && !(*it)->isEmpty())
		{
			std::cout << "add " << p->getIdx() << " --> " << (*it)->End->getIdx() << std::endl;

			Manager::AddCharEdge(p, (*it)->End, (*it)->MatchContent);
		}
	}
	*/
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

void Epsilon::dfs(Status* p, Status* u)
{
	vis[u->getIdx()] = true;
	//std::cout << u->getIdx() << std::endl;
	for (auto it = u->OutEdges.begin(); it != u->OutEdges.end(); it++)
	{
		Status* v = (*it)->End;
		//std::cout << u->getIdx() << " --> " << v->getIdx() << std::endl;
		if ((*it)->isEmpty())
		{ 
			(*it)->del = true;
			if (!vis[(*it)->End->getIdx()]) dfs(p, v);
		}
		else
		{
			ans.push_back(std::make_pair(p, v));
			vchr.push_back((*it)->MatchContent);
		}
	}
}