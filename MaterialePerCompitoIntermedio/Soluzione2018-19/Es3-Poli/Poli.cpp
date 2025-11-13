// File Poli.cpp
#include "Poli.hpp"
#include <cmath>

Polinomio::Polinomio(double c, unsigned g)
  : v(1,make_pair(g,c)) {}

double Polinomio::Coefficiente(unsigned g) const
{
  unsigned i;
  for (i = 0; i < v.size(); i++)
    if (v[i].first == g)
      return v[i].second;
  return 0.0;
}

double Polinomio::operator()(double x) const
{
  double val = 0.0;
  for (unsigned i = 0; i < v.size(); i++)
    val += v[i].second * pow(x,v[i].first);
  return val;
}

Polinomio operator+(const Polinomio& p1, const Polinomio& p2)
{
  Polinomio p;
  unsigned i1 = 0, i2 = 0;

  while (i1 < p1.v.size() && i2 < p2.v.size())
  {
    if (p1.v[i1].first == p2.v[i2].first)
      {
        p.v.push_back(make_pair(p1.v[i1].first, 
				  p1.v[i1].second + p2.v[i2].second));
        i1++;
        i2++;
      }
    else if (p1.v[i1].first < p2.v[i2].first)
      {
        p.v.push_back(p1.v[i1]);
        i1++;
      }
    else
      {
        p.v.push_back(p2.v[i2]);
        i2++;
      }
  }

  if (i1 == p1.v.size())
    {
      while (i2 < p2.v.size())
        {
          p.v.push_back(p2.v[i2]);
          i2++;
        }
    } 
  else // (i2 == p2.v.size())
    {
      while (i1 < p1.v.size())
        {
          p.v.push_back(p1.v[i1]);
          i1++;
        }
    }
  return p;
}

ostream& operator<<(ostream& os, const Polinomio& p)
{
  os << '<';
  for (int i = p.v.size()-1; i >= 0; i--)
    os << '+' << p.v[i].second << "x^" << p.v[i].first;
  os << '>';
  return os;
}

istream& operator>>(istream& is, Polinomio& p)
{ 
  char ch;
  double coef;
  int grado;

  p.v.clear();
  is >> ch;  // legge il carattere < 
  ch = is.peek();
  while (ch != '>')
  {
	is >> coef >> ch >> ch >> grado >> ch;
	p.v.push_back(make_pair(grado,coef));
  }
  if (p.v.size() == 0)
	  is >> ch;
  return is;
}


