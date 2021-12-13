#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
class Node{
  public:
  T data;
  Node<T>* next;
  Node();
  friend class Integer;
};
class Integer{
  private:
  bool sign;
  Node<int>* uint;

  
  public:
  Integer();
  public:
  Integer(int);
  void operator = (string s);
  friend bool operator == (const Integer & first, const Integer & second);
  friend bool operator != (const Integer & first, const Integer & second);
  public:
  Integer(double d);
  void operator = (int i);
  friend bool operator > (const Integer & first, const Integer & second);
  friend bool operator >= (const Integer & first, const Integer & second);
  public:
  Integer(string s);
  void operator = (double d);
  friend bool operator < (const Integer & first, const Integer & second);
  friend bool operator <= (const Integer & first, const Integer & second);
  public:
  friend Integer operator + (const Integer & first, const Integer & second);
  friend istream & operator >> (istream & input, Integer & I);
  friend ostream & operator << (ostream & output, Integer & I); // Helper function
};
#endif
