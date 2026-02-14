// File Negozio.cpp
#include "Negozio.hpp"

Negozio::Negozio(unsigned r, double x_coord, double  y_coord)
{
  richiesta = r;
  x = x_coord;
  y = y_coord;
}

void Negozio::InserisciIncompatibilita(Magazzino* m)
{
  if (CercaIncompatibile(m) == -1)
    incompatibili.push_back(m);
}

int Negozio::CercaIncompatibile(Magazzino* m) const
{
  unsigned i;
  for (i = 0; i < incompatibili.size(); i++)
    if (incompatibili[i] == m)
      return i;
  return -1;
}

ostream& operator<<(ostream& os, const Negozio& n)
{
  // unsigned i;
  os << "Negozio con richiesta " << n.richiesta 
     << " in posizione (" << n.x << "," << n.y << ")"; 
	 
  // os << "Magazzini incompatibili:" << endl;
  // for (i = 0; i < n.magazzini_incompatibili.size(); i++)
    // os << *(n.magazzini_incompatibili[i]) << endl;
  // os  << endl;

  return os;
}

