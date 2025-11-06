#include <iostream>
#include <cmath>
using namespace std;

class Poli
{
   friend Poli operator+(const Poli& p1, const Poli& p2);
   friend Poli operator-(const Poli& p1, const Poli& p2);
   friend ostream& operator<<(ostream& os, const Poli& p);
   friend istream& operator>>(istream& is, Poli& p);
   public:
      //costruttori
      Poli();
      Poli(float term, int exp);
      Poli(Poli& p);
      ~Poli();
      //selettori
      float GetTerm(const int exp) const;
      //overloading 
      Poli& operator=(const Poli& p);
      float operator()(float x);
   private:
      int dim;
      float* vet;
};