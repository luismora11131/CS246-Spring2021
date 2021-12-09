#include <iostream>
#include <string>
#include <cctype>
#include "Node.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "Array.h"
using namespace std;
using namespace ds;

/****************************************************************************************
 * Fundamentals
 ****************************************************************************************
 * a. first in last out
 *
 * b. hash value
 *
 * c. the keys of the key-value pairs must be distinct
 *
 * d. the number of the keys in a table divided by the number of slots of the table
 *
 * e. when a collision occurs it moves the key to the closest available slot.
 ***************************************************************************************/


/****************************************************************************************
 * Implementation
 ***************************************************************************************/
template <class T>
void PriorityQueue<T>::Enqueue(int priority,const T& value)
{
	if(priority >= 0 && priority <= 2)
	{
		if(ends[priority][1] == NULL)
		{
			ends[priority][1] = dn::Create(value);
			ends[priority][0] = ends[priority][1];
		}
		else
		{
			ends[priority][1]->next = dn::Create(value);
			ends[priority][1]->next->prev = ends[priority][1];
			ends[priority][1] = ends[priority][1]->next;
		}
	}
}

/****************************************************************************************
 * Problem Solving
 ***************************************************************************************/
char SecondMostLetter(string str)
{
	int m = -1, s = -1, i;
	Array<int> counts(26);

	for(i = 0;str[i] != '\0';i += 1)
	{
		if(isalpha(str[i]))
		{
			counts[tolower(str[i])-'a'] += 1;
		}	
	}
	
	for(i = 0;i < 26;i += 1)
	{
		if(counts[i] != 0)
		{
			if(m == -1)
			{
				m = i;
			}
			else if(counts[m] < counts[i])
			{
				s = m;
				m = i;
			}
			else if(s == -1 || counts[s] < counts[i])
			{
				s = i;
			}
		}
	}	
	
	if(s != -1)
	{
		return (char)('a' + s);
	}
	else if(m != -1)
	{
		return (char)('a' + m);
	}
	return '0';
}

string Evaluate(string str)
{
	Stack<char> s;
	string rstr = "";
	bool cap = false;

	for(int i = 0;str[i] != '\0';i += 1)
	{
		if(str[i] == '#')
		{
			s.Pop();
		}
		else if(str[i] == '$')
		{
			cap = !cap;
		}
		else
		{
			s.Push(((cap)?(toupper(str[i])):(str[i])));
		}	
	}

	while(!s.IsEmpty())
	{
		rstr = s.Top() + rstr;
		s.Pop();
	}
	return rstr;
}

int main()
{
	PriorityQueue<int> a = {2,4,6};
	string str;

	cout << a << "\n";
	a.Enqueue(1,5);
	cout << a << "\n\n";

	cout << "Enter a string: ";
	cin >> str;

	cout << "SecondMostLetter(" << str << ") = " << SecondMostLetter(str) << "\n";

	cout << "\nEnter a string: ";
	cin >> str;
	cout << "Evaluate(" << str << ") = " << Evaluate(str) << "\n";
	return 0;
}
