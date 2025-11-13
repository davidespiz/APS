#include "A.hpp"

int main()
{
  A a(false,3.2), b(true);
  a[2] = -1.7; a[4] = -4.88;
  cout << a << endl << b << endl;
  return 0; 
}
