#include "std.h"
#include "Group.h"


int main()
{
	Group* p[100];
	p[0] = new Group();
	p[0]->MakeCharSet('a');
	p[1] = new Group();
	p[1]->MakeCharSet('a');
	p[0]->Series(p[1]);

	p[2] = new Group();
	p[2]->MakeCharSet('b');
	p[3] = new Group();
	p[3]->MakeCharSet('b');
	p[2]->Series(p[3]);
	
	p[0]->ReadyToParallel();
	p[0]->Parallel(p[2]);

	Manager::showAll();

	getchar();
	
}