#pragma once

#include "std.h"
#include "Node.h"
#include "CharSet.h"

namespace NodeManager
{
	// 状态结点池
	std::vector<Status*> StatusPool;
	
	// 边结点池
	std::vector<Edge*> EdgePool;
	
	//-------------------------------------------------------------------------
	//		新建结点的 new 系列

	// 创建一个新的空状态
	Status* newStatus()
	{
		Status* p = new Status();
		StatusPool.push_back(p);
		return p;
	}

	// 创建一个新的终结状态
	Status* newFinalStatus()
	{
		Status* p = new Status(true);
		StatusPool.push_back(p);
		return p;
	}

	// 创建一个新的空边
	Edge* newEmptyEdge()
	{
		Edge* p = new Edge();
		EdgePool.push_back(p);
		return p;
	}

	// 创建一个新的字符集边
	Edge* newCharEdge(CharSet c)
	{
		Edge* p = new Edge(c);
		EdgePool.push_back(p);
		return p;
	}

	//-------------------------------------------------------------------------
	// 添加边

	// 添加一条边E连接状态S到T 
	void addEdge(Status* S, Status* T, Edge* E)
	{
		S->addOutEdge(E);
		T->addInEdge(E);
	}

	// 添加字符集c使得状态S跳转到状态T
	void addCharEdge(Status* S, Status* T, CharSet c)
	{
		Edge* E = newCharEdge(c);
		addEdge(S, T, E);
	}

	// 添加空边使得状态S跳转到状态T
	void addEdge(Status* S, Status* T)
	{
		Edge* E = newEmptyEdge();
		S->addOutEdge(E);
		T->addInEdge(E);
	}

	//-------------------------------------------------------------------------

	// 清空NFA中所有的点与边
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