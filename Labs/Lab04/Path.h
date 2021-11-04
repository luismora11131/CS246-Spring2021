#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using ulong = unsigned long;

namespace ds
{
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

		char& GetValue(int r,int c)
		{
			if(r < 0 || r >= 8 || c < 0 || c >= 8)
			{
				throw "Invalid Indices";
			}
			return grid[r*8+c];
		}

		bool& GetState(int r,int c)
		{
			if(r < 0 || r >= 8 || c < 0 || c >= 8)
			{
				throw "Invalid Indices";
			}
			return states[r*8+c];
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
			
			for(int i = 0;i < 8;i += 1)
			{
				out << "[";

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

	bool To2D(int i,int& r,int& c)
	{
		if(i >= 0 && i < 64)
		{
			r = i / 8;
			c = i % 8;
			return true;
		}
		return false;
	}

	bool To1D(int r,int c,int& i)
	{
		if(r >= 0 && r < 8 && c >= 0 && c < 8)
		{
			i = 8 * r + c;
			return true;
		}
		return false;
	}	
}

#endif

