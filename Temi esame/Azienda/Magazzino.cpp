// File Magazzino.cpp
#include "Magazzino.hpp"

Magazzino::Magazzino(unsigned c, double x_coord, double  y_coord)
{
  capacita = c;
  aperto = true;
  x = x_coord;
  y = y_coord;
}

ostream& operator<<(ostream& os, const Magazzino& m)
{
  os << "Magazzino " << (m.aperto ? "aperto" : "chiuso") << " di capacita " << m.capacita << " in posizione (" << m.x << "," << m.y << ")"; 
  return os;
}
