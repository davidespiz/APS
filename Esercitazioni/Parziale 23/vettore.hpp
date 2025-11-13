#include <iostream>
using namespace std;

#ifndef VETTORE
#define VETTORE

class Vettore
{
   friend ostream& operator<<(ostream& os, const Vettore& v);
   friend istream& operator>>(istream& is, Vettore& v);
   public:
      Vettore(int d);            //d dimensione vettore
      Vettore(const Vettore& v);
      ~Vettore();
      void Set(int i, float v);        //inserisce valore all'indice
      float operator[](int i) const;   //restituisce valore a i
      Vettore operator=(const Vettore& v);

   private:
      float* value;
      int* index;
      int dim;
      int term;
};

#endif