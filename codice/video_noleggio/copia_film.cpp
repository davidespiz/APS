//file copia_film.cpp
#include "copia_film.hpp"

std::ostream& operator<<(std::ostream& os, const CopiaFilm& c)
{
  os << "Copia numero " << c.numero << " del film " << c.film->Titolo() << std::endl
     << "supporto      :" << c.supporto << std::endl
     << "acquisito il  :" << c.acquisizione << std::endl;

  return os;
}

