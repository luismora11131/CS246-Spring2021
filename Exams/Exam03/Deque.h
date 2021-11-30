#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template<class T>
	class Deque
	{
		private:
		dn::Node<T>* front;
		dn::Node<T>* back;
	
		public:
		Deque() : front(NULL), back(NULL) {}

		Deque(const Deque<T>& obj)
		{
			front = dn::Copy(obj.front);
			back = front;

			if(back != NULL)
			{
				while(back->next != NULL)
				{
					back = back->next;
				}
			}
		}

		Deque<T>& operator=(const Deque<T>& rhs)
		{
			if(this != &rhs)
			{
				dn::Clear(front);
				front = dn::Copy(rhs.front);
				back = front;
				
				if(back != NULL)
				{
					while(back->next != NULL)
					{
						back = back->next;
					}
				}
			}
			return *this;
		}

		~Deque()
		{
			dn::Clear(front);
			front = NULL;
			back = NULL;
		} 

		void InsertToFront(const T& value);
		void InsertToBack(const T& value);
		void RemoveFromFront();
		void RemoveFromBack();

		const T& Front() const 
		{
			if(front == NULL)
			{
				throw "empty deque";
			}
			return front->data;
		}

		const T& Back() const
		{
			if(back == NULL)
			{
				throw "empty deque";
			}
			return back->data;
		}

		bool IsEmpty() const 
		{
			return (front == NULL);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			if(front != NULL)
			{
				out << front->data << ":" << back->data;
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Deque<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

