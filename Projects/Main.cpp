#include <iostream>
#include "Integer.h"

using namespace std;

int main()
{
    Integer I1(123);
    Integer I2(456.00);
    Integer I3("789");
    Integer I4;
    I4 = "123";
    Integer I5;
    I5 = 456;
    Integer I6;
    I6 = 789.00;
    Integer I7;
    cin >> I7;
    cout << (I1 == I2) << endl;
    cout << (I2 != I3) << endl;
    cout << (I3 > I4) << endl;
    cout << (I4 >= I5) << endl;
    cout << (I5 < I6) << endl;
    cout << (I5 <= I6) << endl;
    Integer I8;
    I8 = (I6 + I7);
    cout << I8 << endl;
    cout << I7 << endl;
    return 0;
}
