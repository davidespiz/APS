#include <iostream>
using namespace std;

#include "Pile.hpp"

int main()
{
   Pila p;

   cin >> p;

   p.Push(12);
   p.Pop();
   cout << p << endl;

   return 0;
}