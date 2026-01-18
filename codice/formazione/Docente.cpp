//File Docente.cpp
#include "Docente.hpp"

std::ostream& operator<<(std::ostream& os, const Docente& d)
{
  os << d.nome << " (" << d.email << ") [" << d.codice << "]";
  return os;
}
