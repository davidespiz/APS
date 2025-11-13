// File Poli.hpp
#ifndef POLI_HPP
#define POLI_HPP

#include <iostream>
#include <vector>

using namespace std;

class Polinomio
{
  friend Polinomio operator+(const Polinomio&, const Polinomio&);
  friend ostream& operator<<(ostream& os, const Polinomio&);
  friend istream& operator>>(istream& is, Polinomio& p);
public:
  Polinomio() {}
  Polinomio(double c, unsigned g = 0);
  double Coefficiente(unsigned g) const;
  double operator()(double x) const;
private:
  vector<pair<unsigned,double>> v;
};

#endif
