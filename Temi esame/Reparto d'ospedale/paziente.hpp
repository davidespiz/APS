// File Paziente.hpp
#ifndef PAZIENTE_HPP
#define PAZIENTE_HPP
#include <iostream>

using namespace std;

enum class Genere {FEMMINA, MASCHIO};

class Paziente
{ // classe stub: contiene solo il nome e il genere
  friend ostream& operator<<(ostream& os, const Paziente& p);
public:
  Paziente(string n, Genere g) : nome(n) { genere = g; }
  string Nome() const { return nome; }
  Genere GenerePaziente() const { return genere; }
private:
  string nome;
  Genere genere;
};

inline ostream& operator<<(ostream& os, const Paziente& p)
{
  os << p.nome << " (" << (p.genere == Genere::FEMMINA ? 'f' : 'm') << ")";
  return os;
};

#endif
