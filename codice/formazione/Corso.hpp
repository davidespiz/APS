//File Corso.hpp
#ifndef CORSO_HPP
#define CORSO_HPP
#include <string>
#include "../utils/Data.hpp"
#include "Cliente.hpp"
#include "Docente.hpp"
#include "Lezione.hpp"
#include <vector>

class Corso
{
  friend std::ostream& operator<<(std::ostream& os, const Corso& c);
public:
  Corso(std::string n, std::string des, Data i, Data f, unsigned max, Docente* doc);
  std::string Nome() const { return nome;}
  std::string Descrizione() const { return descrizione;}
  Data Inizio() const { return inizio;}
  Data Fine() const { return fine;}
  unsigned NMaxClienti() const { return n_max_clienti;}
  Lezione* VediLezione(unsigned i) const { return lezioni[i];}
  unsigned NumLezioni() const { return lezioni.size();}
  Cliente* VediPartecipante(unsigned i) const { return partecipanti[i];}
  unsigned NumPartecipanti() const { return partecipanti.size();}
  Docente* VediDocente() const { return docente;}
  void AggiungiLezione(Lezione* l);
  void AggiungiPartecipante(Cliente* c);
  void RimuoviLezione(Lezione* l);
  void RimuoviPartecipante(Cliente* c);
  bool EsistePartecipante(Cliente* c) const 
  { return CercaPartecipante(c) != -1; };		
private:
  std::string nome,descrizione;
  Data inizio,fine;
  unsigned n_max_clienti;
  std::vector<Lezione*> lezioni;
  std::vector<Cliente*> partecipanti;
  Docente* docente;
  int CercaLezione(Lezione* l) const;
  int CercaPartecipante(Cliente* c) const;		
};
#endif
