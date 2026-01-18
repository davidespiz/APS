#include "Carta.hpp"

Carta::Carta(Seme s, Valore v)
{
   seme = s;
   valore = v;
}

string Carta::NomeSeme() const
{
   switch (seme) 
   {
      case Seme::picche: return "picche";
      case Seme::fiori: return "fiori";
      case Seme::quadri: return "quadri";
      case Seme::cuori: return "cuori";
      default: return "ignoto"; // caso impossibile (per evitare il warning)
   }
}

string Carta::NomeValore() const
{
   switch (valore) 
   {
      case Valore::due: return "due"; 
      case Valore::tre: return "tre"; 
      case Valore::quattro: return "quattro"; 
      case Valore::cinque: return "cinque"; 
      case Valore::sei: return "sei"; 
      case Valore::sette: return "sette"; 
      case Valore::otto: return "otto"; 
      case Valore::nove: return "nove"; 
      case Valore::dieci: return "dieci"; 
      case Valore::fante: return "fante"; 
      case Valore::donna: return "donna"; 
      case Valore::re: return "re"; 
      case Valore::asso: return "asso"; 
      default: return "ignoto"; // caso impossibile (per evitare il warning)
   }
}