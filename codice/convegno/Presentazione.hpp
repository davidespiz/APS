// File Presentazione.hpp
#ifndef PRESENTAZIONE_HPP
#define PRESENTAZIONE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "../utils/Data.hpp"
#include "Aula.hpp"

class Schedulazione
{
 public:
  Schedulazione()
    { aula = nullptr; ora = 0; }
  Schedulazione(Data g, unsigned o, Aula* a)
    : giorno(g)  { ora = o; aula = a; }
  void Assegna(Data g, unsigned o, Aula* a)
    { giorno = g; ora = o; aula = a; }
  Data giorno;
  unsigned ora;
  Aula* aula;
};

class Presentazione
{
  friend std::ostream& operator<<(std::ostream& os, const Presentazione& p);
 public:
  Presentazione(std::string t, std::string r, unsigned p);
  std::string Titolo() const { return titolo; }
  std::string Relatore() const { return relatore; }
  unsigned Partecipanti() const { return partecipanti; }
  Data DataPresentazione() const 
  { if (schedulazione.aula == nullptr) throw std::invalid_argument("Presentazione non schedulata");
    return schedulazione.giorno; }
  unsigned OraPresentazione() const 
  { if (schedulazione.aula == nullptr) throw std::invalid_argument("Presentazione non schedulata");
    return schedulazione.ora; }
  Aula* AulaPresentazione() const { return schedulazione.aula; }
  unsigned NumInConflitto() const { return in_conflitto.size(); }
  Presentazione* PresInConflitto(unsigned i) const { return in_conflitto[i]; }
  void SetTitolo(std::string t) { titolo = t; }
  void SetRelatore(std::string r) { relatore = r; }
  void SetPartecipanti(unsigned p) { partecipanti = p; }
  void Schedula(Aula* a, Data g, unsigned o);
  void InserisciConflitto(Presentazione* p);
  void RimuoviConflitto(Presentazione* p);
  void LiberaAula() {schedulazione.aula = nullptr;}
  bool InConflitto(Presentazione* p) const { return CercaConflitto(p) != -1; }
private:
  std::string titolo, relatore;
  unsigned partecipanti;
  Schedulazione schedulazione;
  std::vector<Presentazione*> in_conflitto;
  int CercaConflitto(Presentazione* p) const;
};
#endif
