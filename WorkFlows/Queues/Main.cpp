#include <iostream>
#include <string>
#include "Node.h"
#include "Queue.h"
using namespace std;

void FIFO(std::string word)
{
  ds::Queue<char> s;

  //Enqueue all the characters to the stack
  for(int i = 0;word[i] != '\0';i += 1)
  {
    s.Enqueue(word[i]);
  }

  std::cout << "\n";
  //Dequeue all the characters from the stack
  while(!s.IsEmpty())
  {
    std::cout << s.Peek();
    s.Dequeue();
  }
  std::cout << "\n";
}




void TernaryCounter(int n)
{
	if(n == 0)
	{
		cout << "0";
	}
	else if(n > 0)
	{
		std::string digits[2] = {"0","1"}, current;
		ds::sn::Queue<string> numbers;
		numbers.Enqueue(digits[1]);

		for(int i = 1;i <= n;i += 1)
		{
			current = numbers.Peek();
			numbers.Dequeue();
			numbers.Enqueue(current + digits[0]);
			numbers.Enqueue(current + digits[1]);
			cout << current << "\n";
		}
	}
}

int main()
{
	string first = "first";
	string second = "second";
	string third = "racecar";
	FIFO(first);
	FIFO(second);
	FIFO(third);
	int n;

	std::cout << "Enter a number: ";
	std::cin >> n;

	TernaryCounter(n);
	return 0;
}