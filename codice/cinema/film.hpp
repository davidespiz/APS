// File film.hpp
#ifndef FILM_HPP
#define FILM_HPP
#include <iostream>
#include <string>

class Film
{
  friend std::ostream& operator<<(std::ostream& os, const Film& f);
public:
  Film(std::string t, unsigned d);
  unsigned Durata() const { return durata; }
  std::string Titolo() const { return titolo; }
private:
  std::string titolo;
  unsigned durata; // in minuti
};
#endif
