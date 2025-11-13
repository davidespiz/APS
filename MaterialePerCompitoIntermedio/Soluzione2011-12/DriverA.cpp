#include <iostream>
#include "A.hpp"

using namespace std;

int main()
{
  A a1(5), a2; //, a3();
  a1[3] = 5;
//   a1++;
  a2[2] = a1[3] + a1[4] + 2;
  a1.BackUp();
  a1[3]++;
//   a1.v[2] = 5;
//   a2.Restore(); 
  cout << a1 << endl << a2 << endl; // << a3 << endl;
  return 0;
}
