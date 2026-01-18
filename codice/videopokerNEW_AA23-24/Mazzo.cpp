// File Mazzo.cpp
#include <cassert>
#include "Mazzo.hpp"

Mazzo::Mazzo(unsigned p)
  : NUM_VALORI(13), NUM_SEMI(4), 
    NUM_CARTE_PACCHETTO(NUM_VALORI * NUM_SEMI), NUM_PACCHETTI(p)
{
  Rimescola();
}

Carta Mazzo::PescaCarta()
{ 
  if (mazzo.size() == 0)
	 throw logic_error("Mazzo vuoto!");
  Carta carta = mazzo.back();   // mazzo[mazzo.size()-1]
  mazzo.pop_back();
  return carta;
}

void Mazzo::Rimescola()
{ // ricrea il mazzo completo (con NUM_PACCHETTI copie di ogni carta)
  unsigned i, j, k = 0;
  // crea il mazzo ordinato
  mazzo.resize(NUM_CARTE_PACCHETTO * NUM_PACCHETTI);
  for (i = 0; i < NUM_CARTE_PACCHETTO; i++)
	for (j = 0; j < NUM_PACCHETTI; j++)
	{
	   mazzo[k] = Carta(static_cast<Seme>(i/NUM_VALORI), 
	                    static_cast<Valore>(i%NUM_VALORI));
       k++;
    }	
  // mescola in mazzo (Fisher-Yates shuffle, 1938)
  for (i = 0; i < mazzo.size() - 1; i++)
  {
	 j = Random(i, mazzo.size() - 1);
	 swap(mazzo[i],mazzo[j]);
  }
}

ostream& operator <<(ostream& os, const Mazzo& m)
{ 
  os << "Numero di carte : " << m.mazzo.size() << endl;
  for (unsigned i = 0; i < m.mazzo.size(); i++)
     os << m.mazzo[i] << endl;
  return os;
}
