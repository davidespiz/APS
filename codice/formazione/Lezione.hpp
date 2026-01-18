//File Lezione.hpp
#ifndef LEZIONE_HPP
#define LEZIONE_HPP
#include <string>
#include <iostream>
#include "../utils/Data.hpp"

class Lezione
{
  friend std::ostream& operator<<(std::ostream& os, const Lezione& l);
public:
  Lezione(std::string c, Data g)   
    : codice(c),giorno(g) {}
  std::string Codice() const {return codice;}
  Data Giorno() const {return giorno;}
private:
  std::string codice;
  Data giorno;
};
#endif
