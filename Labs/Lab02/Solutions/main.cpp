#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main()
{
	string symbols[4] = {"1","1","wild","reverse"};
	string suits[4] = {"red","red","black","green"};
	Card a;
	UnoDeck d;
	
	for(int i = 0;i < 4;i += 1)
	{
		a.SetSymbol(symbols[i]);
		a.SetSuit(suits[i]);
		d.Load(a);
	}
	cout << d << "\n";
	d.Shuffle();
	cout << d << "\n";
	a = d.Draw();
	cout << a << "\n" << d << "\n";

	return 0;
}
