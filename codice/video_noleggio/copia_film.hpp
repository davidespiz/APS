//file copia_film.hpp
#ifndef COPIA_FILM_HPP
#define COPIA_FILM_HPP
#include "film.hpp"
#include "data.hpp"

class CopiaFilm
{
  friend std::ostream& operator<<(std::ostream& os, const CopiaFilm& c);
public:
  CopiaFilm(std::string s, int n, Data a, Film* f) : supporto(s), acquisizione(a)
  { film = f; numero = n; }
  std::string Supporto() const { return supporto; }
  Data Acquisizione() const { return acquisizione; }
  int Numero() const { return numero; }
  Film* VediFilm() const { return film; } 
private:
  std::string supporto;
  Data acquisizione;
  int numero;
  Film* film;
};
#endif

