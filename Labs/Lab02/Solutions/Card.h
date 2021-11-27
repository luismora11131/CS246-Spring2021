#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <sstream>

class Card
{
	private:
	std::string symbol;
	std::string suit;

	public:
	Card() : symbol(""), suit("") {}
	
	Card(const Card& obj)
	{
		symbol = obj.symbol;
		suit = obj.suit;
	}

	Card& operator=(const Card& rhs)
	{
		if(this != &rhs)
		{
			symbol = rhs.symbol;
			suit = rhs.suit;
		}
		return *this;
	}

	~Card() {}

	std::string GetSymbol() const 
	{
		return symbol;
	}

	std::string GetSuit() const 
	{
		return suit;
	}

	void SetSymbol(std::string value)
	{
		symbol = value;
	}

	void SetSuit(std::string value)
	{
		suit = value;
	}

	std::string ToString() const 
	{
		std::stringstream out;
		out << "[" << symbol << ":" << suit << "]";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Card& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
