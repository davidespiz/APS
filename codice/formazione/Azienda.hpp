//File Azienda.hpp
#ifndef AZIENDA_HPP
#define AZIENDA_HPP
#include <string>
#include <vector>
#include <iostream>
#include "Cliente.hpp"
#include "Docente.hpp"
#include "Corso.hpp"

class Azienda
{
  friend std::ostream& operator<<(std::ostream& os, const Azienda& a);
public:
  Azienda(std::string);
  std::string Nome() const { return nome; }
  Corso* VediCorso(unsigned i) const { return corsi[i]; }
  unsigned NumCorsi() const { return corsi.size(); }
  Cliente* VediCliente(unsigned i) const { return clienti[i]; }
  unsigned NumClienti() const { return clienti.size(); }
  Docente* VediDocente(unsigned i) const { return docenti[i]; }
  unsigned NumDocenti() const { return docenti.size(); }
  void InserisciDocente(Docente* d);
  void InserisciCorso(Corso* c);
  void InserisciLezioneCorso(Lezione* l, Corso* c);
  void InserisciCliente(Cliente* c);
  void InserisciClienteCorso(Cliente* cl, Corso* co);
  void RimuoviClienteCorso(Cliente* cl, Corso* co);
  void CancellaLezione(Lezione* l);
private:
  std::string nome;
  std::vector<Cliente*> clienti;
  std::vector<Corso*> corsi;
  std::vector<Docente*> docenti;
  int CercaCliente(Cliente* c) const;
  int CercaCorso(Corso* c) const;
  int CercaDocente(Docente* d) const;
};
#endif
