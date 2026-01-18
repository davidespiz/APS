#include <iostream>
using namespace std;

#ifndef CARTA_HPP
#define CARTA_HPP 

enum class Seme {cuori, quadri, fiori, picche};
enum class Valore {asso, re, donna, fante, dieci, nove, otto, sette, 
             sei, cinque, quattro, tre, due};

class Carta
{
   public:
      Carta(Seme s = Seme::cuori, Valore v = Valore::asso);
      string NomeSeme() const;
      string NomeValore() const;
   private:
      Seme seme;
      Valore valore;
};

#endif