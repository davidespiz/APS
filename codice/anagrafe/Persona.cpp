// File Persone.cpp
#include <stdexcept>
#include "Persona.hpp"

Persona::Persona() 
{ 
  comune_residenza = nullptr; 
  coniuge = nullptr;
  padre = nullptr;
  madre = nullptr;
}

Persona::Persona(std::string n, std::string c, char s, Data d, std::string cn, Comune* p_com)
  : nome(n), cognome(c), data_nascita(d), citta_nascita(cn)
{
  sesso = s;
  comune_residenza = p_com;
  coniuge = nullptr;
  padre = nullptr;
  madre = nullptr;
}

void Persona::CambiaComune(Comune* p_com)
{
  comune_residenza = p_com;
}

void Persona::AggiungiConiuge(Persona* p)
{
  if (coniuge != nullptr || p->coniuge != nullptr)
    throw std::invalid_argument("Persona gia' sposata");
  if  (sesso == p->sesso)
    throw std::invalid_argument("Persone dello stesso sesso");
  coniuge = p;
  p->coniuge = this;
}

void Persona::RimuoviConiuge()
{
  if (coniuge == nullptr)
    throw std::invalid_argument("Persona non sposata");
  coniuge->coniuge = nullptr;
  coniuge = nullptr;
}

void Persona::AggiungiGenitore(Persona* p)
{
  if (p->sesso == 'm')
    {
      if (padre != nullptr)
        throw std::invalid_argument("Padre gia' inserito");
      padre = p;
    }
  else
    {
      if (madre != nullptr)
        throw std::invalid_argument("Madre gia' inserita");
      madre = p;
    }
  p->figli.push_back(this);
}

void Persona::RimuoviPadre()
{
  if (padre == nullptr)
    throw std::invalid_argument("Padre assente");
  padre->EliminaCollegamentoFiglio(this);
  padre = nullptr;
}
 
void Persona::RimuoviMadre()
{
  if (madre == nullptr)
    throw std::invalid_argument("Madre assente");
  madre->EliminaCollegamentoFiglio(this);
  madre = nullptr;
}

void Persona::AggiungiFiglio(Persona* p)
{
  figli.push_back(p);
  if (sesso == 'm')
    p->padre = this;
  else
    p->madre = this;
}

void Persona::RimuoviFiglio(Persona* p)
{
  EliminaCollegamentoFiglio(p);
  if (sesso == 'm')
    p->padre = nullptr;
  else
    p->madre = nullptr;
}

void Persona::EliminaCollegamentoFiglio(Persona* p)
{
  for (unsigned i = 0; i < figli.size(); i++)
    if (figli[i] == p)
      {
        figli.erase(figli.begin() + i);
        break;
      }
}

void Persona::StatoDiFamiglia(std::ostream& os) const
{ 
  os << *this << std::endl;
  char desinenza = (sesso == 'm') ? 'o' : 'a';
  if (padre != nullptr)
    {
      os << "Figli" << desinenza << " di : ";
      os << padre->Nome() << " " << padre->Cognome() << std::endl;
    }
  if (madre != nullptr)
    {
      os << "Figli" << desinenza << " di : ";
      os << madre->Nome() << " " << madre->Cognome() << std::endl;
    }
  if (coniuge != nullptr)
    {
      os << "Coniugat" << desinenza << " con : ";
      os << coniuge->Nome() << " " << coniuge->Cognome() << std::endl;
    }
  else
    os << "Non coniugat" << desinenza << std::endl;
  if (figli.size() > 0)
    {
      os << "Figli : " << std::endl;
      for (unsigned i = 0; i < figli.size(); i++)
        os << figli[i]->Nome() << " " << figli[i]->Cognome() << std::endl;
    }
  else
    os << "Nessun figlio" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Persona& p)
{
  os << p.nome << ' ' << p.cognome << " (" << p.sesso << "), " 
     << p.data_nascita << "  " << p.citta_nascita;
  return os;
}  

std::istream& operator>>(std::istream& is, Persona& p)
{
  char ch;
  is >> p.nome >> p.cognome >> ch >> p.sesso >> ch >> p.data_nascita 
     >> p.citta_nascita;
  return is;
}  
