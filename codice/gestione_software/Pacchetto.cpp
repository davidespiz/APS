// File Pacchetto.cpp
#include <stdexcept>
#include "Pacchetto.hpp"  

std::ostream& operator<<(std::ostream& os, const Pacchetto& p)
{
  os << p.nome << " (" << p.descrizione << ")";
  return os;
}

Pacchetto::Pacchetto(std::string n, std::string d)
  : nome(n), descrizione(d) {}

void Pacchetto::InserisciDipendenza(Pacchetto* p)
{
  if (CercaDipendenza(p) != -1)
    throw std::invalid_argument("Dipendenza gia' inserita");
  dipendenze.push_back(p);
}

void Pacchetto::RimuoviDipendenza(Pacchetto* p)
{
  int i = CercaDipendenza(p);
  if (i == -1)
    throw std::invalid_argument("Dipendenza assente");
  dipendenze.erase(dipendenze.begin() + i);
}

int Pacchetto::CercaDipendenza(Pacchetto* p) const
{
  unsigned i;
  for (i = 0; i < dipendenze.size(); i++)
    if (dipendenze[i] == p)
      return i;
  return -1;
}

