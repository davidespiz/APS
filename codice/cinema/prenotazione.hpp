// File prenotazione.hpp
#ifndef PRENOTAZIONE_HPP
#define PRENOTAZIONE_HPP
#include <string>
#include <iostream>

class Prenotazione
{
  friend std::ostream& operator<<(std::ostream& os, const Prenotazione& p);
public:
  Prenotazione(std::string n, unsigned posti);
  std::string NomePrenotante() const { return nome_prenotante; }
  unsigned Posti() const { return posti; }
private:
  std::string nome_prenotante;
  unsigned posti;
};
#endif
