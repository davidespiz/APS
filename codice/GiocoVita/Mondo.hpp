// File Mondo.hpp
#ifndef MONDO_HPP
#define MONDO_HPP
#include <iostream>
#include <vector>
#include <stdexcept>

class Mondo
{
  friend std::ostream& operator<<(std::ostream& os, const Mondo& m);  
  friend std::istream& operator>>(std::istream& is, Mondo& m);
  friend bool operator==(const Mondo& m1, const Mondo& m2);
public:
  Mondo(unsigned n = 10);
  unsigned Dimensione() const { return dim; }
  bool Cella(unsigned i, unsigned j) const { return scacchiera[i][j]; }
  void InizializzaCella(unsigned i, unsigned j, bool vivo);
  void Evolvi();
  bool EsisteVita() const;
private:
  unsigned dim;
  std::vector<std::vector<bool>> scacchiera;
  unsigned NumeroViciniVivi(unsigned i, unsigned j) const;
};
#endif
