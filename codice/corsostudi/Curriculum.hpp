#ifndef CURRICULUM_HPP
#define CURRICULUM_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Insegnamento.hpp"

class Curriculum
{
  friend std::ostream& operator<<(std::ostream& os, const Curriculum& in);
public:
  Curriculum(std::string n);
  std::string Nome() const { return nome; }
  unsigned Insegnamenti() const { return insegnamenti.size(); }
  Insegnamento* VediInsegnamento(unsigned i) const { return insegnamenti[i]; }
  void InserisciInsegnamento(Insegnamento* in);
  unsigned CreditiTotali() const { return crediti_totali; }
  bool Membro(Insegnamento* in) const { return CercaInsegnamento(in) != -1; }
private:
  int CercaInsegnamento(Insegnamento* in) const;
  std::string nome;
  std::vector<Insegnamento*> insegnamenti;
  unsigned crediti_totali;
};
#endif
