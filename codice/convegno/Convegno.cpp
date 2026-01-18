// File Convegno.cpp
#include <stdexcept>
#include "Convegno.hpp"

Convegno::Convegno(std::string n, Data i, Data f)
  : nome(n), inizio(i), fine(f)
{ 
  if (inizio > fine)
    throw std::invalid_argument("Intervallo impossibile");    
}

void Convegno::InserisciPresentazione(Presentazione* p)
{
  if (CercaPresentazione(p) != -1)
    throw std::invalid_argument("Presentazione gia' inserita");
  presentazioni.push_back(p);
}

void Convegno::EliminaPresentazione(Presentazione* p)
{
  unsigned k;
  int i = CercaPresentazione(p);
  if (i == -1)
    throw std::invalid_argument("Presentazione assente");
  if(presentazioni[i]->AulaPresentazione() != nullptr)
    presentazioni[i]->LiberaAula();
  if(presentazioni[i]->NumInConflitto() > 0)
    {
      for(k = 0; k < presentazioni.size(); k++)
	  {
	    if(presentazioni[k]->InConflitto(presentazioni[i]))
	      presentazioni[k]->RimuoviConflitto(presentazioni[i]);
	  }
    }
  presentazioni.erase(presentazioni.begin() + i);
}

void Convegno::InserisciAula(Aula* a)
{
  if (CercaAula(a) != -1)
    throw std::invalid_argument("Aula gia' inserita");    
  aule.push_back(a);
}

void Convegno::InserisciConflitto(Presentazione* p1, Presentazione* p2)
{
  int i, j;
  i = CercaPresentazione(p1);
  j = CercaPresentazione(p2);
  if (i == -1 || j == -1)
    throw std::invalid_argument("Presentazione assente");
  presentazioni[i]->InserisciConflitto(presentazioni[j]);
}

void Convegno::RimuoviConflitto(Presentazione* p1, Presentazione* p2)
{
  int i, j;
  i = CercaPresentazione(p1);
  j = CercaPresentazione(p2);
  if (i == -1 || j == -1)
    throw std::invalid_argument("Presentazione assente");
  presentazioni[i]->RimuoviConflitto(presentazioni[j]);
}

void Convegno::SchedulaPresentazione(Presentazione* p, Aula* a, Data g, unsigned o)
{
  int i = CercaPresentazione(p), j = CercaAula(a);
  if (o < 9 || o > 18)
    throw std::domain_error("Orario fuori dominio");
  if (g < inizio || g > fine)
    throw std::invalid_argument("Data fuori intervallo");    
  if (i == -1)
    throw std::invalid_argument("Presentazione assente");
  if (j == -1)
    throw std::invalid_argument("Aula assente");
  if (presentazioni[i]->AulaPresentazione() != nullptr);
    throw std::invalid_argument("Presentazione gia' assegnata");
  if (!AulaLibera(a,g,o))
    throw std::invalid_argument("Aula occupata");
  presentazioni[i]->Schedula(a, g, o);
}

bool Convegno::AulaLibera(Aula* a, Data g, unsigned o) const
{
  for(unsigned k = 0; k < presentazioni.size(); k++)
    if(presentazioni[k]->AulaPresentazione() == a &&
       presentazioni[k]->DataPresentazione() == g &&
       presentazioni[k]->OraPresentazione() == o)
      return false;
  return true;
}

int Convegno::CercaPresentazione(Presentazione* p) const
{
  for(unsigned i = 0; i < presentazioni.size(); i++)
    if(presentazioni[i] == p)
      return i;
  return -1;
}

int Convegno::CercaAula(Aula* a) const
{
  for(unsigned i = 0; i < aule.size(); i++)
    if(aule[i] == a)
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Convegno& c)
{
  unsigned i;
  os << "Convegno \"" << c.nome << "\" (dal " << c.inizio
     << " al " << c.fine << ")" << std::endl;
  os << "Aule: " << c.aule.size() << std::endl;
  for(i = 0; i < c.aule.size(); i++)
    os << i+1 << ": " << *(c.aule[i]) << std::endl;
  os << std::endl;
  os << "Presentazioni: " << c.presentazioni.size() << std::endl;
  for(i = 0; i < c.presentazioni.size(); i++)
    os << i+1 << ": " << *(c.presentazioni[i]) << std::endl;
  os << std::endl;
  return os;
}
