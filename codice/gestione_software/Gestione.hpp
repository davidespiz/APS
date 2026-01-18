// File gestione.hpp
#ifndef GESTIONE_HPP
#define GESTIONE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Pacchetto.hpp"  
#include "Versione.hpp"  

class Gestione
{
  friend std::ostream& operator<<(std::ostream& os, const Gestione& g);
public:
  Gestione(std::string n, unsigned st);
  std::string Nome() const { return nome; }
  unsigned SpazioDisponibile() const { return spazio_disponibile; }
  unsigned SpazioTotale() const { return spazio_totale; }
  Pacchetto* VediPacchettoDisponibile(unsigned i) const 
    { return pacchetti_disponibili[i]; }
  Versione* VediVersioneDisponibile(unsigned i) const 
    { return versioni_disponibili[i]; }
  Versione* VediVersioneInstallata(unsigned i) const 
    { return versioni_installate[i]; }
  unsigned PacchettiDisponibili() const { return pacchetti_disponibili.size(); }
  unsigned VersioniDisponibili() const { return versioni_disponibili.size(); }
  unsigned VersioniInstallate() const { return versioni_installate.size(); }
  void InserisciPacchettoDisponibile(Pacchetto* p);
  void InserisciVersioneDisponibile(Versione* v);
  void InstallaVersione(Versione* v);
  void RimuoviVersione(Versione* v);
private:
  std::string nome;
  unsigned spazio_disponibile, spazio_totale; 
  std::vector<Pacchetto*> pacchetti_disponibili;
  std::vector<Versione*> versioni_disponibili, versioni_installate;
  int CercaPacchettoDisponibile(Pacchetto* p) const;
  int CercaPacchettoInstallato(Pacchetto* p) const;
  int CercaVersioneInstallata(Versione* v) const;
};
#endif
