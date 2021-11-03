#include <iostream>
#include <string>
#include "Array.h"
#include "Stack.h"
#include "Node.h"
#include "Extra.h"
using namespace std;
using namespace ds;

/******************************************************************************
 * Runtime
 ******************************************************************************
 cost	| time
 1	| 1
 1	| n + 1
 1	| n
 1	| n
 1	| 11n
 1	| 10n
 1	| 10n
 1	| n
 1	| n
 -----------------
 T(n) = 36n + 2
******************************************************************************/

template<class T>
void Bag<T>::Insert(const T& item)
{
	if(size < data.Size())
	{
		int i = 0;

		while(i < size && item > data[i].value)
		{
			i += 1;
		}

		if(i < size && data[i].value == item)
		{
			data[i].count += 1;
		}
		else 
		{
			for(int j = size;j > i;j -= 1)
			{
				data[j] = data[j-1];
			}
			data[i].value = item;
			data[i].count = 1;
			size += 1;
		}
	}
}

template<class T>
void Sort(dn::Node<T>* data)
{
	if(data != NULL)
	{
		for(dn::Node<T>* i = data;i != NULL;i = i->next)
		{
			dn::Node<T>* m = i;

			for(dn::Node<T>* j = i->next;j != NULL;j = j->next)
			{
				if(m->data > j->data)
				{
					m = j;
				}
			}

			if(i != m)
			{
				Swap(i->data,m->data);
			}
		}
	}
}

bool IsValid(string str)
{
	Stack<char> s;

	for(int i = 0;str[i] != '\0';i += 1)
	{
		if(str[i] == '(' || str[i] == '[') 
		{
			s.Push(str[i]);
		}
		else if(str[i] == ')')
		{
			if(s.IsEmpty() || s.Top() != '(')
			{
				return false;
			}
			s.Pop();
		}
		else if(str[i] == ']')
		{
			if(s.IsEmpty() || s.Top() != '[')
			{
				return false;
			}
			s.Pop();
		}
		else
		{
			return false;
		}
	}
	return s.IsEmpty();
}

template<typename T>
void Print(dn::Node<T>* root)
{
	cout << "\n[";

	for(dn::Node<T>* t = root;t != NULL;t = t->next)
	{
		cout << t->data;

		if(t->next != NULL)
		{
			cout << ",";
		}
	}
	cout << "]\n";
}

int main()
{
	try
	{
	Bag<char> a;

	a.Insert('d');
	a.Insert('b');
	a.Insert('a');
	a.Insert('b');
	a.Insert('c');

	cout << "\n" << a << "\n";

	dn::Node<int>* r = dn::Create(3);
	r->next = dn::Create(2);
	r->next->prev = r;

	Print(r);
	Sort(r);
	Print(r);
	dn::Clear(r);

	cout << boolalpha;
	cout << "\n" << IsValid("[([])]") << " " << IsValid("[(])") << "\n";
	}
	catch(const char* e)
	{
		cerr << e << "\n";
	}
	return 0;
}
