#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*1
int c=0 c1 1
double t=0 c2 1
int i=0 1
i<s n-1
i+=1 n
a[i]>0 c4 n
t+=a[i] c5 n
c+=1 c6 n
b[c-1]=t/c c7 n
a[i]<0 c8 n
t+=-1*a[i] c9 n
c+=1 c10 n
b[c-1]=t/c c11 n
return c c12 1

r(n) = 10n+3
*/

//2
int MaximunCount(int data[], int n){
  int max=0;
  for(int i=0;i<n;i++){
    if(data[i]>max){
      max=data[i];
    }
  }
  int solution=0;
  for(int i=0;i<n;i++){
    if(data[i]==max){
      solution+=1;
    }
  }
  return solution;
}
int main() {
  cout << "Hello World!\n";
}