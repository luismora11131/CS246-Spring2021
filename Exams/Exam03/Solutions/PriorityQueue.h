#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template<class T>
	class PriorityQueue
	{
		private:
		dn::Node<T>* ends[3][2];
	
		public:
		PriorityQueue()
		{
			for(int i = 0;i < 3;i += 1)
			{
				ends[i][0] = ends[i][1] = NULL;
			}
		}

		PriorityQueue(const PriorityQueue<T>& obj)
		{
			for(int i = 0;i < 3;i += 1)
			{
				ends[i][0] = dn::Copy(obj.ends[i][0]);
				ends[i][1] = ends[i][0];

				if(ends[i][1] != NULL)
				{
					while(ends[i][1]->next != NULL)
					{
						ends[i][1] = ends[i][1]->next;
					}
				}
			}
		}

		PriorityQueue(std::initializer_list<T> lt)
		{
			for(int i = 0;i < 3;i += 1)
			{
				ends[i][0] = ends[i][1] = NULL;
			}

			for(const T& x : lt)
			{
				if(ends[2][1] == NULL)
				{	
					ends[2][1] = dn::Create(x);
				}
				else
				{
					ends[2][1]->next = dn::Create(x);
					ends[2][1]->next->prev = ends[2][1];
					ends[2][1] = ends[2][1]->next;
				}
			}
			ends[2][0] = ends[2][1];

			if(ends[2][0] != NULL)
			{
				while(ends[2][0]->prev != NULL)
				{
					ends[2][0] = ends[2][0]->prev;
				}
			}
		}

		PriorityQueue<T>& operator=(const PriorityQueue<T>& rhs)
		{
			if(this != &rhs)
			{
				for(int i = 0;i < 3;i += 1)
				{
					dn::Clear(ends[i][0]);
					ends[i][0] = dn::Copy(rhs.ends[i][0]);
					ends[i][1] = ends[i][0];
				
					if(ends[i][1] != NULL)
					{
						while(ends[i][1]->next != NULL)
						{
							ends[i][1] = ends[i][1]->next;
						}
					}
				}
			}
			return *this;
		}

		~PriorityQueue()
		{
			for(int i = 0;i < 3;i += 1)
			{
				dn::Clear(ends[i][0]);
				ends[i][0] = NULL;
				ends[i][1] = NULL;
			}
		} 

		void Enqueue(int priority,const T& value);
		void Dequeue();

		const T& Front() const 
		{	
			for(int i = 0;i < 3;i += 1)
			{
				if(ends[i][0] != NULL)
				{
					return ends[i][0]->data;
				}
			}
			throw "empty queue";
		}

		bool IsEmpty() const 
		{
			return (ends[0][0] == NULL && ends[1][0] == NULL && ends[2][0] == NULL);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";
			
			for(int i = 0;i < 3;i += 1)
			{
				if(ends[i][0] != NULL)
				{
					out << ends[i][0]->data;
					break;
				}
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const PriorityQueue<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

