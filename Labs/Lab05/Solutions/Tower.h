#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <string>
#include <sstream>

class Tower
{
	private:
	int size;
	char tower[4];

	public:
	Tower() : size(0) {}

	Tower(const Tower& obj)
	{
		size = obj.size;

		for(int i = 0;i < size;i += 1)
		{
			tower[i] = obj.tower[i];
		}
	}

	Tower& operator=(const Tower& rhs)
	{
		if(this != &rhs)
		{
			size = rhs.size;

			for(int i = 0;i < size;i += 1)
			{
				tower[i] = rhs.tower[i];
			}
		}
		return *this;
	}

	~Tower() {}

	bool Push(char value)
	{
		if(size < 4)
		{
			if(size == 0 || value < tower[size-1])
			{
				tower[size] = value;
				size += 1;
				return true;
			}
		}
		return false;
	}

	void Pop() 
	{
		if(size > 0) 
		{
			size -= 1;
		}
	}

	char Top() const 
	{
		if(size == 0)
		{
			throw "empty tower";
		}
		return tower[size-1];
	}

	bool IsEmpty() const
	{
		return (size == 0);
	}

	bool IsFull() const 
	{
		return (size == 4);
	}

	void MakeEmpty()
	{
		size = 0;
	}

	std::string ToString() const
	{
		std::stringstream out;

		out << "[";
		for(int i = 3;i >= 0;i -= 1)
		{
			if(i < size)
			{
				out << tower[i];
			}
			else 
			{
				out << " ";
			}

			if(i != 0)
			{
				out << "|";
			}
		}
		out << "]";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Tower& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
