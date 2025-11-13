#include <iostream>
#include "MultiPila.hpp"

void TrasferisciTutti(MultiPila& p, unsigned k);

int main()
{
  MultiPila p(5);
  unsigned scelta, i;
  int elem;
  do 
    {
      cout << "MultiPila : " << p << endl;
      cout << "Operazione: " << endl
           << "  1. Push" << endl
           << "  2. Pop" << endl
           << "  3. Top" << endl
           << "  4. Trasferisci" << endl
           << "  0. Esci" << endl
           << "Scelta : ";
      cin >> scelta;

      switch(scelta)
        {
        case 1:
          {
            cout << "Pila : ";
            cin >> i;
            cout << "Elemento : ";
            cin >> elem;            
            p.Push(elem,i);
            break;
          }
        case 2:
          cout << "Pila : ";
          cin >> i;
          p.Pop(i);
          break;
        case 3:
          cout << "Pila : ";
          cin >> i;
          cout << "Elemento affiorante: " << p.Top(i) << endl;
        case 4:
          cout << "Pila : ";
          cin >> i;
          TrasferisciTutti(p,i);
        case 0:
          break;
        default:
          cout << "Scelta non valida" << endl;          
        }
    }
  while (scelta != 0);
}

void TrasferisciTutti(MultiPila& p, unsigned k)
{
  unsigned i;
  for (i = 0; i < p.NumPile(); i++)
    if (i != k)
      {
        while(!p.IsEmpty(i))
          {
            p.Push(p.Top(i),k);
            p.Pop(i);
          }
      }
}

