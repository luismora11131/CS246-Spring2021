#ifndef CHECKING_H
#define CHECKING_H

#include <iostream>
#include <sstream>
#include <string>

namespace cw1
{
	class Checking : public Account 
	{
		public:
		Checking()  
		{
		}
		Checking(double amt) : Account(amt)
		{
		}

		Checking(const Checking& obj) : Account(static_cast<const Account&>(obj)) {}

		Checking& operator=(const Checking& rhs)
		{
			if(this != &rhs)
			{
				Account::operator=(static_cast<const Account&>(rhs));
			}
			return *this;
		}

		~Checking() {} 

		//Overridding ToString() method
		std::string ToString() const 
		{
			std::stringstream out;
			out << "Checking " << Account::ToString();
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Checking& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
