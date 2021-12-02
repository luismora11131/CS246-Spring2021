#include <iostream>
#include <string>
#include "Node.h"

bool Monotonic(ds::dn::Node<int>* head)
{
	if(head == NULL)
	{
		return true;
	}

	for(ds::dn::Node<int>* t = head->next;t != NULL;t = t->next)
	{
		if(t->prev->data < t->data)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	return 0;
}
