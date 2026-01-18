// File ManipolaDate.cpp
#include <iostream>
#include <stdexcept>
#include "ManipolaDate.hpp"

bool DataValida(unsigned giorno, unsigned mese, unsigned anno)
{
  return anno >= 1 && mese >= 1 && mese <= 12 
    && giorno >=1 && giorno <= GiorniDelMese(mese,anno);
}

unsigned GiorniDelMese(unsigned mese, unsigned anno)
{
  if (mese == 4 || mese == 6 || mese == 9 || mese == 11)
    return 30;
  else if (mese == 2)
    if (Bisestile(anno))
      return 29;
    else
      return 28;
  else 
    return 31;
}         

bool Bisestile(unsigned a)
{
  if (a % 4 != 0)
    return false;
  else if (a % 100 != 0)
    return true;
  else if (a % 400 != 0)
    return false;
  else 
    return true;
}

void StampaData(unsigned giorno, unsigned mese, unsigned anno)
{
  if (DataValida(giorno,mese,anno))
    {
      cout << giorno << ' ';
      if (mese == 1) cout << "gennaio";
      else if (mese == 2) cout << "febbraio";
      else if (mese == 3) cout << "marzo";
      else if (mese == 4) cout << "aprile";
      else if (mese == 5) cout << "maggio";
      else if (mese == 6) cout << "giugno";
      else if (mese == 7) cout << "luglio";
      else if (mese == 8) cout << "agosto";
      else if (mese == 9) cout << "settembre";
      else if (mese == 10) cout << "ottobre";
      else if (mese == 11) cout << "novembre";
      else cout << "dicembre";
      cout << ", " << anno;
    }
  else
    cout << "Data non valida" << endl;
}

int ComparaDate(unsigned g1, unsigned m1, unsigned a1, 
                unsigned g2, unsigned m2, unsigned a2)
{
  if (a1 < a2)
    return -1;
  else if (a1 == a2 && m1 < m2)
    return -1;
  else if (a1 == a2 && m1 == m2 && g1 < g2)
    return -1;
  else if (a1 == a2 && m1 == m2 && g1 == g2)
    return 0;
  else 
    return 1;
}

void Scambia(unsigned& a, unsigned& b)
{
  unsigned temp = a;
  a = b;
  b = temp;
}

void InvertiDate(unsigned& g1, unsigned& m1, unsigned& a1, 
                 unsigned& g2, unsigned& m2, unsigned& a2)
{
  Scambia(g1,g2);
  Scambia(m1,m2);
  Scambia(a1,a2);
}

unsigned DistanzaTraDate(unsigned g1, unsigned m1, unsigned a1, 
                         unsigned g2, unsigned m2, unsigned a2)
{
  unsigned i = 0;
  while (ComparaDate(g1,m1,a1,g2,m2,a2) == -1)
    {
      i++;
      DataSuccessiva2(g1,m1,a1);
    }
  return i;
}
      
int DistanzaTraDateBidirezionale(unsigned g1, unsigned m1, unsigned a1, 
                         unsigned g2, unsigned m2, unsigned a2)
{
  if (ComparaDate(g1,m1,a1,g2,m2,a2) != 1)
    return DistanzaTraDate(g1,m1,a1,g2,m2,a2);
  else
    return -DistanzaTraDate(g2,m2,a2,g1,m1,a1);
}

void DataSuccessiva(unsigned& giorno, unsigned& mese, unsigned& anno)
{ 
  if (giorno < GiorniDelMese(mese, anno))
    giorno++;
  else if (mese < 12)  
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

void DataSuccessiva2(unsigned& giorno, unsigned& mese, unsigned& anno)
{ 
  assert(DataValida(giorno, mese, anno));
  if (giorno < GiorniDelMese(mese, anno))
    giorno++;
  else if (mese < 12)  
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

void DataSuccessiva3(unsigned& giorno, unsigned& mese, unsigned& anno)
{ 
  try
    {
      if(!DataValida(giorno, mese, anno))
        {
          if (anno < 1)
            throw "anno inesistente";
          if(mese < 1 || mese > 12)
            throw "mese inesistente";
          if(giorno < 1 || giorno > GiorniDelMese(mese, anno))
            throw "giorno inesistente";
        }
    }
  
  catch (char* errore)
    {
      cout << "Data non valida: " << errore  
	   << " (" << giorno << '/' << mese << '/' << anno << ')' << endl; 
    }
  
  if (giorno < GiorniDelMese(mese,anno))
    giorno++;
  else 
    if (mese < 12)  
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
