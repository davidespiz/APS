// File Presentazione.cpp
#include <stdexcept>
#include "Presentazione.hpp"

Presentazione::Presentazione(std::string t, std::string r, unsigned p)
  : titolo(t), relatore(r)
{ 
  partecipanti = p; 
}

void Presentazione::Schedula(Aula* a, Data g, unsigned o)
{
  if (a->Capienza() < partecipanti)
    throw std::invalid_argument("Aula troppo piccola");
  schedulazione.Assegna(g, o, a);
}

void Presentazione::InserisciConflitto(Presentazione* p)
{
  if(CercaConflitto(p) == -1)  // p->CercaConflitto(this) == -1
    {
      in_conflitto.push_back(p);
      p->in_conflitto.push_back(this);
    }
}

void Presentazione::RimuoviConflitto(Presentazione* p)
{
  int j, i = CercaConflitto(p);
  if(i != -1)
    {
      j = p->CercaConflitto(this);
      p->in_conflitto.erase(p->in_conflitto.begin() + j);
      in_conflitto.erase(in_conflitto.begin() + i);
    }
}

int Presentazione::CercaConflitto(Presentazione* p) const
{
  for(unsigned i = 0; i < in_conflitto.size(); i++)
    if(in_conflitto[i] == p)
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Presentazione& p)
{
  os << "\"" << p.titolo << "\", " << p.relatore
     << " (" << p.partecipanti << " partecipanti)";
  if(p.schedulazione.aula == nullptr)
    os << " - in programma";
  else
    os << " - si terra' il " << p.schedulazione.giorno << " alle ore "
       << p.schedulazione.ora << " in aula " << *(p.schedulazione.aula);
  os << std::endl;
  os << "Presentazioni in conflitto: " << p.in_conflitto.size() << std::endl;
  for(unsigned i = 0; i < p.in_conflitto.size(); i++)
    os << "\t" << i+1 << ". \"" << p.in_conflitto[i]->titolo << "\", "
       << p.in_conflitto[i]->relatore << std::endl;
  os << std::endl;
  return os;
}
