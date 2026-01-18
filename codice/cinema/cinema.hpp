// File cinema.hpp
#ifndef CINEMA_HPP
#define CINEMA_HPP
#include <vector>
#include <iostream>
#include "proiezione.hpp"

class GestioneCinema
{
  friend std::ostream& operator<<(std::ostream& os, const GestioneCinema& c);
public:
  GestioneCinema(std::string n);
  std::string Nome() const { return nome; }
  unsigned NumeroProiezioni() const { return proiezioni.size(); }
  Proiezione* VediProiezione(unsigned i) const { return proiezioni[i]; }
  void InserisciProiezione(Proiezione* p);
  void RimuoviProiezione(Proiezione* p);
  void CambiaOrario(Proiezione* p, Orario i, Orario o);
  void CambiaSala(Proiezione* p, Sala* s);
  bool InserisciPrenotazione(Prenotazione* pn, Proiezione* pi);
private:
  bool VerificaOrario(Orario i, Orario f, Sala* s);
  int CercaProiezione(Proiezione* p);
  std::vector<Proiezione*> proiezioni;
  std::string nome;
};
#endif
