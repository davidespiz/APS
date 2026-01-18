//File Lezione.cpp
#include "Lezione.hpp"

std::ostream& operator<<(std::ostream& os, const Lezione& l)
{
  os << l.codice << " (" << l.giorno << ")";
  return os;
}
