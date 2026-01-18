// File ristorante.cpp
#include <stdexcept>
#include "ristorante.hpp"

Tavolo::Tavolo(unsigned posti)
{
  capienza = posti;
}

bool Tavolo::Presente(Persona* p) const
{
  for (unsigned i = 0; i < seduti.size(); i++)
    if (seduti[i] == p)
      return true;
  return false;
}

void Tavolo::AggiungiPersona(Persona* p)
{
  if (seduti.size() >= capienza)
    throw std::invalid_argument("Tavolo gia' pieno");
  seduti.push_back(p);
}

void Tavolo::Libera()
{
  seduti.clear();
}

void Tavolo::CambiaCapienza(unsigned c)
{
  if (seduti.size() > 0)
    throw std::invalid_argument("Impossibile cambiare capienza ad un tavolo occupato");
  capienza = c;
}

Ristorante::Ristorante(std::string n, unsigned t)
  : tavoli(t), nome(n)
{}

void Ristorante::AggiungiPersona(Persona* p, unsigned i)
{
  if (!PersonaPresente(p))
    tavoli[i].AggiungiPersona(p);
}

void Ristorante::LiberaTavolo(unsigned i)
{
  tavoli[i].Libera();
}

void Ristorante::ModificaTavolo(unsigned i, unsigned d)
{
  tavoli[i].CambiaCapienza(d);
}

bool Ristorante::PersonaPresente(Persona* p)
{
  for (unsigned i = 0; i < tavoli.size(); i++)
    if (tavoli[i].Presente(p))
      return true;
  return false;
}

std::ostream& operator<<(std::ostream& os, const Ristorante& r)
{
  os << "Ristorante " << r.nome << std::endl;
  for (unsigned i = 0; i < r.tavoli.size(); i++)
    {
      os << "Tavolo " << i+1 << " (" << r.PostiTavolo(i) << " posti) : ";
      for (unsigned j = 0; j < r.SedutiTavolo(i); j++)
        os << r.tavoli[i].Occupante(j)->Nome() << ' ';
      os << std::endl;
    }
  return os;
}
