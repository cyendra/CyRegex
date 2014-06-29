#pragma once
#include "std.h"
#include "Node.h"

class Manager
{
public:

	// 状态结点池
	static std::vector<Status*> statusPool;

	// 边结点池
	static std::vector<Edge*> edgePool;
	
	// 创建一个新的空状态
	static Status* NewStatus();

	// 创建一个新的终结状态
	static Status* NewFinalStatus();

	// 创建一个新的空边
	static Edge* NewEmptyEdge();

	// 创建一个新的字符集边
	static Edge* NewCharEdge(CharSet c);

	// 添加一条边E连接状态S到T 
	static void AddEdge(Status* S, Status* T, Edge* E);

	// 添加字符集c使得状态S跳转到状态T
	static void AddCharEdge(Status* S, Status* T, CharSet c);

	// 添加空边使得状态S跳转到状态T
	static void AddEdge(Status* S, Status* T);
	
	// 清空NFA中所有的点与边
	static void clearAll();

	// 显示整个图
	static void showAll();

	// 删除空边
	static void clearEmpty();

	// 删除状态
	static void clearNotEffect(Status* s);
};

