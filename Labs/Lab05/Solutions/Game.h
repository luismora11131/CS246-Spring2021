#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <sstream>
#include "Tower.h"

class Game
{
	private:
	Tower towers[3];

	public:
	Game() 
	{
		for(char i = 'D';i >= 'A';i -= 1)
		{
			towers[0].Push(i);
		}
	}

	Game(const Game& obj)
	{
		for(int i = 0;i < 3;i += 1)
		{
			towers[i] = obj.towers[i];
		}
	}

	Game& operator=(const Game& rhs)
	{
		if(this != &rhs)
		{
			for(int i = 0;i < 3;i += 1)
			{
				towers[i] = rhs.towers[i];
			}
		}
		return *this;
	}

	~Game() {}

	bool Move(int From,int To)
	{
		if(To >= 0 && To <= 2 && From >= 0 && From <= 2 && To != From)
		{
			if(!towers[From].IsEmpty() && (towers[To].IsEmpty() || towers[From].Top() < towers[To].Top()))
			{
				towers[To].Push(towers[From].Top());
				towers[From].Pop();
				return true;
			}
		}
		return false;
	}

	void Reset() 
	{
		for(int i = 0;i < 3;i += 1)
		{
			towers[i].MakeEmpty();
		}

		for(char i = 'D';i >= 'A';i -= 1)
		{
			towers[0].Push(i);
		}
	}
	
	bool Success() const 
	{
		return (towers[0].IsEmpty() && towers[1].IsEmpty() && towers[2].IsFull());
	}

	std::string ToString() const 
	{
		std::stringstream out;

		for(int i = 0;i < 3;i += 1)
		{
			out << (i + 1) << ":" << towers[i] << "\n";
		}
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Game& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
