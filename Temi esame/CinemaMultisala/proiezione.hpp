#include <iostream>
using namespace std;

#ifndef PROIEZIONE_HPP
#define PRIOEZIONE_HPP

#include "orario.hpp"

class Proiezione
{
   public: 
      Proiezione(Orario i, Orario f);
      Orario OraInizio() const {return ora_inizio;}
      Orario OraFine() const {return ora_fine;}

   private:
      Orario ora_inizio;
      Orario ora_fine;

};

#endif