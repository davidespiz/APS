//file noleggio.cpp
#include "noleggio.hpp"

Noleggio::Noleggio(CopiaFilm* cp, Cliente* c)
  :inizio()
{
  //costruisci un oggetto rappresentante un video noleggiato e non ancora restituito
  restituito = false;
  copia = cp;
  cliente = c;
  addebito = 0;
}

void Noleggio::Restituisci(unsigned t)
{ 
  restituzione = Data();
  restituito = true;
  addebito = t * (restituzione - inizio + 1);
}

std::ostream& operator<<(std::ostream& os, const Noleggio& n)
{
  os << "Noleggio della copia numero " << n.copia->Numero() << " del film: " << n.copia->VediFilm()->Titolo() << std::endl
     << "del cliente con tessera " << n.cliente->NTessera() << std::endl
     << "dal giorno " << n.inizio << std::endl;
	 
  if (n.restituito)
    os << "al giorno " << n.restituzione << std::endl << "con addebito di euro " << n.addebito << std::endl;
  else
    os << "e tuttora in noleggio." << std::endl;
	
  return os;
}

