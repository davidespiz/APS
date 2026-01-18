// File Aula.hpp
#ifndef AULA_HPP
#define AULA_HPP
#include <iostream>
#include <string>

class Aula
{
  friend std::ostream& operator<<(std::ostream& os, const Aula& a);
public:
  Aula(std::string n, unsigned c)
    : nome(n) { capienza = c; }
  std::string Nome() const { return nome; }
  unsigned Capienza() const { return capienza; }
  void SetNome(std::string n) { nome = n; }
  void SetCapienza(unsigned c) { capienza = c; }
private:
  std::string nome;
  unsigned capienza;
};

inline std::ostream& operator<<(std::ostream& os, const Aula& a)
{
  return os << a.nome << " (" << a.capienza << " posti)";
}
#endif
