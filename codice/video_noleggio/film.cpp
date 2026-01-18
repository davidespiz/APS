// File film.cpp
#include "film.hpp"

Film::Film(std::string t, std::string r, int aa)
  : titolo(t), regista(r)
{
  anno = aa;
}

std::ostream& operator<<(std::ostream& os, const Film& f)
{
  os << "Titolo:   " << f.titolo << std::endl
     << "Regista:  " << f.regista << std::endl
     << "Anno:     " << f.anno << std::endl;	 
  return os;
}

