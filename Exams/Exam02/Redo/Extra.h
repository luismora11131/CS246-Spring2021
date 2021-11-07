#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <string>
#include <sstream>
#include "Array.h"

namespace ds
{
	template<class T>
	class OrderedSet
	{
		private:
		Array<T> data;
		int size;
		
		public:
		OrderedSet() : size(0) {}

		OrderedSet(std::initializer_list<T> lt)
		{
			data = Array<T>(lt.size());
			
			ulong n = lt.size();
			size = 0;

			for(const T& x : lt)
			{	
				data[size] = x;
				size += 1;
			}
		}

		OrderedSet(const OrderedSet<T>& obj)
		{
			size = obj.size;
			data = obj.data;
		}

		OrderedSet<T>& operator=(const OrderedSet<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				data = rhs.data;
			}
			return *this;
		}

		~OrderedSet() {}

		std::string ToString() const
		{
			std::stringstream out;
			out << "{";

			for(int i = 0;i < size;i += 1)
			{
				out << data[i];

				if((i + 1) < size)
				{
					out << ",";
				}
			}
			out << "}";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const OrderedSet<T>& obj)
		{
			out << obj.ToString();
			return out;
		}

		void Insert(const T& item);
		void Remove(const T& item);
	};
}

#endif

