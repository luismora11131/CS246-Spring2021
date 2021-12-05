#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>


namespace ds
{
	class Position
	{
		private:
		int x;
		int y;

		public:
		Position() : Position(0,0) {}

		Position(int x,int y) : x(x), y(y) 
		{
			if(this->x < 0 || this->x > 7 || this->y < 0 || this->y > 7)
			{
				this->x = 0;
				this->y = 0;
			}
		}

		Position(const Position& obj) 
		{
			x = obj.x;
			y = obj.y;
		}

		Position& operator=(const Position& rhs)
		{
			if(this != &rhs)
			{
				x = rhs.x;
				y = rhs.y;
			}
			return *this;
		}

		~Position() {}

		int GetX() const 
		{
			return x;
		}

		int GetY() const
		{
			return y;
		}

		void SetX(int value)
		{
			if(value >= 0 && value <= 7)
			{
				x = value;
			}
		}

		void SetY(int value)
		{
			if(value >= 0 && value <= 7)
			{
				y = value;
			}
		}

		void SetXY(int xvalue,int yvalue)
		{
			if(xvalue >= 0 && xvalue <= 7 && yvalue >= 0 && yvalue <= 7)
			{
				x = xvalue;
				y = yvalue;
			}
		}

		bool MoveN() 
		{
			if(x > 0)
			{
				x -= 1;
				return true;
			}
			return false;
		}

		bool MoveS() 
		{
			if(x < 7)
			{
				x += 1;
				return true;
			}
			return false;
		}

		bool MoveW() 
		{
			if(y > 0) 
			{
				y -= 1;
				return true;
			}
			return false;
		}

		bool MoveE()
		{
			if(y < 7)
			{
				y += 1;
				return true;
			}
			return false;
		}

		bool MoveNW() 
		{
			if(x > 0 && y > 0) 
			{
				x -= 1;
				y -= 1;
				return true;
			}
			return false;
		}

		bool MoveNE() 
		{
			if(x > 0 && y < 7)
			{
				x -= 1;
				y += 1;
				return true;
			}
			return false;
		}

		bool MoveSW()
		{
			if(x < 7 && y > 0)
			{
				x += 1;
				y -= 1;
				return true;
			}
			return false;
		}

		bool MoveSE() 
		{
			if(x < 7 && y < 7)
			{
				x += 1;
				y += 1;
				return true;
			}
			return false;
		}

		friend bool operator==(const Position& lhs,const Position& rhs)
		{
			return (lhs.x == rhs.x && lhs.y == rhs.y);
		}

		friend bool operator!=(const Position& lhs,const Position& rhs)
		{
			return (lhs.x != rhs.x || lhs.y != rhs.y);
		}

		std::string ToString() const 
		{
			std::stringstream out;
			out << "(" << x << "," << y << ")";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Position& obj)
		{
			out << obj.ToString();
			return out;
		}

		friend std::istream& operator>>(std::istream& in,Position& obj)
		{
			int x, y;
			in >> x;
			in >> y;
			obj.SetXY(x,y);
			return in;
		}
	};

	class Path
	{
		private:
		char grid[64];
		bool states[64];
		bool flag;

		public:
		Path() 
		{
			srand(time(NULL));
			flag = true;

			for(int i = 0;i < 64;i += 1)
			{
				grid[i] = ' ';
				states[i] = false;
			}
		}

		Path(const Path& obj)
		{
			flag = obj.flag;

			for(int i = 0;i < 64;i += 1)
			{
				grid[i] = obj.grid[i];
				states[i] = states[i];
			}
		}

		Path& operator=(const Path& rhs)
		{
			if(this != &rhs)
			{
				flag = rhs.flag;

				for(int i = 0;i < 64;i += 1)
				{
					grid[i] = rhs.grid[i];
					states[i] = rhs.states[i];
				}
			}
			return *this;
		}

		~Path() {}

		char& GetValue(const Position& p)
		{
			return grid[p.GetX() * 8 + p.GetY()];
		}

		bool& GetState(const Position& p)
		{
			return states[p.GetX() * 8 + p.GetY()];
		}

		bool Toggle() 
		{
			flag = !flag;
			return flag;
		}

		void GeneratePath()
		{
			bool a;

			for(int i = 0;i < 64;i += 1)
			{
				a = ((rand() % 4) != 0);
				grid[i] = (a)?(' '):('+');
				states[i] = false;
			}	
		}	

		std::string ToString() const 
		{
			std::stringstream out;
			
			out << "   ";
			for(int i = 0;i < 8;i += 1)
			{
				out << " " << i << "  ";
			}
			out << "\n";

			for(int i = 0;i < 8;i += 1)
			{
				out << i << " [";

				for(int j = 0;j < 8;j += 1)
				{
					if(flag)
					{
						out << " " << grid[i*8+j] << " ";
					}
					else 
					{
						out << " " << ((states[i*8+j])?(1):(0)) << " ";
					}

					if(j + 1 < 8)
					{
						out << "|";
					}
				}
				out << "]\n";
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Path& obj)
		{
			out << obj.ToString();
			return out;
		}
	};	
}

#endif

