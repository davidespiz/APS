// File Comune.cpp
#include "Comune.hpp"

std::ostream& operator<<(std::ostream& os, const Comune& c)
{
  os << c.nome << " " << c.provincia;
  return os;
}

std::istream& operator>>(std::istream& is, Comune& c)
{ // Funziona solo sotto l'assunzione che nome e provincia non
  // contengano spazi
  is >> c.nome >> c.provincia;
  return is;
}
