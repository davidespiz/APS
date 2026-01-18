// File Carta.hpp
#ifndef CARTA_HPP
#define CARTA_HPP
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Seme {cuori, quadri, fiori, picche};
enum class Valore {asso, re, donna, fante, dieci, nove, otto, sette, 
             sei, cinque, quattro, tre, due};

class Carta
{ friend ostream& operator<<(ostream&, const Carta&);
 public:
  Carta(Seme s = Seme::cuori, Valore v = Valore::asso);
  Valore ValoreCarta() const { return valore; }
  Seme SemeCarta() const { return seme; }
  void SetValore(Valore v) { valore = v; }
  void SetSeme(Seme s) { seme = s; }
  string NomeValore() const;
  string NomeSeme() const; 
private:
  Seme seme;
  Valore valore;
};
#endif
