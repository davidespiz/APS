#include <iostream>
using namespace std;
#include "reparto.hpp"

int StanzeLibereInData(Reparto r, const Data& d);

int main()
{
   Reparto r("Cardiologia");
  Data oggi(28,1,2020);
  
  Paziente 
    p1("Mario", Genere::MASCHIO), p2("Paola", Genere::FEMMINA), 
    p3("Luisa", Genere::FEMMINA), p4("Giovanni", Genere::MASCHIO), 
    p5("Francesca", Genere::FEMMINA), p6("Anna", Genere::FEMMINA),
    p7("Matteo", Genere::MASCHIO), p8("Giulia", Genere::FEMMINA), 
    p9("Chiara", Genere::FEMMINA), p10("Sara", Genere::FEMMINA), 
    p11("Irene", Genere::FEMMINA);
  
  r.AggiungiStanza(4,TipoStanza::SINGOLO_GENERE);
  r.AggiungiStanza(6,TipoStanza::SOLO_UOMINI);
  r.AggiungiStanza(4,TipoStanza::SOLO_DONNE);
  r.AggiungiStanza(3,TipoStanza::MISTA);
  
  r.AmmettiPaziente(&p1, oggi+3);
  r.AmmettiPaziente(&p2, oggi+4);
  r.AmmettiPaziente(&p3, oggi+5);
  r.AmmettiPaziente(&p4, oggi+6);
  r.AmmettiPaziente(&p5, oggi+6);
  r.AmmettiPaziente(&p6, oggi+7);
  r.AmmettiPaziente(&p7, oggi+2);
  r.AmmettiPaziente(&p8, oggi+3);
  r.AmmettiPaziente(&p9, oggi+4);
  r.AmmettiPaziente(&p10, oggi+2);
  r.DimettiPaziente(&p6);
  if(!r.AmmettiPaziente(&p11, oggi+4))
    cout << "Paziente non ammesso: " << p11 << endl;
  r.IsolaPaziente(&p7,4);
  //cout << r << endl;
  
  r.DimettiPaziente(&p8);
  r.DimettiPaziente(&p9);
  r.DimettiPaziente(&p10);

  r.IsolaPaziente(&p5,20);
  //cout << r << endl;

  for (unsigned i = 0; i < 10; i++)
    cout << "Le stanze libere il " << oggi+i << " sono " << StanzeLibereInData(r,oggi+i) << endl;
  
  return 0;	
}

int StanzeLibereInData(Reparto r, const Data& d)
{
   int numLibere = 0;
   for (unsigned i = 0; i < r.NumStanze(); i++)
   {
      if (r.GetStanza(i).NumRicoverati() == 0)
         numLibere++;
      else
      {
         unsigned numDimessi = 0, k;
         for (k = 0; k < r.GetStanza(i).NumRicoverati(); k++)
            if (r.GetStanza(i).GetDimissione(k) < d)
               numDimessi++;
         if (numDimessi == k)
            numLibere++;
      }
   }
   return numLibere;
}