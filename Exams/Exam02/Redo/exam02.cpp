#include <iostream>
#include <string>
#include "Array.h"
#include "Extra.h"
using namespace std;
using namespace ds;

/******************************************************************************
 * define function below
 *****************************************************************************/

void Remove(const T& ítem){
if(OrderedSet.size>0){
for(int i=0;i<OrderedSet.size-1;i++){
int decr =0;
if(item==data[i]){
data[i]="";
decr++;
}
}
OrderedSet.size-=decr;
Array<T> temp[size];
int assign=0;
for(int j=0:j<OrderedSet.size-1;j++){
if(data[j]!=""){
temp[assign]=data[j];
assign+=1;
}
}
data=temp;
}
}



int main()
{
	OrderedSet<int> a = {5,3,1};
	return 0;
}
