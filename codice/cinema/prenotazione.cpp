// File prenotazione.cpp
#include "prenotazione.hpp"

Prenotazione::Prenotazione(std::string n, unsigned p)
  : nome_prenotante(n)
{
  posti = p;
}

std::ostream& operator<<(std::ostream& os, const Prenotazione& p)
{
  os << p.nome_prenotante << ": " << p.posti;
  return os;
}
