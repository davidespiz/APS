// File Azienda.cpp
#include "Azienda.hpp"
using namespace std;

void Azienda::InserisciMagazzino(Magazzino* m)
{
   if (CercaMagazzino(m) != -1)
      return;
   magazzini.push_back(m);
}

void Azienda::InserisiNegozio(Negozio* n)
{
   if (CercaNegozio(n) != -1)
      return;
   negozi.push_back(n);
}

void Azienda::ChiudiMagazzino(Magazzino* m)
{
   int index = CercaMagazzino(m);
   if (index == -1)
      throw invalid_argument("Magazzino non disponibile!");
   for (unsigned i = 0; i < NumForniture(); i++)
      if (forniture[i].magazzino == m)
         throw invalid_argument("Fornitura presente!");
   m->Chiudi();
}


int Azienda::CercaMagazzino(Magazzino* m)
{
   for (unsigned i = 0; i < NumMagazzini(); i++)
      if (magazzini[i] == m)
         return i;
   return -1;
}

int Azienda::CercaNegozio(Negozio* n)
{
   for (unsigned i = 0; i < NumNegozi(); i++)
      if (negozi[i] == n)
         return i;
   return -1;
}