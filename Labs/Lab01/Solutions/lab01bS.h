#ifndef LAB01AS_H
#define LAB01AS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Rectangle
{
	private:
	double width;
	double length;

	public:
	Rectangle() 
	{
		length = 1;
		width = 1;
	}

	Rectangle(const Rectangle& obj)
	{
		length = obj.length;
		width = obj.width;
	}

	Rectangle& operator=(const Rectangle& rhs)
	{
		if(this != &rhs)
		{
			length = rhs.length;
			width = rhs.width;
		}
		return *this;
	}

	~Rectangle() {}

	double GetLength() const 
	{
		return length;
	}

	double GetWidth() const 
	{
		return width;
	}

	void SetLength(double value)
	{
		if(value >= width)
		{
			length = value;
		}
	}

	void SetWidth(double value)
	{
		if(value > 0 && value <= length)
		{
			width = value;
		}
	}

	double Perimeter() const
	{
		return (2 * (length + width));
	}

	double Area() const
	{
		return (length * width);
	}

	std::string ToString() const 
	{
		std::stringstream out;

		out << std::fixed << std::setprecision(2);
		out << "[" << width << "," << length << "]";
		return out.str();
	}

};

#endif
