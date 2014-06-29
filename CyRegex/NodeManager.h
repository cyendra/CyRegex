#pragma once

#include "std.h"
#include "Node.h"
#include "CharSet.h"

namespace NodeManager
{
	// ״̬����
	std::vector<Status*> statusPool;
	
	// �߽���
	std::vector<Edge*> edgePool;
	
	//-------------------------------------------------------------------------
	//		�½����� new ϵ��

	// ����һ���µĿ�״̬
	Status* NewStatus()
	{
		Status* p = new Status();
		statusPool.push_back(p);
		return p;
	}

	// ����һ���µ��ս�״̬
	Status* NewFinalStatus()
	{
		Status* p = new Status(true);
		statusPool.push_back(p);
		return p;
	}

	// ����һ���µĿձ�
	Edge* NewEmptyEdge()
	{
		Edge* p = new Edge();
		edgePool.push_back(p);
		return p;
	}

	// ����һ���µ��ַ�����
	Edge* NewCharEdge(CharSet c)
	{
		Edge* p = new Edge(c);
		edgePool.push_back(p);
		return p;
	}

	//-------------------------------------------------------------------------
	// ��ӱ�

	// ���һ����E����״̬S��T 
	void AddEdge(Status* S, Status* T, Edge* E)
	{
		S->addOutEdge(E);
		T->addInEdge(E);
	}

	// ����ַ���cʹ��״̬S��ת��״̬T
	void AddCharEdge(Status* S, Status* T, CharSet c)
	{
		Edge* E = NewCharEdge(c);
		AddEdge(S, T, E);
	}

	// ��ӿձ�ʹ��״̬S��ת��״̬T
	void AddEdge(Status* S, Status* T)
	{
		Edge* E = NewEmptyEdge();
		S->addOutEdge(E);
		T->addInEdge(E);
	}

	//-------------------------------------------------------------------------

	// ���NFA�����еĵ����
	void clearAll()
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
	void showAll()
	{
		std::cout << "***** Status *****" << std::endl;
		for (auto it = statusPool.begin(); it != statusPool.end(); it++)
		{
			std::cout << (*it)->getIdx() << " " << (*it)->isFinalStatus() << std::endl;
		}
		std::cout << "***** Edge *****" << std::endl;
		for (auto it = edgePool.begin(); it != edgePool.end(); it++)
		{
			std::cout << (*it)->getIdx() << " Start:" << (*it)->Start->getIdx()<< " End:" << (*it)->End->getIdx() << std::endl;
		}
	}
}