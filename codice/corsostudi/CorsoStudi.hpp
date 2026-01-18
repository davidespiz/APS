#ifndef CORSOSTUDI_HPP
#define CORSOSTUDI_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Insegnamento.hpp"
#include "Curriculum.hpp"

enum class Tipologia {obbligatorio, scelta, curricolare};

class Erogazione
{
public:
  Erogazione(Insegnamento* in, Tipologia t, unsigned a);
  Insegnamento* insegnamento;
  Tipologia tipo;
  unsigned anno;
};

class CorsoStudi
{
  friend std::ostream& operator<<(std::ostream& os, const CorsoStudi& in);
public:
  CorsoStudi(std::string n, std::string c, unsigned cn);
  std::string Nome() const { return nome; }
  std::string Classe() const { return classe; }
  unsigned CreditiNecessari() const { return crediti_necessari; }
  void CreaCurriculum(std::string nome);
  void InserisciInsegnamento(Insegnamento* in, Tipologia t, unsigned a);
  void InserisciInCurriculum(Insegnamento* in, std::string curriculum);
  Erogazione VediInsegnamento(unsigned i) const { return erogazioni[i]; }
  unsigned Insegnamenti() const { return erogazioni.size(); }
  bool VerificaCrediti() const;
  bool EsisteInsegnamento(Insegnamento* in, Tipologia t) const;
private:
  int CercaCurriculum(std::string nome) const;
  int CercaInsegnamento(Insegnamento* in) const;
  bool PresenteInCurricula(Insegnamento* in) const;
  unsigned SommaCrediti(Tipologia t) const; 
  std::string nome;
  std::string classe;
  unsigned crediti_necessari;
  std::vector<Erogazione> erogazioni;
  std::vector<Curriculum> curricula;
};
#endif
