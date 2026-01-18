// File sala.cpp
#include "sala.hpp"

Sala::Sala(std::string n, unsigned c)
  : nome(n)
{
  capienza = c;
}

std::ostream& operator<<(std::ostream& os, const Sala& s)
{
  os << s.nome << " (" << s.capienza << " posti)";
  return os;
}
