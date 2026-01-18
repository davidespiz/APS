//File Cliente.cpp
#include "Cliente.hpp"

std::ostream& operator<<(std::ostream& os, const Cliente& c)
{
  os << c.nome << " " << c.email;
  return os;
}
