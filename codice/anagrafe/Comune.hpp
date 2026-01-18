// File Comune.hpp
#ifndef COMUNE_HPP
#define COMUNE_HPP
#include <iostream>
#include <string>

class Comune
{
  friend std::ostream& operator<<(std::ostream& os, const Comune&);
  friend std::istream& operator>>(std::istream& is, Comune&);
public:
  Comune(std::string n, std::string pr)  : nome(n), provincia(pr) {}
  Comune() {}
  std::string Nome() const { return nome; }
  std::string Provincia() const { return provincia; }
private:
  std::string nome;
  std::string provincia;
};
#endif
