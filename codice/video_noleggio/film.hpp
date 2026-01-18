// File film.hpp
#ifndef FILM_HPP
#define FILM_HPP
#include <iostream>
#include <string>

class Film
{
  friend std::ostream& operator<<(std::ostream& os, const Film& f);
public:
  Film(std::string t, std::string r, int aa);
  std::string Titolo() const { return titolo; }
  std::string Regista() const { return regista; }
  int Anno() const { return anno; }  
private:
  std::string titolo;
  std::string regista;
  int anno;
};
#endif

