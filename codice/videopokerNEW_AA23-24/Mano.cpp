// File Mano.cpp
#include "Mano.hpp"
#include <cassert>

Mano::Mano(Mazzo* mazzo)
  : carte(5)
{ 
  if (mazzo->NUM_PACCHETTI != 1)
    throw logic_error("Il mazzo deve avere un solo pacchetto!"); 
  mazzo_utilizzato = mazzo;
}

void Mano::Distribuisci()
{ 
  for (unsigned i = 0; i < 5; i++)
    carte[i] = mazzo_utilizzato->PescaCarta();
}

void Mano::CambiaCarta(unsigned i)
{ 
  carte[i] = mazzo_utilizzato->PescaCarta();
}

Punto Mano::Valuta() const
{ 
  vector<unsigned> conta_valori(mazzo_utilizzato->NUM_VALORI,0), 
    conta_semi(mazzo_utilizzato->NUM_SEMI,0);
  pair<unsigned,unsigned> max;
  Conta(conta_semi,conta_valori);
  max = CercaMassimi(conta_valori);
  switch (max.first)
    {
    case 4:
      return Punto::poker;
    case 3:
      if (max.second == 2)
        return Punto::full;
      else 
        return Punto::tris;
    case 2:  
      if (max.second == 2)
        return Punto::doppia_coppia;
      else 
	  {
        if (CoppiaVestita(conta_valori))
		  return Punto::coppia_vestita;
	    else
          return Punto::coppia;
	  }
    default:
      if (Scala(conta_valori))
        if (Colore(conta_semi))
		{
		  if (conta_valori[0] == 1 && conta_valori[1] == 1) // scala reala con AK... (non 5432A)
		    return Punto::scala_reale_massima;
		  else
            return Punto::scala_reale;
		}
        else 
          return Punto::scala;
      else
        if (Colore(conta_semi))
          return Punto::colore;
        else 
          return Punto::niente;
    }
}

void Mano::Conta(vector<unsigned>& semi, vector<unsigned>& valori) const
{ 
  for (unsigned i = 0; i < 5; i++)
    { 
      semi[static_cast<unsigned>(carte[i].SemeCarta())]++;
      valori[static_cast<unsigned>(carte[i].ValoreCarta())]++;
    }
}

pair<unsigned,unsigned> Mano::CercaMassimi(const vector<unsigned> & valori) const
{ 
  pair<unsigned,unsigned> max = make_pair(0,0);
  for (unsigned i = 0; i < mazzo_utilizzato->NUM_VALORI; i++)
    if (valori[i] > max.first)
      { 
        max.second = max.first;
        max.first = valori[i];
      }
    else if (valori[i] > max.second)
      max.second = valori[i];
  return max;
}

bool Mano::CoppiaVestita(vector<unsigned>& valori) const
{
  return valori[0] == 2 || valori[1] == 2 || valori[2] == 2 || valori[3] == 2;
}

bool Mano::Scala(vector<unsigned>& valori) const
{ 
  unsigned v;
  for (v = mazzo_utilizzato->NUM_VALORI-1; valori[v] == 0; v--) 
    ; // cerca il valore piu' alto della mano      
  if (valori[v] > 1 || v < 4)
    return false; // se ci sono carte uguali (valori[v] > 1) oppure 
  // se v e' uno degli ultimi 4 valori (v  < 4) allora non c'e' scala
  if (ScalaMinima(valori)) // La scala minima 5432A è valutata a parte
	  return true;
  int carte_da_trovare = 4;
  while (carte_da_trovare > 0)
    { v--;
      if (valori[v] != 1)
        return false;
      else 
        carte_da_trovare--;
    }
  return true;
}

bool Mano::ScalaMinima(vector<unsigned>& v) const
{
  return v[0] == 1 && v[9] == 1 && v[10] == 1&& v[11] == 1 && v[12] == 1;
}

bool Mano::Colore(vector<unsigned>& semi) const
{ for (unsigned s = 0; s < mazzo_utilizzato->NUM_SEMI; s++)
    if (semi[s] == 5)
      return true;
  return false;
}

string Mano::NomePunto(Punto p) const
{ 
  switch (p) 
    {
    case Punto::niente: return "niente";
    case Punto::coppia: return "coppia";
    case Punto::coppia_vestita: return "coppia vestita";
    case Punto::doppia_coppia: return "doppia coppia";
    case Punto::tris: return "tris";
    case Punto::scala: return "scala";
    case Punto::full: return "full";
    case Punto::colore: return "colore";
    case Punto::poker: return "poker";
    case Punto::scala_reale: return "scala reale";
    case Punto::scala_reale_massima: return "scala reale massima";
	default: return "ignoto";
    }
}

ostream& operator<<(ostream& os, const Mano& m)
{ 
  os << endl;
  for (unsigned i = 1; i <= 5; i++)
    os << i << ": " << m.carte[i-1] << endl;
  os << "Punto: " << m.NomePunto(m.Valuta()) << endl;
  return os;
}
