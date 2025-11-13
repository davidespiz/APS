// File Poli.cpp
#include "Poli.hpp"
#include <cmath>

Polinomio::Polinomio()
{
  v = nullptr;
  max = -1;
}

Polinomio::Polinomio(double c, int g)
{
  max = g;
  v = new double[g+1];
  for (int i = 0; i < max; i++)
    v[i] = 0.0;
  v[max] = c;
}

Polinomio::~Polinomio()
{
  delete[] v;
}

Polinomio::Polinomio(const Polinomio& p)
{
  max = p.max;
  if (max != -1)
    {
      v = new double[max+1];
      for (int i = 0; i <= max; i++)
	v[i] = p.v[i];
    }
  else
    v = nullptr;
}
 
Polinomio& Polinomio::operator=(const Polinomio& p)
{
  if (p.max != -1)
    {
      if (max != p.max)
	{
	  max = p.max;
	  delete [] v;
	  v = new double[max+1];
	}
      for (int i = 0; i <= max; i++)
	v[i] = p.v[i];
    }
  else
    {
      max = -1;
      v = nullptr;
    }
  return *this;
} 

Polinomio Polinomio::operator-() const
{
  Polinomio p = *this;
  for (int i = 0; i <= max; i++)
    p.v[i] = -p.v[i];
  return p;
}

double Polinomio::Coefficiente(int g) const
{
  if (g > max)
    return 0;
  else
    return v[g];
}

Polinomio operator+(const Polinomio& p1, const Polinomio& p2)
{
  Polinomio p;
  int i;
  if (p1.max > p2.max)
    {
      p = p1;
      for (i = 0; i <= p2.max; i++)
	p.v[i] += p2.v[i];
     } 
  else
    {
      p = p2;
      for (i = 0; i <= p1.max; i++)
	p.v[i] += p1.v[i];
   }
  return p;
}

Polinomio operator*(const Polinomio& p1, const Polinomio& p2)
{
  Polinomio p;
  int i, j;

  p.max = p1.max + p2.max;
  p.v = new double[p.max + 1];
  
  for (i = 0; i <= p.max; i++)
    p.v[i] = 0.0;

  for (i = 0; i <= p1.max; i++)
    for (j = 0; j <= p2.max; j++)
      p.v[i+j] += p1.v[i] * p2.v[j];
  return p;
}

Polinomio operator-(const Polinomio& p1, const Polinomio& p2)
{  
  Polinomio p;
  int i;
  if (p1.max > p2.max)
    {
      p = p1;
      for (i = 0; i <= p2.max; i++)
	p.v[i] -= p2.v[i];
     } 
  else
    {
      p = -p2;
      for (i = 0; i <= p1.max; i++)
	p.v[i] += p1.v[i];
   }
  return p;
}

double Polinomio::operator()(double p) const
{
  double val = 0.0;
  for (int i = 0; i <= max; i++)
    val += v[i] * pow(p,i);
  return val;
}

istream& operator>>(istream& is, Polinomio& p)
{
  char ch;
  double coef;
  int pot;

  is >> ch >> coef >> ch >> ch >> pot;
  if (!is)
    return is;
  p.max = pot;
  delete [] p.v;
  p.v = new double[pot+1];
  p.v[pot] = coef;
  for (int i = 0; i < pot; i++)
    p.v[i] = 0.0;

  while (ch != '>')
    {
      ch = is.peek();
      if (ch != '>')
	{
	  is >> ch >> coef >> ch >> ch >> pot;
	  p.v[pot] = coef;
	}
      else
	is >> ch;
    }
  return is;
}

ostream& operator<<(ostream& os, const Polinomio& p)
{
  os << '<';
  for (int i = p.max; i >= 0; i--)
    if (p.v[i] > 0.0)
      os << '+' << p.v[i] << "x^" << i;
    else if (p.v[i] < 0.0)
       os << p.v[i] << "x^" << i;     
  os << '>';
  return os;
}


