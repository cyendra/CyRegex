#include "Manager.h"


Manager::Manager()
{

}

Manager::~Manager()
{

}

//-------------------------------------------------------------------------
//		�½����� new ϵ��

// ����һ���µĿ�״̬
Status* Manager::NewStatus()
{
	Status* p = new Status();
	statusPool.push_back(p);
	return p;
}

// ����һ���µ��ս�״̬
Status* Manager::NewFinalStatus()
{
	Status* p = new Status(true);
	statusPool.push_back(p);
	return p;
}

// ����һ���µĿձ�
Edge* Manager::NewEmptyEdge()
{
	Edge* p = new Edge();
	edgePool.push_back(p);
	return p;
}

// ����һ���µ��ַ�����
Edge* Manager::NewCharEdge(CharSet c)
{
	Edge* p = new Edge(c);
	edgePool.push_back(p);
	return p;
}

//-------------------------------------------------------------------------
// ��ӱ�

// ���һ����E����״̬S��T 
void Manager::AddEdge(Status* S, Status* T, Edge* E)
{
	S->addOutEdge(E);
	T->addInEdge(E);
}

// ����ַ���cʹ��״̬S��ת��״̬T
void Manager::AddCharEdge(Status* S, Status* T, CharSet c)
{
	Edge* E = NewCharEdge(c);
	AddEdge(S, T, E);
}

// ��ӿձ�ʹ��״̬S��ת��״̬T
void Manager::AddEdge(Status* S, Status* T)
{
	Edge* E = NewEmptyEdge();
	S->addOutEdge(E);
	T->addInEdge(E);
}

//-------------------------------------------------------------------------

// ���NFA�����еĵ����
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

// ��ʾ����ͼ
void Manager::showAll()
{
	std::cout << "***** Status *****" << std::endl;
	for (auto it = statusPool.begin(); it != statusPool.end(); it++)
	{
		std::cout << (*it)->getIdx() << " " << (*it)->isFinalStatus() <<" del = " <<(*it)->del << std::endl;
		std::cout << "InEdge:" << std::endl;
		for (auto i = (*it)->InEdges.begin(); i != (*it)->InEdges.end(); i++)
		{
			std::cout << (*i)->Start->getIdx() << " " << (*i)->End->getIdx() << std::endl;
		}
		std::cout << "OutEdge:" << std::endl;
		for (auto i = (*it)->OutEdges.begin(); i != (*it)->OutEdges.end(); i++)
		{
			std::cout << (*i)->Start->getIdx() << " " << (*i)->End->getIdx() << std::endl;
		}
		std::cout << "-----------" << std::endl;
	}
	std::cout << "***** Edge *****" << std::endl;
	for (auto it = edgePool.begin(); it != edgePool.end(); it++)
	{
		std::cout << (*it)->getIdx() << " Char: " << (*it)->MatchContent.getText() << ", Start: " << (*it)->Start->getIdx() << ", End:" << (*it)->End->getIdx() << " del = " << (*it)->del << std::endl;
	}
}

void Manager::clearEmpty()
{
	std::vector<Edge*> pool;
	for (auto it = edgePool.begin(); it != edgePool.end(); it++)
	{
		if ((*it)->isEmpty() || ((*it)->Start == nullptr || (*it)->End == nullptr))
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

		if ((*it)->effect)
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
			(*it)->~Status();
			delete s;
		}
	}
	statusPool = pool;
}

void Manager::clearDel()
{
	std::vector<Status*> pool;
	for (auto it = statusPool.begin(); it != statusPool.end(); it++)
	{
		(*it)->clearNullEdge();
		if (!(*it)->del) pool.push_back(*it);
		else delete (*it);
	}
	statusPool = pool;

	std::vector<Edge*> vct;
	for (auto it = edgePool.begin(); it != edgePool.end(); it++)
	{
		if (!(*it)->del) vct.push_back(*it);
		else delete (*it);
	}
	edgePool = vct;
}