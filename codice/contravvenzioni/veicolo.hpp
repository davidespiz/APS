//File veicolo.hpp
#ifndef VEICOLO_HPP
#define VEICOLO_HPP
#include <string>

class Veicolo
{
  friend std::ostream& operator<<(std::ostream& os, const Veicolo& v);
public:
  Veicolo(std::string n, unsigned p, std::string t)
    :  targa(n), tipo(t)
  { potenza = p; }
  std::string Targa() const { return targa; }
  unsigned Potenza() const { return potenza; }
  std::string Tipo() const { return tipo; }
private:
  std::string targa;
  unsigned potenza;
  std::string tipo;
};

inline std::ostream& operator<<(std::ostream& os, const Veicolo& v)
{
	os << v.targa << " (" << v.potenza << "Kw) " << v.tipo;
	return os;
}

#endif
