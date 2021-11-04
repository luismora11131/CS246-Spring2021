#ifndef NODE_H
#define NODE_H

namespace ds
{
	namespace sn 
	{
		template<class T>
		struct Node
		{
			T data;
			Node<T>* link;
		};
	
		template<class T>
		Node<T>* Create(const T& itm)
		{
			Node<T>* t = new Node<T>;
	
			t->data = itm;
			t->link = NULL;
			return t;
		}

		template<class T>
		Node<T>* Copy(Node<T>* rt)
		{
			if(rt == NULL)
			{
				return NULL;
			}
			Node<T>* hd = Create(rt->data);
			Node<T>* t = hd, *s = rt;

			while(s->link != NULL)
			{
				t->link = Create(s->link->data);
				s = s->link;
				t = t->link;
			}
			return hd;
		} 
		
		template<class T>
		void Clear(Node<T>*& rt)
		{
			Node<T>* t;
			
			while(rt != NULL)
			{
				t = rt;
				rt = rt->link;
				delete t;
				t = NULL;
			}
		}
	}
	
	namespace dn 
	{
		template<class T>
		struct Node
		{
			T data;
			Node<T>* prev;
			Node<T>* next;
		};
	
		template<class T>
		Node<T>* Create(const T& itm)
		{
			Node<T>* t = new Node<T>;
	
			t->data = itm;
			t->prev = NULL;
			t->next = NULL;
			return t;
		}

		template<class T>
		Node<T>* Copy(Node<T>* rt)
		{
			if(rt == NULL)
			{
				return NULL;
			}
			Node<T>* hd = Create(rt->data);
			Node<T>* t = hd, *s = rt;

			while(s->next != NULL)
			{
				t->next = Create(s->next->data);
				t->next->prev = t;
				s = s->next;
				t = t->next;
			}
			return hd;
		} 
		
		template<class T>
		void Clear(Node<T>*& rt)
		{
			Node<T>* t;
			
			while(rt != NULL)
			{
				t = rt;
				rt = rt->next;
				delete t;
				t = NULL;
			}
		}
	}
}

#endif

