#include <iostream>
#include <string>
#include "Array.h"
#include "Stack.h"
#include "Node.h"
#include "Extra.h"
using namespace std;
using namespace ds;
//1
/*

int i=0   1
i<n       n+1
i+=       n
data[i] = "["   n
char j = 'O'  n
j<='9'  n+1
j+=1  n
data[i] += j    n
data[i]= "]"    n
T(n) = 8n+3
*/
//2
template<typename T>
void Insert(const T& item){
  int count =0;
  if(item!=-1){
    count+=1;
  }
  else if(size<data){
    count =1;
  }
}

//3
template<typename T>
void Sort(dn::Node<T>* data){
  node*temp=data;
  while(temp){
    node* min = temp;
    node* r = temp->next;
  }
  int x = temp-> data;
  temp->data = min->data;
  min->data=x;
  temo=temp->next;
}

//4
template<typename T>
bool IsValid(string str){
  int n = str.length();
  Stack<char> s;
  for(int i=0;i<n;i+=0){
    if(str[i]=='('){
      s.Push('(');
    }
    else if(str[i]==')'){
      if(s.IsEmpty()){
        return false;
      }
      s.Pop();
    }
    else{
      return false;
    }
  }
  return s.IsEmpty();
}

int main()
{
  string a = "()[(){()}]";
  IsValid(a);
	return 0;
}
