// file azienda.cpp
#include <iostream>
#include <stdexcept>
#include "azienda.hpp"

Azienda::Azienda(unsigned max_imp)
{
  max_impiegati = max_imp;
}

void Azienda::Assumi(Impiegato* i)
{
  if (impiegati.size() == max_impiegati)
    throw std::invalid_argument("Massimo numero impiegati gia' raggiunto");
  if (CercaImpiegato(i) == -1)
    impiegati.push_back(i);
}

void Azienda::CreaTurno(Turno* t)
{
  if (CercaTurno(t) != -1)
    throw std::invalid_argument("Turno gia' insertito");
  turni.push_back(t);
}

void Azienda::AssegnaTurno(Impiegato* i, Turno* t)
{
  int j = CercaImpiegato(i);
  int k = CercaTurno(t);
  if (j == -1)
    throw std::invalid_argument("Impiegato sconosciuto");
  if (k != -1)
    throw std::invalid_argument("Turno sconosciuto");
  for (unsigned h = 0; h < assegnazioni.size(); h++)
    if (assegnazioni[h].imp == static_cast<unsigned>(j))
      if (!Disgiunti(turni[assegnazioni[h].turno], t))
        throw std::invalid_argument("Turni sovrapposti");
  assegnazioni.push_back(Assegnazione(j,k));
}

Impiegato* Azienda::VediImpiegato(unsigned i) const
{
  return impiegati[i];
}

Turno* Azienda::VediTurno(unsigned i) const
{
  return turni[i];
}

std::pair<Impiegato*, Turno*> Azienda::VediAssegnazione(unsigned i) const
{
  return std::make_pair(impiegati[assegnazioni[i].imp], 
                   turni[assegnazioni[i].turno]);
}

int Azienda::CercaImpiegato(Impiegato* imp) const
{
  for (unsigned j = 0; j < impiegati.size(); j++)
    if (impiegati[j] == imp)
      return j;
  return -1;
}

int Azienda::CercaTurno(Turno* t) const
{
  for (unsigned j = 0; j < turni.size(); j++)
    if (turni[j]->Start() == t->Start() && turni[j]->Stop() == t->Stop())
      return j;
  return -1;
}

std::ostream& operator<<(std::ostream & os, const Azienda& az)
{// non richiesto per il compito in classe
  unsigned i;

  os << "Stampa azienda (max " << az.max_impiegati << ") dipendenti" << std::endl;
  os << "Impiegati:" << std::endl;
  for (i = 0; i < az.impiegati.size(); i++)
    os << i+1 << " : " << az.impiegati[i]->Nome() << std::endl;
  os << "Turni:" << std::endl;
  for (i = 0; i < az.turni.size(); i++)
    os << i+1 << " : " << az.turni[i]->Start() << "-" << az.turni[i]->Stop() << std::endl;
  os << "Assegnazioni:" << std::endl;
  for (i = 0; i < az.assegnazioni.size(); i++)
    os << i+1 << " : " << az.impiegati[az.assegnazioni[i].imp]->Nome() << " ==> " 
         << az.turni[az.assegnazioni[i].turno]->Start() << "-" 
         << az.turni[az.assegnazioni[i].turno]->Stop() << std::endl;
  return os;
}
