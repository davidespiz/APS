// file Azienda.hpp
#ifndef AZIENDA_HPP
#define AZIENDA_HPP
#include <string>
#include <vector>
#include "impiegato.hpp"
#include "turno.hpp"

class Assegnazione
{// un oggetto rappresenta l'assegnazione di una persona ad un turno
public:
  Assegnazione(unsigned i, unsigned t) { imp = i; turno = t; }
  unsigned imp, turno;
};

class Azienda
{
  friend std::ostream& operator<<(std::ostream &, const Azienda&);
 public:
  Azienda(unsigned max_imp);
  unsigned Impiegati() const { return impiegati.size(); }
  unsigned Turni() const { return turni.size(); }
  unsigned Assegnazioni() const { return assegnazioni.size(); }
  void Assumi(Impiegato* i);
  void CreaTurno(Turno* t);
  void AssegnaTurno(Impiegato* i, Turno* t);
  Impiegato* VediImpiegato(unsigned i) const;
  Turno* VediTurno(unsigned i) const;
  std::pair<Impiegato*,Turno*> VediAssegnazione(unsigned i) const;
 private:
  unsigned max_impiegati;
  std::vector<Impiegato*> impiegati;
  std::vector<Turno*> turni;
  std::vector<Assegnazione> assegnazioni;
  int CercaImpiegato(Impiegato* i) const;
  int CercaTurno(Turno* t) const;
};
#endif
