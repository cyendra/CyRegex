#pragma once
#include "std.h"
#include "Node.h"

class Manager
{
public:

	// ״̬����
	static std::vector<Status*> statusPool;

	// �߽���
	static std::vector<Edge*> edgePool;
	
	// ����һ���µĿ�״̬
	static Status* NewStatus();

	// ����һ���µ��ս�״̬
	static Status* NewFinalStatus();

	// ����һ���µĿձ�
	static Edge* NewEmptyEdge();

	// ����һ���µ��ַ�����
	static Edge* NewCharEdge(CharSet c);

	// ���һ����E����״̬S��T 
	static void AddEdge(Status* S, Status* T, Edge* E);

	// ����ַ���cʹ��״̬S��ת��״̬T
	static void AddCharEdge(Status* S, Status* T, CharSet c);

	// ��ӿձ�ʹ��״̬S��ת��״̬T
	static void AddEdge(Status* S, Status* T);
	
	// ���NFA�����еĵ����
	static void clearAll();

	// ��ʾ����ͼ
	static void showAll();

	// ɾ���ձ�
	static void clearEmpty();

	// ɾ��״̬
	static void clearNotEffect(Status* s);
};

