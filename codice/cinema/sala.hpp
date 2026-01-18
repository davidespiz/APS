// File sala.hpp
#ifndef SALA_HPP
#define SALA_HPP
#include <iostream>
#include <string>

class Sala
{
  friend std::ostream& operator<<(std::ostream& os, const Sala& s);
public:
  Sala(std::string n, unsigned c);
  unsigned Capienza() const { return capienza; }
  std::string Nome() const { return nome; }
private:
  std::string nome;
  unsigned capienza;
};
#endif
