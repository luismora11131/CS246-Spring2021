#ifndef LAB01AS_H
#define LAB01AS_H

#include <iostream>

class Point3D
{
	public:
	int x;
	int y;
	int z;

	Point3D() 
	{
		x = 1;
		y = 1;
		z = 1;
	}

	void Output() const
	{
		std::cout << "(" << x << "," << y << "," << z << ")";
	}
};

#endif
