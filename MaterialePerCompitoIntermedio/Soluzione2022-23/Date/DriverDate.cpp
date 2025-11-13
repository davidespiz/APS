// File DriverVettore.cpp
#include <iostream>
#include "Data.hpp"

int main()
{
  Data d1(26,10,2022), d2(4,11,2022), d3; 
  
  d3 = d1|d2;

  cout << d1 << endl;
  cout << d2 << endl;
  cout << d3 << endl;

  return 0;
}
