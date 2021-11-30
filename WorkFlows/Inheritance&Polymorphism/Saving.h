#ifndef SAVINGS_H
#define SAVINGS_H

#include <iostream>
#include <sstream>
#include <string>

namespace cw1
{
	class Savings : public Account 
	{
		public:
		Savings()  
		{
		}
        	Savings(double amt) : Account(amt)
        	{
        	}
		Savings(const Savings& obj) : Account(static_cast<const Account&>(obj)) {}

		Savings& operator=(const Savings& rhs)
		{
			if(this != &rhs)
			{
                		Account::operator=(static_cast<const Account&>(rhs));
			}
			return *this;
		}

		~Savings() {} 
        	bool Withdraw(double amt)
        	{
            		if(amt < GetBalance()) 
            		{
   				return Account::Withdraw(amt);
            		} 
            		return false;          
        	}

		std::string ToString() const 
		{
			std::stringstream out;
            		out << "Savings " << Account::ToString();
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Savings& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
