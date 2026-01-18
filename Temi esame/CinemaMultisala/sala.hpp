#include <iostream>
using namespace std;

#ifndef SALA_HPP
#define SALA_HPP

class Sala
{
   friend ostream& operator<<(ostream& os, const Sala& s);
   public:
      Sala(string n, int p);
   private:
      string nome;
      int posti;
};

#endif 