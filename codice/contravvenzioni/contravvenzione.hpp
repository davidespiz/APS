//File contravvenzione.hpp
#ifndef CONTRAVVENZIONE_HPP
#define CONTRAVVENZIONE_HPP
#include <string>
#include "veicolo.hpp"

class Contravvenzione
{
  friend std::ostream& operator<<(std::ostream& os, const Contravvenzione& c);
public:
  Contravvenzione(unsigned n, std::string l, Veicolo* v)
    : luogo(l)
  { numero = n;  veicolo = v; }
  std::string Luogo() const { return luogo; }
  unsigned Numero()const { return numero; }
  Veicolo* QualeVeicolo() const { return veicolo; }
private:
  std::string luogo;
  unsigned numero;
  Veicolo* veicolo;
};

inline std::ostream& operator<<(std::ostream& os, const Contravvenzione& c)
{
	os << c.numero << " [" << c.luogo << ", " << *(c.veicolo) << "]";
	return os;
}

#endif
