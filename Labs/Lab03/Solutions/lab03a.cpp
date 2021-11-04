#include <iostream>
#include <string>
#include "Array.h"

/*Function Definitions Here*/
template <typename T>
void ArrayFill(Array<T>& data,const T& value)
{
	ulong n = data.Size();

	for(ulong i = 0;i < n;i += 1)
	{
		data[i] = value;
	}
}

template <typename T>
void SubArray(Array<T>& data,Array<T>& subdata,ulong a,ulong b)
{
	ulong n = data.Size();

	if(a >= 0 && a < n && b >= 0 && b < n)
	{
		ulong m = a + b, n = (a > b)?(a):(b);
		m -= n;
		subdata = Array<T>(n - m + 1);

		for(ulong i = m;i <= n;i += 1)
		{
			subdata[i] = data[i];
		}
	}
}

template <typename T>
ulong DelimitedSearch(Array<T>& data,const T& delimit,const T& target)
{
	ulong n = data.Size(), idx = 0;

	while(idx < n && data[idx] != delimit)
	{
		idx += 1;
	}

	if(idx == n)
	{
		return n;
	}

	for(ulong i = idx;i > 0;i -= 1)
	{
		if(data[i-1] == target)
		{
			return (i - 1);
		}
	}
	return n;
}

int main()
{
	return 0;
}
