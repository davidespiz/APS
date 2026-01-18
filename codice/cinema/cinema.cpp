// File cinema.cpp
#include <stdexcept>
#include "cinema.hpp"

GestioneCinema::GestioneCinema(std::string n)
  : nome(n)
{}

void GestioneCinema::InserisciProiezione(Proiezione* p)
{
  if (CercaProiezione(p) != -1)
    throw std::invalid_argument("Proiezione gia' inserita");    
  if (!VerificaOrario(p->OraInizio(),p->OraFine(),p->SalaProiezione()))
    throw std::invalid_argument("Orario indisponibile per la proiezione");
  if (p->NumeroPrenotazioni() > 0)
	throw std::invalid_argument("Proiezione con prenotazioni");
  proiezioni.push_back(p);
}

void GestioneCinema::RimuoviProiezione(Proiezione* p)
{
  int i = CercaProiezione(p);
  if (i == -1)
    throw std::invalid_argument("Proiezione assente");    
  proiezioni.erase(proiezioni.begin() + i);
}

void GestioneCinema::CambiaOrario(Proiezione* p, Orario i, Orario o)
{
  RimuoviProiezione(p);
  if (!VerificaOrario(i,o,p->SalaProiezione()))
    throw std::invalid_argument("Nuovo orario indisponibile per la proiezione");
  p->CambiaOrario(i,o);
  InserisciProiezione(p);
}

void GestioneCinema::CambiaSala(Proiezione* p, Sala* s)
{
  if (!VerificaOrario(p->OraInizio(),p->OraFine(),s))
    throw std::invalid_argument("Orario indisponibile in nuova sala");
  p->CambiaSala(s);
}

bool GestioneCinema::InserisciPrenotazione(Prenotazione* pn, Proiezione* p)
{
  if (CercaProiezione(p) == -1)	
    throw std::invalid_argument("Proiezione assente");    
  return p->AggiungiPrenotazione(pn);
}

bool GestioneCinema::VerificaOrario(Orario inizio, Orario fine, Sala* s)
{
  for (unsigned i = 0; i < proiezioni.size(); i++)
    if (proiezioni[i]->SalaProiezione() == s)
      if (!(proiezioni[i]->OraFine() <= inizio 
            || fine <= proiezioni[i]->OraInizio()))
        return false;
  return true;
}

int GestioneCinema::CercaProiezione(Proiezione* p)
{
  for (unsigned i = 0; i < proiezioni.size(); i++)
    if (proiezioni[i] == p)
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const GestioneCinema& c)
{
  os << "Cinema " << c.nome << std::endl;
  for (unsigned i = 0; i < c.proiezioni.size(); i++)
    os << *(c.proiezioni[i]) << std::endl;
  return os;
}
