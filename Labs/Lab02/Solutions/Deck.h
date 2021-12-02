#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "AbstractDeck.h"

struct Counts
{
	int colors[5];
};

class UnoDeck : public DeckInterface
{
	private:
	int size;
	Card deck[108];
	Counts counts[15];

	bool ValidCard(const Card& value,int& symbol,int& suit)
	{
		std::string symbols[15] = {"0","1","2","3","4","5","6","7","8","9","skip","reverse","draw 2","wild","wild draw"};
		std::string suits[5] = {"red","yellow","green","blue","black"};
		for(int i = 0;i < 15;i += 1)
		{
			if(value.GetSymbol() == symbols[i])
			{
				if(i < 12)
				{
					for(int j = 0;j < 4;j += 1)
					{
						if(value.GetSuit() == suits[j])
						{
							symbol = i;
							suit = j;
							return true;
						}
					}
					return false;
				}
				else 
				{
					symbol = i;
					suit = 4;
					return (value.GetSuit() == suits[4]);
				}
			}
		}
		return false;
	}

	bool Equal(const Card& a,const Card& b)
	{
		return (a.GetSymbol() == b.GetSymbol() && a.GetSuit() == b.GetSuit());
	}

	void Swap(Card& a,Card& b)
	{
		Card t = a;
		a = b;
		b = t;
	}

	public:
	UnoDeck() : size(0) 
	{
		srand(time(NULL));
		
		for(int i = 0;i < 15;i += 1)
		{
			for(int j = 0;j < 5;j += 1)
			{
				counts[i].colors[j] = 0;
			}
		}
	}

	UnoDeck(const UnoDeck& obj)
	{
		size = obj.size;

		for(int i = 0;i < size;i += 1)
		{
			deck[i] = obj.deck[i];
		}
	}

	UnoDeck& operator=(const UnoDeck& rhs)
	{
		if(this != &rhs)
		{
			size = rhs.size;

			for(int i = 0;i < size;i += 1)
			{
				deck[i] = rhs.deck[i];
			}
		}
		return *this;
	}

	~UnoDeck() {}

	virtual Card Draw()
	{
		if(size == 0)
		{
			throw "Empty Deck";
		}
		Card card = deck[0];
		size -= 1;

		for(int i = 0;i < size;i += 1)
		{
			deck[i] = deck[i+1];
		}
		return card;
	}

	virtual void Shuffle()
	{
		int n = size, m;

		for(int i = size - 1;i > 0;i -= 1)
		{
			m = rand() % n;
			n -= 1;
			Swap(deck[i],deck[m]);
		}
	}

	virtual bool Load(const Card& value)
	{
		int sm, su;
		if(ValidCard(value,sm,su) && size < 108)
		{
			int i = 0;

			while(i < size && !Equal(deck[i],value))
			{
				i += 1;
			}
			
			bool a = (i == size);
			bool b = (sm == 0 && su < 4 && counts[sm].colors[su] < 1);
			bool c = (sm >= 1 && sm <= 12 && su < 4 && counts[sm].colors[su] < 2);
			bool d = (sm > 12 && su == 4 && counts[sm].colors[su] < 4);

			if(a || b || c || d)
			{
				deck[size] = value;
				counts[sm].colors[su] += 1;
				size += 1;
				return true;
			}
			return false;
		}
		return false;
	}

	virtual bool IsEmpty() const 
	{
		return (size == 0);
	}

	virtual std::string ToString() const 
	{
		std::stringstream out;
		out << "[";

		for(int i = 0;i < size;i += 1)
		{
			out << deck[i];

			if(i + 1 < size)
			{
				out << ",";
			}
		}
		out << "]";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const UnoDeck& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
