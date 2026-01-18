#ifndef BIPILA_HPP
#define BIPILA_HPP

#include <iostream>
#include "Pila.hpp"

class BiPila
{
  friend std::ostream& operator<<(std::ostream& os, const BiPila& p);
public:
  void Pop(int lato); 
  void Push(int elem, int lato); 
  int Top(int lato) const; 
  bool EstVuota(int lato) const;
  BiPila operator!() const;
 private:
  Pila p1, p2;
};

#endif
