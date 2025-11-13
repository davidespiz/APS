#include "A.hpp"

int main()
{
  A a1(10), a2(10, false);
  a2.Set1(4,8.5);
  a1 = a2;
  a1.Set2(4,11.2);
  a2.Split();
  cout << a2.Get2(4) << endl;
  return 0; 
}
