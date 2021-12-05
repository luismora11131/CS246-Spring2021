#include <iostream>
#include <string>
#include "Queue.h"
#include "Path.h"
using namespace std;
using namespace ds;

void GetAdjacencies(Queue<Position>& q,const Position& p)
{
	Position cp = p;

	if(cp.MoveNW())
	{
		q.Enqueue(cp);
	}
	cp = p;

	if(cp.MoveNE())
	{
		q.Enqueue(cp);
	}
	cp = p;

	if(cp.MoveSW())
	{
		q.Enqueue(cp);
	}
	cp = p;

	if(cp.MoveSE())
	{
		q.Enqueue(cp);
	}
}

bool HasPath(Path& p,const Position& s,const Position& e)
{
	Queue<Position> q;
	q.Enqueue(s);
	Position cp;

	while(!q.IsEmpty())
	{
		cp = q.Peek();
		q.Dequeue();

		if(cp == e)
		{
			return true;
		}
		else if(cp == s || (p.GetState(cp) == false && p.GetValue(cp) == ' '))
		{
			GetAdjacencies(q,cp);
		}
		p.GetState(cp) = true;
	}
	return false;
}

int main()
{
	Path p;
	Position s, e;

	p.GeneratePath();
	cout << "\n" << p << "\n";

	cout << "Enter start position: ";
       	cin >> s;

	cout << "Enter end position: ";
	cin >> e;

	cout << boolalpha;
	cout << "HasPath(grid," << s << "," << e << ") = " << HasPath(p,s,e) << "\n";  	

	return 0;
}

