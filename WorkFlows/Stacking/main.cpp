#include <iostream>
#include <string>
#include "Stack.h"
#include "Node.h"
using namespace std;
void FILO(std::string word)
{
  ds::Stack<char> s;

  //Push all the characters to the stack
  for(int i = 0;word[i] != '\0';i += 1)
  {
    s.Push(word[i]);
  }

  std::cout << "\n";
  //Pop all the characters from the stack
  while(!s.IsEmpty())
  {
    std::cout << s.Top();
    s.Pop();
  }
  std::cout << "\n";
}

bool IsPattern(string word){
    
    if(word.length()==0){
    return true;
    }
    for(int i=0;i<word.length();i++){
        if(word[i]=='a' && word[i+1]=='a' && word[i+2]=='b'){
            return true;
        }
    }
    return false;
    
}
int main() 
{
    string first = "first";
    string second = "second";
    string third = "racecar";
    FILO(first);
    FILO(second);
    FILO(third);
    cout<<IsPattern("soft")<<endl;
    cout<<IsPattern("aabaabaa");

  return 0;
} 