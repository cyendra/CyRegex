#include "Group.h"


Group::Group()
{
}


Group::~Group()
{
}

Group::Group(Status* st, Status* ed)
{
	start = st;
	end = ed;
}