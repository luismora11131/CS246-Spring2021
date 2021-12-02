#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <string>
#include <cctype>

namespace wf
{
  int counter;

  int Function01(int data[],int n,int target)
  {
    for(int i = 0;i < n;i += 1)
    {
      if(target == data[i])
      {
        return i;
      }
    }
    return -1;
  }

  void Function02(std::string& data)
  {
    int n = data.length();

    for(int i = 0;i < n;i += 1)
    {
      data[i] = toupper(data[i]);
    }
  }

  bool Function03(int n)
  {
    if(n == 0)
    {
      return false;
    }
    else if(n < 0)
    {
      n *= -1;
    }

    for(int i = 2;i * i <= n;i += 1)
    {
      if(n % i == 0)
      {
        return false;
      }
    }
    return true;
  }
  
}

#endif