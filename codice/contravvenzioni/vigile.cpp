//File vigile.cpp
#include <iostream>
#include <stdexcept>
#include "vigile.hpp"

void Vigile::EffettuaContravvenzione(Contravvenzione* c)
{
  if (Cerca(c) != -1)
    throw std::invalid_argument("Contravvenzione gia' inserita");
  contravvenzioni.push_back(c);
}

void Vigile::EliminaContravvenzione(Contravvenzione* c)
{
  int i = Cerca(c);
  if (i == -1)
    throw std::invalid_argument("Contravvenzione assente");    
  contravvenzioni.erase(contravvenzioni.begin()+i);
}

int Vigile::Cerca(Contravvenzione* c) const
{
  for(unsigned i = 0; i < contravvenzioni.size(); i++)
    if (contravvenzioni[i] == c)
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Vigile& vig)
{
  os << " VIGILE:  " << vig.Nome()
     << "                  MATRICOLA:  " << vig.Matricola()<<std::endl;
  os << " ==============================================="
     <<  "============================ "<<std::endl;
  if(vig.contravvenzioni.size()==0)
    os << " Non ha effettuato contravvenzioni"<< std::endl;  
  else
  {
    os << " Le sue contravvenzioni sono:"<< std::endl; 
    for (unsigned i = 0; i < vig.contravvenzioni.size(); i++)
    {
	  os << *(vig.contravvenzioni[i]) << std::endl;	  
      // os << " -- NUMERO:   " << vig.contravvenzioni[i]->Numero()
         // << "     LUOGO:  " << vig.contravvenzioni[i]->Luogo()
 // << "  VEICOLO: " << vig.contravvenzioni[i]->QualeVeicolo()->Tipo()
         // << std::endl;
       // os <<"   TARGA:  "<< vig.contravvenzioni[i]->QualeVeicolo()
            // ->Targa()<<'\t'<<"  POTENZA:  "
          // << vig.contravvenzioni[i]->QualeVeicolo()->Potenza()
          // << std::endl;  
     }
  }
  os << " ==============================================="
     <<  "============================ "<<std::endl;
  return os;
}
