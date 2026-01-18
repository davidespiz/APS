// file campominato.hpp
#ifndef CAMPOMINATO_HPP
#define CAMPOMINATO_HPP
#include <iostream>
#include <vector>
#include "casella.hpp"

class CampoMinato
{
  friend std::ostream& operator<<(std::ostream& os, const CampoMinato& u);
 public:
  CampoMinato(unsigned dim, unsigned num_b);
  int Muovi(char dir);
  unsigned Esplora(unsigned r);
  Casella Posizione() const { return posizione; }
  unsigned ScoppiRimasti() const { return max_scoppi - scoppi; }
  unsigned Dim() const { return dim; }
 private:
  unsigned dim;
  unsigned scoppi, max_scoppi;
  Casella posizione, tesoro;
  std::vector<Casella> bombe;
  bool CasellaProibita(Casella c);
  bool EstBomba(Casella c);
};
#endif
