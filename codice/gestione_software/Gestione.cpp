// File Gestione.cpp
#include <stdexcept>
#include "Gestione.hpp"  

Gestione::Gestione(std::string n, unsigned st)
  : nome(n)
{
  spazio_totale = st;
  spazio_disponibile = st;
}

void Gestione::InserisciPacchettoDisponibile(Pacchetto* p)
{
  unsigned i;
  if (CercaPacchettoDisponibile(p) != -1)
    throw std::invalid_argument("Pacchetto gia' disponibile");
  for (i = 0; i < p->Dipendenze(); i++)
    if (CercaPacchettoDisponibile(p->VediDipendenza(i)) == -1)
      throw std::invalid_argument("Manca dipendenza");
  pacchetti_disponibili.push_back(p);   
}

void Gestione::InserisciVersioneDisponibile(Versione* v)
{
  unsigned i;
  int num_diff, data_diff;

  if (CercaPacchettoDisponibile(v->VediPacchetto()) == -1)
    throw std::invalid_argument("Pacchetto assente");
  // Verifica le condizioni sulle versioni e le date
  for (i = 0; i < versioni_disponibili.size(); i++)
    if(versioni_disponibili[i]->VediPacchetto() == v->VediPacchetto())
      {
	num_diff = v->Numero() - versioni_disponibili[i]->Numero();
	if (num_diff <= 0)
          throw std::invalid_argument("Versione attuale o successiva presente");
	data_diff = v->Rilascio() - versioni_disponibili[i]->Rilascio();
	if (num_diff > data_diff)
          throw std::invalid_argument("Rilascio di versione troppo anticipato");
      }
  versioni_disponibili.push_back(v);
}

void Gestione::InstallaVersione(Versione* v)
{
  unsigned i;
  int versione_corrente = -1;
  Pacchetto* p = v->VediPacchetto();

  // Verifica dipendenze
  for (i = 0; i < p->Dipendenze(); i++)
    if (CercaPacchettoInstallato(p->VediDipendenza(i)) == -1)
      {
        std::cerr << *p << " " << *p->VediDipendenza(i) << std::endl;
        throw std::invalid_argument("Manca installazione dipendenza");
      }
  // Verifica installazione precedente
  for (i = 0; i < versioni_installate.size(); i++)
    {
      if (versioni_installate[i]->VediPacchetto() == p)
	{
	  if (versioni_installate[i]->Numero() >= v->Numero())
            throw std::invalid_argument("Installata versione attuale o superiore");
	  versione_corrente = i;
	  break; // al massimo una versione e' installata
	}
    }
  // Verifica lo spazio disponibile
  if (versione_corrente == -1)
    {
      if (v->Dimensione() > spazio_disponibile)
        throw std::invalid_argument("Spazio su disco insufficiente");
    }
  else
    if (v->Dimensione() - 
        versioni_installate[versione_corrente]->Dimensione() 
        > spazio_disponibile)
      throw std::invalid_argument("Spazio su disco insufficiente");
  if (versione_corrente != -1)
    {
      spazio_disponibile += versioni_installate[versione_corrente]->Dimensione();
      versioni_installate.erase(versioni_installate.begin() 
				+ versione_corrente);
    }
  versioni_installate.push_back(v);
  spazio_disponibile -= v->Dimensione();
}

void Gestione::RimuoviVersione(Versione* v)
{
  int i = CercaVersioneInstallata(v);
  if (i == -1)
    throw std::invalid_argument("Versione assente");
  spazio_disponibile += versioni_installate[i]->Dimensione();
  versioni_installate.erase(versioni_installate.begin() + i);
}

int Gestione::CercaPacchettoDisponibile(Pacchetto* p) const
{
  unsigned i;
  for (i = 0; i < pacchetti_disponibili.size(); i++)
    if (pacchetti_disponibili[i] == p)
      return i;
  return -1;
}

int Gestione::CercaPacchettoInstallato(Pacchetto* p) const
{
  unsigned i;
  for (i = 0; i < versioni_installate.size(); i++)
    if (versioni_installate[i]->VediPacchetto() == p)
      return i;
  return -1;
}

int Gestione::CercaVersioneInstallata(Versione* v) const
{
  unsigned i;
  for (i = 0; i < versioni_installate.size(); i++)
    if (versioni_installate[i] == v)
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Gestione& g)
{
  unsigned i;
  os << g.nome << " (" << g.spazio_disponibile << "/" << g.spazio_totale << ")" << std::endl;
  os << "Pacchetti disponibile: " << std::endl;
  for (i = 0; i < g.pacchetti_disponibili.size(); i++)
    os << *(g.pacchetti_disponibili[i]) << std::endl;
  os << "Versioni disponibile: " << std::endl;
  for (i = 0; i < g.versioni_disponibili.size(); i++)
    os << *(g.versioni_disponibili[i]) << std::endl;
  os << "Versioni installate: " << std::endl;
  for (i = 0; i < g.versioni_installate.size(); i++)
    os << *(g.versioni_installate[i]) << std::endl;
  return os;
}
