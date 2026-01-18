// File film.cpp
#include "film.hpp"

Film::Film(std::string t, unsigned d)
  : titolo(t)
{
  durata = d;
}

std::ostream& operator<<(std::ostream& os, const Film& f)
{
  os << f.titolo << " (" << f.durata << " minuti)";
  return os;
}
