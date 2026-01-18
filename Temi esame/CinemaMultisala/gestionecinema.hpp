#include <iostream>
using namespace std;

#ifndef GESTIONECINEMA_HPP
#define GESTIONECINEMA_HPP

#include "proiezione.hpp"

class GestioneCinema
{
    
   public:
      void InserisiProiezione(const Proiezione& p);
   private:
      string nome;
};

#endif 