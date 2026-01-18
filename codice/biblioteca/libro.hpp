// file libro.hpp
#ifndef LIBRO_HPP
#define LIBRO_HPP
#include <string>

class Libro
{
public:
  Libro(std::string n) { nome = n; }
  std::string Nome() const { return nome; }
private:
  std::string nome;
};
#endif
