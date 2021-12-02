#include <iostream>
#include <string>
#include "Queue.h"
#include "Path.h"
using namespace std;
using namespace ds;

int main()
{
	Path p;

	p.GeneratePath();
	cout << "\n" << p << "\n";

	return 0;
}

