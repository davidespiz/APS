#include <iostream>
using namespace std;

#ifndef PRENOTAZIONE_HPP
#define PRENOTAZIONE_HPP

class Prenotazione
{
   friend ostream& operator<<(ostream& os, const Prenotazione& p);
   public:
      Prenotazione(string nome_p, int num_p);
      string NomePrenotante() const {return nome_prenotante;}
      int Numero_posti() const {return numero_posti;}

   private:
      string nome_prenotante;
      int numero_posti;
};
#endif