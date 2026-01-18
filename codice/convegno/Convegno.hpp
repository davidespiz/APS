// File Convegno.hpp
#ifndef CONVEGNO_HPP
#define CONVEGNO_HPP
#include "Presentazione.hpp"

class Convegno
{
  friend std::ostream& operator<<(std::ostream& os, const Convegno& c);
public:
  Convegno(std::string n, Data i, Data f);
  std::string Nome() const {return nome;}
  Data DataInizio() const {return inizio;}
  Data DataFine() const {return fine;}
  unsigned NumPresentazioni() const {return presentazioni.size();}
  Presentazione* VediPresentazione(unsigned i) const { return presentazioni[i]; }
  unsigned NumAule() const {return aule.size();}
  Aula* VediAula(unsigned i) const { return aule[i]; }
  void InserisciPresentazione(Presentazione* p);
  void EliminaPresentazione(Presentazione* p);
  void InserisciAula(Aula* a);
  void InserisciConflitto(Presentazione* p1, Presentazione* p2);
  void RimuoviConflitto(Presentazione* p1, Presentazione* p2);
  void SchedulaPresentazione(Presentazione* p, Aula* a, Data g, unsigned o);
private:
  std::string nome;
  Data inizio, fine;
  std::vector<Presentazione*> presentazioni;
  std::vector<Aula*> aule;
  bool AulaLibera(Aula* a, Data g, unsigned o) const;
  int CercaPresentazione(Presentazione* p) const;
  int CercaAula(Aula* a) const;
};
#endif




