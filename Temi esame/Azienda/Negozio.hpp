// File Negozio.hpp
#ifndef NEGOZIO_HPP
#define NEGOZIO_HPP
#include <iostream>
#include <vector>
#include "Magazzino.hpp"

using namespace std;

class Negozio
{
  friend ostream& operator<<(ostream& os, const Negozio& n);
 public:
  Negozio(unsigned r, double x_coord, double  y_coord);
  unsigned Richiesta() const { return richiesta; }
  double X() const { return x; }
  double Y() const { return y; }
  
  unsigned Incompatibili() const { return incompatibili.size(); }
  Magazzino* Incompatibile(unsigned i) const { return incompatibili[i]; }
  bool EstCompatibile(Magazzino* m) const { return CercaIncompatibile(m) == -1; }

  void InserisciIncompatibilita(Magazzino* m);
  
 private:
  int CercaIncompatibile(Magazzino* m) const;
  unsigned richiesta;
  double x, y;
  vector<Magazzino*> incompatibili;
};
#endif
