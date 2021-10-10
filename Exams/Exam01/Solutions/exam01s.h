#ifndef EXAM01_H
#define EXAM01_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Date
{
	private:
	string month;
	unsigned short day;
	unsigned int year;

	public:
	Date() : month("January"), day(1), year(1900) {}

	Date(const Date& obj)
	{
		month = obj.month;
		day = obj.day;
		year = obj.year;
	}

	Date& operator=(const Date& rhs)
	{
		if(this != &rhs)
		{
			month = rhs.month;
			day = rhs.day;
			year = rhs.year;
		}
		return *this;
	}

	~Date() {}

	string GetMonth() const {return month;}

	unsigned short GetDay() const {return day;}

	unsigned int GetYear() const {return year;}

	void SetMonth(string value) 
	{
		month = value;
	}

	void SetDay(unsigned short value)
	{
		day = value;
	}

	void SetYear(unsigned int value)
	{
		year = value;
	}

	string ToString() const 
	{
		stringstream out;

		out << month << " " << day << ", " << year;
		return out.str();
	}

	friend ostream& operator<<(ostream& out,const Date& obj)
	{
		out << obj.ToString();
		return out;
	}
};

class Timestamp : public Date
{
	private:
	unsigned int time;

	public:
	Timestamp() : time(0) {}

	Timestamp(const Timestamp& obj) : Date(static_cast<const Date&>(obj))
	{
		time = obj.time;
	}

	Timestamp& operator=(const Timestamp& rhs)
	{
		if(this != &rhs)
		{
			Date::operator=(static_cast<const Date&>(rhs));
			time = rhs.time;
		}
		return *this;
	}

	~Timestamp() {}

	unsigned int GetTime() const {return time;}

	void SetTime(unsigned int value)
	{
		time = value;
	}

	string ToString() const 
	{
		stringstream out;

		out << Date::ToString() << "; " << time << "s";
		return out.str();
	}

	friend ostream& operator<<(ostream& out,const Timestamp& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
