#pragma once

#include "std.h"
#include "Node.h"
#include "CharSet.h"

namespace NodeManager
{
	// ״̬����
	std::vector<Status*> StatusPool;
	
	// �߽���
	std::vector<Edge*> EdgePool;
	
	//-------------------------------------------------------------------------
	//		�½����� new ϵ��

	// ����һ���µĿ�״̬
	Status* newStatus()
	{
		Status* p = new Status();
		StatusPool.push_back(p);
		return p;
	}

	// ����һ���µ��ս�״̬
	Status* newFinalStatus()
	{
		Status* p = new Status(true);
		StatusPool.push_back(p);
		return p;
	}

	// ����һ���µĿձ�
	Edge* newEmptyEdge()
	{
		Edge* p = new Edge();
		EdgePool.push_back(p);
		return p;
	}

	// ����һ���µ��ַ�����
	Edge* newCharEdge(CharSet c)
	{
		Edge* p = new Edge(c);
		EdgePool.push_back(p);
		return p;
	}

	//-------------------------------------------------------------------------
	// ��ӱ�

	// ���һ����E����״̬S��T 
	void addEdge(Status* S, Status* T, Edge* E)
	{
		S->addOutEdge(E);
		T->addInEdge(E);
	}

	// ����ַ���cʹ��״̬S��ת��״̬T
	void addCharEdge(Status* S, Status* T, CharSet c)
	{
		Edge* E = newCharEdge(c);
		addEdge(S, T, E);
	}

	// ��ӿձ�ʹ��״̬S��ת��״̬T
	void addEdge(Status* S, Status* T)
	{
		Edge* E = newEmptyEdge();
		S->addOutEdge(E);
		T->addInEdge(E);
	}

	//-------------------------------------------------------------------------

	// ���NFA�����еĵ����
	void clearAll()
	{
		for (auto it = StatusPool.begin(); it != StatusPool.end(); it++)
		{
			delete (*it);
		}
		StatusPool.clear();
		for (auto it = EdgePool.begin(); it != EdgePool.end(); it++)
		{
			delete (*it);
		}
		EdgePool.clear();
	}
}