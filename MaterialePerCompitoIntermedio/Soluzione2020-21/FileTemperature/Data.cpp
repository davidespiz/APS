// File ClasseData.cpp
#include <iostream>
#include "Data.hpp"

Data::Data()
{
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
  return anno >= 1 && anno < 10000 
      && mese >= 1 && mese <= 12 
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

ostream& operator<<(ostream& os, const Data& d)
{
  os << d.giorno << '/' << d.mese << '/' << d.anno;
  return os;
}

istream& operator>>(istream& is, Data& d)
{
  char ch;
  is >> d.giorno >> ch >> d.mese >> ch >> d.anno;
  return is;
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

Data Data::operator+(int n) const
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

bool operator==(const Data& d1, const Data& d2)
{
  return d1.giorno == d2.giorno 
      && d1.mese == d2.mese 
      && d1.anno == d2.anno;
}

bool operator<(const Data& d1, const Data& d2)
{
  return d1.anno < d2.anno
    || (d1.anno == d2.anno && d1.mese < d2.mese)
    || (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno < d2.giorno);
}

int operator-(Data d1, Data d2)
{
  int distanza = 0;
  if (d2 < d1)
    {
      while (d2 < d1)
        {
          ++d2;
          distanza++;	   
        }
    }
  else  
    {
      while (d1 < d2)
        {
          ++d1;
          distanza--;		 
        }
    }	  
  return distanza;	
}

