// File Versione.cpp
#include <stdexcept>
#include "Versione.hpp"  

std::ostream& operator<<(std::ostream& os, const Versione& v)
{
  os << *(v.pacchetto) << " [v. " << v.numero << ", " << v.rilascio 
     << ", " << v.dimensione << "KB]";
  return os;
}

Versione::Versione(unsigned n, unsigned d, Data r, Pacchetto* p)
  : rilascio(r)
{
  numero = n;
  dimensione = d;
  pacchetto = p;
}
