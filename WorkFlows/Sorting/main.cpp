#include "Array.h"
#include "Sorting.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    Array int first;
    Array int second;
    Array int thrid;
    first = RandomValues(first);
    cout<<first<<endl;
    BubbleSort(first);
    cout<<second<<" "<<GetCount(first)<<endl;
    InsertionSort(third);
    cout<<second<<" "<<GetCount(second)<<endl;
    SelectionSort(third);
    cout<<third<<" "<<GetCount(third)<<endl;
}