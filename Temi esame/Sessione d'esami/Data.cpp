// File data.cpp
#include <iostream>
#include "Data.hpp"

Data::Data()
{ // data convezionale
  giorno = 1;
  mese = 1;
  anno = 1970;
}

Data::Data(unsigned g, unsigned m, unsigned a)
{
  giorno = g;
  mese = m;
  anno = a;
  if (!Valida())
    {
      giorno = 1;
      mese = 1;
      anno = 1970;
    }
}

bool Data::Valida() const
{
  return anno >=1 && mese >= 1 && mese <= 12 
    && giorno >= 1 && giorno <= GiorniDelMese();
}

unsigned Data::GiorniDelMese() const
{
  if (mese == 4 || mese == 6 || mese == 9 || mese == 11)
    return 30;
  else if (mese == 2)
    if (Bisestile())
      return 29;
    else
      return 28;
  else 
    return 31;
}         

bool Data::Bisestile() const
{
  if (anno % 4 != 0)
    return false;
  else if (anno % 100 != 0)
    return true;
  else if (anno % 400 != 0)
    return false;
  else 
    return true;
}

std::istream& operator>>(std::istream& is, Data& d)
{
  char ch;
  is >> d.giorno >> ch >> d.mese >> ch >> d.anno;
  if (!d.Valida())
    {
      d.giorno = 1;
      d.mese = 1;
      d.anno = 1970;
    }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Data& d)
{
  os << d.giorno << '/' << d.mese << '/' << d.anno;
  return os;
}

void Data::operator--()
{ 
  if (giorno != 1)
    giorno--;
  else 
    if (mese != 1)  
      { 
        mese--;
        giorno = GiorniDelMese();
      }
    else
      { 
        anno--;
        mese = 12;
        giorno = GiorniDelMese();
      }
}

void Data::operator++()
{ 
  if (giorno != GiorniDelMese())
    giorno++;
  else 
    if (mese != 12)  
      { 
        giorno = 1;
        mese++;
      }
    else
      { 
        giorno = 1;
        mese = 1;
        anno++;
      }
}

void Data::operator+=(int n)
{
  int i;
  if (n > 0)
    for (i = 0; i < n; i++)
      ++(*this);
  else
    for (i = 0; i < -n; i++)
      --(*this);
}

Data Data::operator+(int n)
{
  Data d = *this;
  
  int i;
  if (n > 0)
    for (i = 0; i < n; i++)
      ++d;
  else
    for (i = 0; i < -n; i++)
      --d;
  return d;
}

int operator-(const Data& d1, const Data& d2)
{
  int conta = 0;
  Data d;
  if (d1 <= d2)
    {
      d = d1;
      while (d != d2)
	{
	  ++d;
	  conta--;
	}
    }
  else
    {
      d = d2;
      while (d != d1)
	{
	  ++d;
	  conta++;
	}
    }
  return conta;
}

bool operator==(const Data& d1, const Data& d2)
{
  return d1.giorno == d2.giorno && d1.mese == d2.mese && d1.anno == d2.anno;
}

bool operator!=(const Data& d1, const Data& d2)
{
  return d1.giorno != d2.giorno || d1.mese != d2.mese || d1.anno != d2.anno;
}

bool operator<(const Data& d1, const Data& d2)
{
  return (d1.anno < d2.anno) 
    || (d1.anno == d2.anno && d1.mese < d2.mese) 
    || (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno < d2.giorno); 
}

bool operator<=(const Data& d1, const Data& d2)
{
  return (d1.anno < d2.anno) 
    || (d1.anno == d2.anno && d1.mese < d2.mese) 
    || (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno <= d2.giorno); 
}

bool operator>(const Data& d1, const Data& d2)
{
  return (d1.anno > d2.anno) 
    || (d1.anno == d2.anno && d1.mese > d2.mese) 
    || (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno > d2.giorno); 
}

bool operator>=(const Data& d1, const Data& d2)
{
  return (d1.anno > d2.anno) 
    || (d1.anno == d2.anno && d1.mese > d2.mese) 
    || (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno >= d2.giorno); 
}

void Data::operator=(const Data& d)
{
  giorno = d.Giorno();
  mese = d.Mese();
  anno = d.Anno();
}