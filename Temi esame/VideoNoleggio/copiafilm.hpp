using namespace std;
#include "data.hpp"

#ifndef COPIAFILM_HPP
#define COPIAFILM_HPP

#include <iostream>

class CopiaFilm 
{
   private:
      string Supporto() const {return supporto;}
      Data Acquisizione() const {return acquisizione;}
      int Numero() const {return numero;}
   public:
      string supporto;
      Data acquisizione;
      int numero;
};
#endif