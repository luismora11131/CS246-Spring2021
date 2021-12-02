#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <iostream>
#include <string>
#include <sstream>

class Scrollbar
{
	private:
	int length;
	int position;
	std::string ends;

	public:
	Scrollbar() : length(5), position(45) 
	{
		ends = "";

		for(int i = 0;i < 50;i += 1)
		{
			ends += "*";
		}
	}

	Scrollbar(const Scrollbar& obj)
	{
		length = obj.length;
		position = obj.position;
	}

	Scrollbar& operator=(const Scrollbar& rhs)
	{
		if(this != &rhs)
		{
			length = rhs.length;
			position = rhs.position;
		}
		return *this;
	}

	~Scrollbar() {}

	int GetLength() const
	{
		return length;
	}

	int GetPosition() const 
	{
		return position;
	}

	void SetLength(int value)
	{
		if(value > 0 && value <= 50)
		{
			length = value;
			position = 50 - length;
		}
	}

	void SetPosition(int value)
	{
		if(value >0 && value < 50 && value + length <= 50)
		{
			position = value;
		}
	}

	bool MoveUp()
	{
		if(position + length + 1 <= 50)
		{
			position += 1;
			return true;
		}
		return false;
	}

	bool MoveDown()
	{
		if(position > 0)
		{
			position -= 1;
			return true;
		}
		return false;
	}

	bool Drag(int value)
	{
		int n = position + length;
		if(value > -50 && value < 50 && (value + n) > 0 && (value + n) <= 50) 
		{
			position += value;
			return true;
		}
		return false;
	}

	std::string ToString() const 
	{
		std::stringstream out;
		out << " " << ends << "\n-";

		for(int i = 0;i < 50;i += 1)
		{
			if(i == position)
			{
				out << ((length == 1)?("|"):("["));
			}
			else if(i == position + length - 1)
			{
				out << "]";
			}
			else 
			{
				out << " ";
			}
		}
		out << "+\n " << ends << "\n";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Scrollbar& obj)
	{
		out << obj.ToString();
		return out;
	}		
};
#endif
