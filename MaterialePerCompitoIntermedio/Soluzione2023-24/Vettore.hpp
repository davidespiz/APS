// File Vettore.hpp
#ifndef VETTORE_HPP
#define VETTORE_HPP
#include <iostream>

using namespace std;

class Vettore
{
  friend ostream& operator<<(ostream& os, const Vettore& v); 
  friend istream& operator>>(istream& is, Vettore& v); 
public:
  Vettore(unsigned d = 100);
  Vettore(const Vettore&);
  ~Vettore();
  Vettore& operator=(const Vettore&); 
  float operator[](unsigned i) const;
  void Set(unsigned i, float v); 
 private:
  float* val;     // vettore dei valori interi
  unsigned* ind;  // vettore degli indici
  unsigned num;   // numero di elementi presenti
  unsigned dim;   // dimensione dei vettori	
  int CercaElemento(unsigned i) const;
};
#endif