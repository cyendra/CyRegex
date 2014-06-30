#include "Node.h"

Status::Status()
{
	effect = false;
	FinalStatus = false;
	idx = ++StatusNumber;
	del = false;
}
Status::Status(bool fin)
{
	effect = false;
	FinalStatus = fin;
	idx = ++StatusNumber;
	del = false;
}

Status::~Status()
{
	for (auto it = InEdges.begin(); it != InEdges.end(); it++)
	{
		(*it)->End = nullptr;
		(*it)->del = true;
	}
	for (auto it = OutEdges.begin(); it != OutEdges.end(); it++)
	{
		(*it)->Start = nullptr;
		(*it)->del = true;
	}
}

void Status::addInEdge(Edge* e)
{
	e->End = this;
	InEdges.push_back(e);
}

void  Status::addOutEdge(Edge* e)
{
	e->Start = this;
	OutEdges.push_back(e);
}

bool Status::isFinalStatus()
{
	return FinalStatus;
}

void Status::setFinalStatus(bool b)
{
	FinalStatus = b;
}

Edge::Edge()
{
	Start = nullptr;
	End = nullptr;
	idx = ++EdgeNumber;
	del = false;
}

Edge::Edge(CharSet c)
{
	Start = nullptr;
	End = nullptr;
	MatchContent = c;
	idx = ++EdgeNumber;
	del = false;
}

int Status::StatusNumber = 0;
int Edge::EdgeNumber = 0;

int Status::getStatusNumber()
{
	return StatusNumber;
}

int Edge::getEdgeNumber()
{
	return EdgeNumber;
}

int Status::getIdx()
{
	return idx;
}

int Edge::getIdx()
{
	return idx;
}

bool Status::isEffect()
{
	for (auto it = InEdges.begin(); it != InEdges.end(); it++)
	{
		if ((*it)->isEmpty() == false)
		{
			return effect = true;
		}
	}
	return effect = false;
}

bool Edge::isEmpty()
{
	return MatchContent.isEmpty();
}

void Status::clearNullEdge()
{
	std::vector<Edge*> v;
	for (int i = 0; i < (int)InEdges.size(); i++)
	{
		if (!InEdges[i]->del && InEdges[i]->Start != nullptr) v.push_back(InEdges[i]);
	}
	InEdges = v;
	v.clear();
	for (int i = 0; i < (int)OutEdges.size(); i++)
	{
		if (!OutEdges[i]->del && OutEdges[i]->End != nullptr) v.push_back(OutEdges[i]);
	}
	OutEdges = v;
}
