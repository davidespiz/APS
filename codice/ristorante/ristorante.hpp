// File ristorante.hpp
#ifndef RISTORANTE_HPP
#define RISTORANTE_HPP
#include <vector>
#include <iostream>
#include "persona.hpp"

class Tavolo
{
public:
  Tavolo(unsigned posti = 4);
  unsigned NumPosti() const { return capienza; }
  unsigned NumSeduti() const { return seduti.size(); }
  bool Presente(Persona*) const;
  void AggiungiPersona(Persona*);
  void Libera();
  void CambiaCapienza(unsigned c);
  Persona* Occupante(unsigned i) const { return seduti[i]; }
private:
  std::vector<Persona*> seduti;
  unsigned capienza;
};

class Ristorante
{
  friend std::ostream& operator<<(std::ostream& os, const Ristorante& r);
public:
  Ristorante(std::string n, unsigned t);
  void AggiungiPersona(Persona* p, unsigned i);
  void LiberaTavolo(unsigned i);
  void ModificaTavolo(unsigned i, unsigned d);
  unsigned NumTavoli() const { return tavoli.size(); }
  std::string Nome() const { return nome; }
  unsigned PostiTavolo(unsigned i) const { return tavoli[i].NumPosti(); }
  unsigned SedutiTavolo(unsigned i) const { return tavoli[i].NumSeduti(); }
private:
  bool PersonaPresente(Persona* p);
  std::vector<Tavolo> tavoli;
  std::string nome;
};
#endif
