// File versione.hpp
#ifndef VERSIONE_HPP
#define VERSIONE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Pacchetto.hpp"  
#include "../utils/Data.hpp"

class Versione
{
  friend std::ostream& operator<<(std::ostream& os, const Versione& v);
public:
  Versione(unsigned n, unsigned d, Data r, Pacchetto* p);
  unsigned Numero() const { return numero; }
  unsigned Dimensione() const { return dimensione; }
  Data Rilascio() const { return rilascio; }
  Pacchetto* VediPacchetto() const { return pacchetto; }
private:
  unsigned numero, dimensione; 
  Data rilascio;
  Pacchetto* pacchetto;
};
#endif
