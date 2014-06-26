#include "Node.h"


Node::Node()
{
	type = empty;
}

Node::Node(char c)
{
	type = charset;
	chr = c;
}

Node::~Node()
{
	removeChild();
}

Node::Type Node::getType()
{

}

char Node::getChar()
{

}

int Node::size()
{

}

std::vector<Node*>::iterator Node::begin()
{

}

std::vector<Node*>::iterator Node::end()
{

}

void Node::removeChild()
{
	for (auto it = begin(); it != end(); it++)
	{
		(*it)->removeChild();
		delete (*it);
	}
	next.clear();
}
