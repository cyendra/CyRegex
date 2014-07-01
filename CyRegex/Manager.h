#pragma once
#include "std.h"
#include "Node.h"

class Manager
{
public:
	Manager();
	~Manager();


	// 状态结点池
	std::vector<Status*> statusPool;

	// 边结点池
	std::vector<Edge*> edgePool;
	
	// 创建一个新的空状态
	Status* NewStatus();

	// 创建一个新的终结状态
	Status* NewFinalStatus();

	// 创建一个新的空边
	Edge* NewEmptyEdge();

	// 创建一个新的字符集边
	Edge* NewCharEdge(CharSet c);

	// 添加一条边E连接状态S到T 
	void AddEdge(Status* S, Status* T, Edge* E);

	// 添加字符集c使得状态S跳转到状态T
	void AddCharEdge(Status* S, Status* T, CharSet c);

	// 添加空边使得状态S跳转到状态T
	void AddEdge(Status* S, Status* T);
	
	// 清空NFA中所有的点与边
	void clearAll();

	// 显示整个图
	void showAll();

	// 删除空边
	void clearEmpty();

	// 删除状态
	void clearNotEffect(Status* s);

	// 清空删除的结点
	void clearDel();
};

