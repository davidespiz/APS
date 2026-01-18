// File orario.cpp
#include "orario.hpp"

bool operator<(const Orario& o1, const Orario& o2)
{
  return o1.ore < o2.ore || (o1.ore == o2.ore && o1.minuti < o2.minuti);
}

bool operator<=(const Orario& o1, const Orario& o2)
{
  return o1.ore < o2.ore || (o1.ore == o2.ore && o1.minuti <= o2.minuti);
}

bool operator==(const Orario& o1, const Orario& o2)
{
  return o1.ore == o2.ore && o1.minuti == o2.minuti;
}
 
int operator-(const Orario& o1, const Orario& o2)
{
  return (o1.ore - o2.ore) * 60 + o1.minuti - o2.minuti;
}

std::ostream& operator<<(std::ostream& os, const Orario& o)
{
  os << o.ore << ':';
  if (o.minuti < 9) os << '0'; // per una stampa piu' gradevole
  os << o.minuti;
  return os;
}

Orario::Orario(unsigned o, unsigned m)
{
  ore = o;
  minuti = m;
}
