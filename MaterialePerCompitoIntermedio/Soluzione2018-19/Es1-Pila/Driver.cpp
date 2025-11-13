#include <fstream>
#include "Pila.hpp"

using namespace std;

int main()
{
  Pila p;
  p.Push(4);
  p.Push(3);
  p.Push(4);
  p.Push(5);
  p.Push(3);
  p.Push(2);
  cout << p << endl;
  (p += 4) += 6;
  cout << p << endl;
  return 0;	
}