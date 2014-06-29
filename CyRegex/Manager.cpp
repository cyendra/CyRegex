#include "Manager.h"


// 状态结点池
std::vector<Status*> Manager::statusPool;

// 边结点池
std::vector<Edge*> Manager::edgePool;

//-------------------------------------------------------------------------
//		新建结点的 new 系列

// 创建一个新的空状态
Status* Manager::NewStatus()
{
	Status* p = new Status();
	statusPool.push_back(p);
	return p;
}

// 创建一个新的终结状态
Status* Manager::NewFinalStatus()
{
	Status* p = new Status(true);
	statusPool.push_back(p);
	return p;
}

// 创建一个新的空边
Edge* Manager::NewEmptyEdge()
{
	Edge* p = new Edge();
	edgePool.push_back(p);
	return p;
}

// 创建一个新的字符集边
Edge* Manager::NewCharEdge(CharSet c)
{
	Edge* p = new Edge(c);
	edgePool.push_back(p);
	return p;
}

//-------------------------------------------------------------------------
// 添加边

// 添加一条边E连接状态S到T 
void Manager::AddEdge(Status* S, Status* T, Edge* E)
{
	S->addOutEdge(E);
	T->addInEdge(E);
}

// 添加字符集c使得状态S跳转到状态T
void Manager::AddCharEdge(Status* S, Status* T, CharSet c)
{
	Edge* E = NewCharEdge(c);
	AddEdge(S, T, E);
}

// 添加空边使得状态S跳转到状态T
void Manager::AddEdge(Status* S, Status* T)
{
	Edge* E = NewEmptyEdge();
	S->addOutEdge(E);
	T->addInEdge(E);
}

//-------------------------------------------------------------------------

// 清空NFA中所有的点与边
void Manager::clearAll()
{
	for (auto it = statusPool.begin(); it != statusPool.end(); it++)
	{
		delete (*it);
	}
	statusPool.clear();
	for (auto it = edgePool.begin(); it != edgePool.end(); it++)
	{
		delete (*it);
	}
	edgePool.clear();
}

// 显示整个图
void Manager::showAll()
{
	std::cout << "***** Status *****" << std::endl;
	for (auto it = statusPool.begin(); it != statusPool.end(); it++)
	{
		std::cout << (*it)->getIdx() << " " << (*it)->isFinalStatus() << std::endl;
	}
	std::cout << "***** Edge *****" << std::endl;
	for (auto it = edgePool.begin(); it != edgePool.end(); it++)
	{
		std::cout << (*it)->getIdx() << " Char: " << (*it)->MatchContent.getText() << ", Start: " << (*it)->Start->getIdx() << ", End:" << (*it)->End->getIdx() << std::endl;
	}
}

void Manager::clearEmpty()
{
	std::vector<Edge*> pool;
	for (auto it = edgePool.begin(); it != edgePool.end(); it++)
	{
		if ((*it)->isEmpty())
		{
			Edge* e = (*it);
			delete e;
		}
		else
		{
			pool.push_back(*it);
		}
	}
	edgePool = pool;
}

void Manager::clearNotEffect(Status* s)
{
	std::vector<Status*> pool;
	for (auto it = statusPool.begin(); it != statusPool.end(); it++)
	{
		if ((*it)->isEffect())
		{
			pool.push_back(*it);
		}
		else if ((*it) == s)
		{
			pool.push_back(*it);
		}
		else
		{
			Status* s = (*it);
			delete s;
		}
	}
	statusPool = pool;
}
