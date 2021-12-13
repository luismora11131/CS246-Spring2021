#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Integer.h"
using namespace std;

template<class T>
Node<T>::Node(){
  data = 0;
  next = NULL;
};

Integer::Integer(){
  sign = false;
  uint = new Node<int>;
  uint->data = 0;
  uint->next = NULL;
}

Integer::Integer(int i){
  //Check of the interger is possitive ot negative
  if(i < 0){
    sign = true;
    i *= -1;
  }
  else{
    sign = false;
  }
  //reference
  stringstream ss;
  ss << i;
  string s;
  ss >> s;
  //Create a replica called temp
  uint = new Node<int>;
  Node<int> * temp;
  temp = uint;
  //Sort it out starting by reverse
  for(int j = s.length()-1;j >= 0;j--){
    temp->data = s[j] - '0';
    temp->next = new Node<int>;
    temp = temp->next;
  }
  temp = NULL;
}

void Integer::operator = (string s){
  if(s.find_first_not_of("-0123456789") != string::npos){// check if parameter is in the proper format
    sign = false;
    uint = new Node<int>;
    uint->data = 0;
    uint ->next = NULL;
    return;
  }
  if(s[0] == '-'){
    sign = true;
    s.erase(s.begin());
  }
  else{
    sign = false;
  }
  //Integer I = *this;
  uint = new Node<int>;
  Node<int> * temp;
  temp = uint;
  for(int i = s.length()-1;i >= 0 ;i--){
    temp->data = s[i] - '0';
    temp->next = new Node<int>;
    temp = temp->next;
  }
  temp = NULL;
}

bool operator == (const Integer & first, const Integer & second){
  Node<int> *temp;
  //It will count its similarities
  temp = first.uint;
  int firstInt = 0;
  string s;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }
    stringstream ss(s);
    ss >> firstInt;
    if(first.sign == true)
    {
      firstInt *= -1;
    }
    s.clear();
    ss.clear();
    ss.str(string());
    //Here beging the second value
    temp = second.uint;
    int secondInt = 0;
    while(temp->next){
      s.insert(s.begin(), ((temp->data) + '0'));
      temp = temp->next;
    }
    ss << s;
    ss >> secondInt;
    if(second.sign == true){
      secondInt *= -1;
    }
    //return
    return (firstInt == secondInt);
}
//Same thing but != to the other operator
bool operator != (const Integer & first, const Integer & second){
    Node<int> *temp;
    temp = first.uint;
    int firstInt = 0;
    string s;
    while(temp->next){
      s.insert(s.begin(), ((temp->data) + '0'));
      temp = temp->next;
    }
    stringstream ss(s);
    ss >> firstInt;
    if(first.sign == true){
      firstInt *= -1;
    }
    s.clear();
    ss.clear();
    ss.str(string());
    temp = second.uint;
    int secondInt = 0;
    while(temp->next){
      s.insert(s.begin(), ((temp->data) + '0'));
      temp = temp->next;
    }
    ss << s;
    ss >> secondInt;
    if(second.sign == true){
      secondInt *= -1;
    }
    //return
    return (firstInt != secondInt);
}

Integer::Integer(double d){
  uint = new Node<int>;
  Node<int> * temp;
  temp = uint;
  //convert it into integer using static cast
  int i = static_cast<int> (d);
  //proceed to use the same process as the other operator
  if(i < 0){
    i *= -1;
    sign = true;
  }
  else{
    sign = false;
  }
  stringstream ss;
  ss << i;
  string s;
  ss >> s;
  //sort
  for(int j = s.length() - 1; j >= 0; j--){
    temp->data = s[j] - '0';
    temp->next = new Node<int>;
    temp = temp->next;
  }
  temp = NULL;
}

void Integer::operator = (int i){
  //same process
  if(i < 0){
    sign = true;
    i *= -1;
  }
  else{
    sign = false;
  }
  uint = new Node<int>;
  Node<int> * temp;
  temp = uint;
  stringstream ss;
  ss << i;
  string s;
  ss >> s;
  //sort
  for(int i = s.length() - 1; i >= 0 ; i--){
    temp->data = s[i] - '0';
    temp->next = new Node<int>;
    temp = temp->next;
  }
  temp = NULL;
}

