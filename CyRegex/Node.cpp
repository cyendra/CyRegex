#include "Node.h";

Status::Status()
{
	FinalStatus = false;
}
Status::Status(bool fin)
{
	FinalStatus = fin;
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
}

Edge::Edge(CharSet c)
{
	Start = nullptr;
	End = nullptr;
	MatchContent = c;
}
