#include <iostream>
using namespace std;

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
   friend istream& operator>>(istream& is, Data& d);
   friend ostream& operator<<(ostream& os, const Data& d);
   friend int operator-(const Data& d1, const Data& d2);
   friend bool operator<(const Data& d1, const Data& d2);
   friend bool operator==(const Data& d1, const Data& d2);
   public:
      Data();
      Data(unsigned g, unsigned m, unsigned a);
      void operator++();
      void operator--();
   private:
      unsigned giorno;
      unsigned mese; 
      unsigned anno;
      bool Valida() const;
      bool Bisestile() const;
      unsigned GiorniDelMese() const;      
};
#endif