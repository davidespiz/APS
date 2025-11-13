#include "a.hpp"
#include <iostream>

using namespace std;

int main()       
{
  A a1(5);
  a1.Flip();
  a1.Set1(6);
  A a2 = a1;
  a2.Set1(4);
  cout << a1.Get1() << '/' 
       << a1.Get2() << endl;
  return 0;
}

// stampa 4/5 senza costruttore di copia, 6/5 se corretta