#include <stdexcept>
#include "BiPila1.hpp"

void BiPila::Pop(int lato)
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (lato == 1)
    p1.Pop();
  else
    p2.Pop();
}
 
void BiPila::Push(int elem, int lato)
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (lato == 1)
    p1.Push(elem);
  else
    p2.Push(elem);
}
 
int BiPila::Top(int lato) const
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (lato == 1)
    return p1.Top();
  else
    return p2.Top();
}
 
bool BiPila::EstVuota(int lato) const
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (lato == 1)
    return p1.EstVuota();
  else
    return p2.EstVuota();
}

BiPila BiPila::operator!() const
{
  BiPila p;
  p.p1 = p2;
  p.p2 = p1;
  return p;
}

std::ostream& operator<<(std::ostream& os, const BiPila& p)
{
  os << p.p1 << '|' << p.p2;
  return os;
}

