// File DriverPila.cpp
#include <iostream>
#include "BiPila2.hpp"

void ScambiaElementiAffioranti(BiPila& p);

int main()
{
  BiPila p;
  unsigned scelta;
  int lato;

  do 
    {
      std::cout << "BiPila : " << p << std::endl
           << "Operazione: " << std::endl
           << "  1. Push" << std::endl
           << "  2. Pop" << std::endl
           << "  3. Top" << std::endl
//            << "  4. Inverti Componenti" << std::endl
           << "  5. Scambia Affioranti" << std::endl
           << "  0. Esci" << std::endl
           << "Scelta : ";
      std::cin >> scelta;

      switch(scelta)
        {
        case 1:
          {
            int elem;
            std::cout << "Elemento : ";
            std::cin >> elem;            
	    std::cout << "Lato (1/2) : ";
	    std::cin >> lato;
            p.Push(elem,lato);
            break;
          }
        case 2:
	  std::cout << "Lato (1/2) : ";
	  std::cin >> lato;
	  p.Pop(lato);
          break;
        case 3:
	  std::cout << "Lato (1/2) : ";
	  std::cin >> lato;
	  std::cout << "Elemento affiorante (lato " << lato << ") : " << p.Top(lato) << std::endl;
//         case 4:
// 	  p = !p;
//           break;
        case 5:
	  ScambiaElementiAffioranti(p);
          break;
        case 0:
          break;
        default:
          std::cout << "Scelta non valida" << std::endl;          
        }
    }
  while (scelta != 0);
}

void ScambiaElementiAffioranti(BiPila& p)
{
  int elem;
  if (!p.EstVuota(1) && !p.EstVuota(2))
    {
      elem = p.Top(1);
      p.Pop(1);
      p.Push(p.Top(2),1);
      p.Pop(2);
      p.Push(elem,2);
    }
}
   
