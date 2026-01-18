//File vigile.hpp
#ifndef VIGILE_HPP
#define VIGILE_HPP
#include <vector>
#include <string>
#include <iostream>
#include "contravvenzione.hpp"

class Vigile
{
  friend std::ostream& operator<<(std::ostream& os, const Vigile& vig);
public:
  Vigile(std::string n, std::string m)
    : nome(n), matricola(m) {}
  std::string Nome() const { return nome; }
  std::string Matricola()const { return matricola; }
  void EffettuaContravvenzione(Contravvenzione*);
  void EliminaContravvenzione(Contravvenzione*);
  Contravvenzione* ContravvenzioneEffettuata(unsigned i) const { return contravvenzioni[i]; }
  unsigned NumeroContravvenzioni() const { return contravvenzioni.size(); }
private:
  std::string nome;
  std::string matricola;
  std::vector <Contravvenzione*> contravvenzioni;
  int Cerca(Contravvenzione*) const;
};
#endif
