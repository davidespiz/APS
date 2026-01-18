// File pacchetto.hpp
#ifndef PACCHETTO_HPP
#define PACCHETTO_HPP
#include <iostream>
#include <string>
#include <vector>

class Pacchetto
{
  friend std::ostream& operator<<(std::ostream& os, const Pacchetto& p);
public:
  Pacchetto(std::string n, std::string d);
  std::string Nome() const { return nome; }
  std::string Descrizione() const { return descrizione; }
  Pacchetto* VediDipendenza(unsigned i) const { return dipendenze[i]; }
  unsigned Dipendenze() const { return dipendenze.size(); }
  void InserisciDipendenza(Pacchetto* p);
  void RimuoviDipendenza(Pacchetto* p);
  bool Dipendenza(Pacchetto* p) const { return CercaDipendenza(p) != -1; }
private:
  std::string nome;
  std::string descrizione; 
  std::vector<Pacchetto*> dipendenze;
  int CercaDipendenza(Pacchetto* p) const;
};
#endif
