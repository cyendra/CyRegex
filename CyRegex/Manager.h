#pragma once
#include "std.h"
#include "Node.h"

class Manager
{
public:
	Manager();
	~Manager();


	// ״̬����
	std::vector<Status*> statusPool;

	// �߽���
	std::vector<Edge*> edgePool;
	
	// ����һ���µĿ�״̬
	Status* NewStatus();

	// ����һ���µ��ս�״̬
	Status* NewFinalStatus();

	// ����һ���µĿձ�
	Edge* NewEmptyEdge();

	// ����һ���µ��ַ�����
	Edge* NewCharEdge(CharSet c);

	// ���һ����E����״̬S��T 
	void AddEdge(Status* S, Status* T, Edge* E);

	// ����ַ���cʹ��״̬S��ת��״̬T
	void AddCharEdge(Status* S, Status* T, CharSet c);

	// ��ӿձ�ʹ��״̬S��ת��״̬T
	void AddEdge(Status* S, Status* T);
	
	// ���NFA�����еĵ����
	void clearAll();

	// ��ʾ����ͼ
	void showAll();

	// ɾ���ձ�
	void clearEmpty();

	// ɾ��״̬
	void clearNotEffect(Status* s);

	// ���ɾ���Ľ��
	void clearDel();
};

