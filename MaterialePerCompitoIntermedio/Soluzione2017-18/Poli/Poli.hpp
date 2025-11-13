// File Poli.hpp
#ifndef POLI_HPP
#define POLI_HPP

#include <iostream>

using namespace std;

class Polinomio
{
  friend Polinomio operator+(const Polinomio&, const Polinomio&);
    // moltiplicazione (non richiesta per l'esercitazione)
  friend Polinomio operator*(const Polinomio&, const Polinomio&); 
  friend Polinomio operator-(const Polinomio&, const Polinomio&);
  friend istream& operator>>(istream& is, Polinomio&);
  friend ostream& operator<<(ostream& os, const Polinomio&);
public:
  Polinomio();
  Polinomio(double c, int g = 0);
  Polinomio(const Polinomio&);
  ~Polinomio();
  Polinomio& operator=(const Polinomio&);
  Polinomio operator-() const; // operatore - unario (non richiesto per l'esercitazione)
  double Coefficiente(int g) const;
 // valutazione del polinomio, realizzato con l'operatore () (non richiesta per l'esercitazione)
  double operator()(double p) const; 
private:
  int max;
  double* v;
};

#endif