bool operator > (const Integer & first, const Integer & second){
  Node<int> *temp;
  temp = first.uint;
  int firstInt = 0;
  string s;
  while(temp->next)
  {
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  stringstream ss(s);
  ss >> firstInt;
  if(first.sign == true){
    firstInt *= -1;
  }
  s.clear();
  ss.clear();
  ss.str(string());
  temp = second.uint;
  int secondInt = 0;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  ss << s;
  ss >> secondInt;
  if(second.sign == true){
    secondInt *= -1;
  }
  //return
  return (firstInt > secondInt);
}

bool operator >= (const Integer & first, const Integer & second)
{
  Node<int> *temp;
  temp = first.uint;
  int firstInt = 0;
  string s;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  stringstream ss(s);
  ss >> firstInt;
  if(first.sign == true){
    firstInt *= -1;
  }
  s.clear();
  ss.clear();
  ss.str(string());
  temp = second.uint;
  int secondInt = 0;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  ss << s;
  ss >> secondInt;
  if(second.sign == true){
    secondInt *= -1;
  }
  return (firstInt >= secondInt);
}
//Luis Mora
Integer::Integer(string s){
  if(s.find_first_not_of("-0123456789") != string::npos){ // check if parameter is in the proper format
    sign = false;
    uint = new Node<int>;
    uint->data = 0;
    uint ->next = NULL;
    return;
  }
  //checks the string for possible
  if(s[0] == '-'){
    sign = true;
    s.erase(s.begin());
  }
  else{
    sign = false;
  }
  uint = new Node<int>;
  Node<int> * temp;
  temp = uint;
  for(int i = s.length()-1;i >= 0;i--){
    temp->data = s[i] - '0';
    temp->next = new Node<int>;
    temp = temp->next;
  }
  temp = NULL;
}

void Integer::operator = (double d)
{
  int i = static_cast<int> (d);
  if(i < 0){
    sign = true;
    i *= -1;
  }
  else{
    sign = false;
  }
  uint = new Node<int>;
  Node<int> * temp;
  temp = uint;
  stringstream ss;
  ss << i;
  string s;
  ss >> s;
  for(int i = s.length()-1;i >= 0;i--){
    temp->data = s[i] - '0';
    temp->next = new Node<int>;
    temp = temp->next;
  }
  temp = NULL;
}

bool operator < (const Integer & first, const Integer & second){
  Node<int> *temp;
  temp = first.uint;
  int firstInt = 0;
  string s;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  stringstream ss(s);
  ss >> firstInt;
  if(first.sign == true){
    firstInt *= -1;
  }
  s.clear();
  ss.clear();
  ss.str(string());

  temp = second.uint;
  int secondInt = 0;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  ss << s;
  ss >> secondInt;
  if(second.sign == true){
    secondInt *= -1;
  }
    return (firstInt < secondInt);
}

bool operator <= (const Integer & first, const Integer & second){
  Node<int> *temp;
  temp = first.uint;
  int firstInt = 0;
  string s;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  stringstream ss(s);
  ss >> firstInt;
  if(first.sign == true){
    firstInt *= -1;
  }
  s.clear();
  ss.clear();
  ss.str(string());
  temp = second.uint;
  int secondInt = 0;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  ss << s;
  ss >> secondInt;
  if(second.sign == true){
    secondInt *= -1;
  }
  return (firstInt <= secondInt);
}

Integer operator + (const Integer & first, const Integer & second){
  Node<int> *temp;
  temp = first.uint;
  int firstInt = 0;
  string s;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  stringstream ss(s);
  ss >> firstInt;
  if(first.sign == true){
    firstInt *= -1;
  }
  s.clear();
  ss.clear();
  ss.str(string());
  temp = second.uint;
  int secondInt = 0;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }

  ss << s;
  ss >> secondInt;
  if(second.sign == true){
    secondInt *= -1;
  }
  int i3 = firstInt + secondInt;
  s.clear();
  ss.clear();
  ss.str(string());
  ss << i3;
  ss >> s;
  Integer I_3(s);
  if(i3 < 0){
    I_3.sign = true;
  }
  else{
    I_3.sign = false;
  }
  return I_3;
}

istream & operator >> (istream & input, Integer & I){
  string s;
  input >> s;
  if(s[0] == '-'){
    I.sign = true;
    s.erase(s.begin());
  }
  else{
    I.sign = false;
  }
  I.uint = new Node<int>;
  Node<int> *temp;
  temp = I.uint;
  for(int i = s.length()-1;i >= 0;i--){
    temp->data = s[i] - '0';
    temp->next = new Node<int>;
    temp = temp->next;
  }
  temp = NULL;
  return input;
}
// This is just a helper function
ostream & operator << (ostream & output, Integer & I){
  Node<int> *temp;
  temp = I.uint;
  string s;
  while(temp->next){
    s.insert(s.begin(), ((temp->data) + '0'));
    temp = temp->next;
  }
  if(I.sign == true){
    output << '-';
  }
  output << s << ' ';
  return output;
}
