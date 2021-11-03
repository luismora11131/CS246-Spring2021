#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <string>
#include <sstream>
#include "Array.h"

using ulong = unsigned long;

namespace ds
{
	template<class T>
	struct Item 
	{
		T value;
		int count;
	};

	template<class T>
	class Bag
	{
		private:
		Array<Item<T>> data;
		int size;
		
		public:
		Bag() : size(0) {}

		Bag(const Bag<T>& obj)
		{
			size = obj.size;
			data = obj.data;
		}

		Bag<T>& operator=(const Bag<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				data = rhs.data;
			}
			return *this;
		}

		~Bag() {}

		std::string ToString() const
		{
			std::stringstream out;
			out << "{";

			for(int i = 0;i < size;i += 1)
			{
				out << "(" << data[i].value << "," << data[i].count << ")";

				if((i + 1) < size)
				{
					out << ",";
				}
			}
			out << "}";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Bag<T>& obj)
		{
			out << obj.ToString();
			return out;
		}

		void Insert(const T& item);
		void Remove(const T& item);
	};

	template<typename T>
	void Swap(T& a,T& b)
	{
		T t = a;
		a = b;
		b = t;
	}	
}

#endif

