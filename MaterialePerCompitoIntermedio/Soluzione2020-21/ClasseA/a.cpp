#include "a.hpp"

A::A(const A& a)
{
  p1 = new B(*(a.p1)); // invoca il costruttore di copia per B, 
                       // in alternativa p1 = new B(a.Get1()) 
					   // che invoca B(int)
  if (a.p2 == a.p1)
    p2 = p1;
  else
    p2 = new B(*(a.p2)); 
}

A& A::operator=(const A& a)
{
  *p1 = *(a.p1);  // copia l'oggetto puntato da p1 
                  // (non è necessario deallocarlo e riallocarlo)
  if (a.p1 == a.p2)
  {
    if (p1 != p2)
      {
     	delete p2;
        p2 = p1;
      }
	 // else: nessuna azione 
  }
  else
    if (p1 == p2)
      p2 = new B(*(a.p2)); 
    else
      *p2 = *(a.p2);
  return *this;
} 

A::~A()
{
  delete p1;
  if (p2 != p1)
    delete p2;
}
