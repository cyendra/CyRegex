#include "Node.h"

Status::Status()
{
	FinalStatus = false;
	idx = ++StatusNumber;
}
Status::Status(bool fin)
{
	FinalStatus = fin;
	idx = ++StatusNumber;
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
}

Edge::Edge(CharSet c)
{
	Start = nullptr;
	End = nullptr;
	MatchContent = c;
	idx = ++EdgeNumber;
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
