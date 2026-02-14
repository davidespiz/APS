// File Magazzino.hpp
#ifndef MAGAZZINO_HPP
#define MAGAZZINO_HPP
#include <iostream>

using namespace std;

class Magazzino
{
  friend ostream& operator<<(ostream& os, const Magazzino& m);
 public:
  Magazzino(unsigned c, double x_coord, double  y_coord);
  unsigned Capacita() const { return capacita; }
  bool Aperto() const { return aperto; }
  double X() const { return x; }
  double Y() const { return y; }
  void Apri() { aperto = true; }
  void Chiudi() { aperto = false; }
 private:
  unsigned capacita;
  bool aperto;
  double x, y;
};
#endif
