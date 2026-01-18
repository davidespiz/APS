// File DriverContravvenzioni.cpp
#include <iostream>
#include "vigile.hpp"

bool ComparaMotoAuto(const Vigile& v);
bool RipetiVeicolo(const Vigile& v);
void StampaStato(const Vigile& v);

int main()
{
  Vigile vig("Bartolomeo Pestalozzi","6969");
  Veicolo a1("Ferrari",30000,"Auto");
  Veicolo a2("Seat",1200,"Auto");
  Veicolo a3("Fiat",1100,"Auto");
  Veicolo m4("Ciao",900,"Moto");
  Veicolo m3("Suzuky",800,"Moto");
  Veicolo m2("Gilera",700,"Moto");
  Veicolo m1("Honda",150,"Moto");
  Contravvenzione c1(7,"Milano",&a1);
  Contravvenzione c2(6,"Torino",&m2);
  Contravvenzione c3(3,"Bologna",&m3);
  Contravvenzione c4(1,"Marte",&m4);
  Contravvenzione c5(2,"Saturno",&a3);
  Contravvenzione c6(5,"Giove",&a2);
  Contravvenzione c7(9,"Venere",&m1);
  Contravvenzione c8(4,"Roma",&a1);
 
  vig.EffettuaContravvenzione(&c1);
  vig.EffettuaContravvenzione(&c2);
  vig.EffettuaContravvenzione(&c3);
  vig.EffettuaContravvenzione(&c4);
  vig.EffettuaContravvenzione(&c5);
  vig.EffettuaContravvenzione(&c6);
  vig.EffettuaContravvenzione(&c7);
  StampaStato(vig);
  vig.EffettuaContravvenzione(&c8);
  StampaStato(vig);
  vig.EliminaContravvenzione(&c2);
  vig.EliminaContravvenzione(&c3);
  vig.EliminaContravvenzione(&c4);
  vig.EliminaContravvenzione(&c5);
  StampaStato(vig);
  vig.EliminaContravvenzione(&c1);
  vig.EliminaContravvenzione(&c8);
  vig.EliminaContravvenzione(&c6);
  vig.EliminaContravvenzione(&c7);
  StampaStato(vig);
}

bool RipetiVeicolo(const Vigile& v)
{
  for(unsigned i = 0; i < v.NumeroContravvenzioni() - 1; i++)
    for(unsigned j = i + 1; j < v.NumeroContravvenzioni(); j++)
      if(v.ContravvenzioneEffettuata(i)->QualeVeicolo() ==
         v.ContravvenzioneEffettuata(j)->QualeVeicolo())
        return true;
  return false;
}

bool ComparaMotoAuto(const Vigile& v)
{
  unsigned conta_moto = 0, conta_auto = 0;
  for(unsigned i = 0; i < v.NumeroContravvenzioni(); i++)
    {
      if(v.ContravvenzioneEffettuata(i)->QualeVeicolo()->Tipo() == "Moto")
	    conta_moto++;
      else
	    conta_auto++;
    }
  return conta_moto > conta_auto;
}

void StampaStato(const Vigile& v)
{
  std::cout << v;
  if (RipetiVeicolo(v))
    std::cout << v.Nome() << " ha dato piu' di una multa a uno stesso veicolo" << std::endl;
  else
    std::cout << v.Nome() << " non ha dato piu' di una multa a uno stesso veicolo" << std::endl;
  
  if(ComparaMotoAuto(v))
    std::cout << v.Nome() << " ha dato piu' multe alle moto"<< std::endl;
  else
    std::cout << v.Nome() << " le multe alle moto non sono maggiori di quelle delle auto" <<std::endl;
  std::cout << std::endl << "Premi invio per continuare ";
  std::cin.get();
}
