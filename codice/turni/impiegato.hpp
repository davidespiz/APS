// file Impiegato.hpp
#ifndef IMPIEGATO_HPP
#define IMPIEGATO_HPP
#include <string>

class Impiegato
{
 public:
  Impiegato(std::string n) { nome = n; }
  std::string Nome() const { return nome; }
 private:
  std::string nome;
};
#endif
