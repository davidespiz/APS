// File Anagrafe.cpp
#include <stdexcept>
#include "Anagrafe.hpp"

void Anagrafe::InserisciPersona(Persona* p)
{
  if (CercaPersona(p) != -1)
    throw std::invalid_argument("Persona gia' inserita");
  if (CercaComune(p->ComuneResidenza()) == -1)
    throw std::invalid_argument("Comune inesistente");
  persone.push_back(p); 
}

void Anagrafe::InserisciNuovoNato(Persona* p, Persona* pm, Persona* pp)
{
  InserisciPersona(p);
  InserisciGenitoreFiglio(pm,p);
  InserisciGenitoreFiglio(pp,p);
}

void Anagrafe::EliminaPersona(Persona* p)
{// Elimina una persona e rimuove tutti i suoi legami
  int i = CercaPersona(p);
  if (i == -1)
    throw std::invalid_argument("Persona sconosciuta");
  RimuoviLegamiPersona(p);
  persone.erase(persone.begin()+i);
}

void Anagrafe::RimuoviLegamiPersona(Persona* p)
{
  if (p->Coniuge() != nullptr)
    p->RimuoviConiuge();
  if (p->Padre() != nullptr)
    p->RimuoviPadre();
  if (p->Madre() != nullptr)
    p->RimuoviMadre();
  for (int j = p->NumFigli() - 1; j >= 0 ; j--)
    { // Elimina al rovescio, altrimenti le locazioni si spostano
      p->RimuoviFiglio(p->Figlio(j));
    }
}

void Anagrafe::InserisciComune(Comune* c)
{
  if (CercaComune(c) != -1)
    throw std::invalid_argument("Comune gia' inserito");
  comuni.push_back(c);
}

void Anagrafe::EliminaComune(Comune* c)
{ // Elimina un comune
  int i = CercaComune(c);
  if (i == -1)
    throw std::invalid_argument("Comune assente");
  comuni.erase(comuni.begin()+i);
}

void Anagrafe::EliminaComuneESuoiResidenti(Comune* c)
{ // Elimina un comune e tutti i suoi legami
  unsigned j = 0;
  int i = CercaComune(c);
  if (i == -1)
    throw std::invalid_argument("Comune assente");

  while(j < persone.size())
    {
      if (persone[j]->ComuneResidenza() == comuni[i])
        {
          RimuoviLegamiPersona(persone[j]);
          persone.erase(persone.begin() + j);
        }
      else
        j++;
    }
  comuni.erase(comuni.begin()+i);
}

void Anagrafe::InserisciConiugio(Persona* pmo, Persona* pma)
{
  if (CercaPersona(pmo) == -1 || CercaPersona(pma) == -1)
    throw std::invalid_argument("Persona assente");
  pmo->AggiungiConiuge(pma);
}

void Anagrafe::InserisciDivorzio(Persona* pmo, Persona* pma)
{
  if (CercaPersona(pmo) == -1 || CercaPersona(pma) == -1)
    throw std::invalid_argument("Persona assente");
  if (pmo->Coniuge() != pma)
    throw std::invalid_argument("Matrimonio assente");
  pmo->RimuoviConiuge();
}

void Anagrafe::InserisciGenitoreFiglio(Persona* pg, Persona* pf)
{
  if (CercaPersona(pg) == -1 || CercaPersona(pf) == -1)
    throw std::invalid_argument("Persona assente");
  pg->AggiungiFiglio(pf);
}

void Anagrafe::StampaCertificato(Persona* p) const
{
  int i = CercaPersona(p);
  if (i == -1)
    throw std::invalid_argument("Persona assente");
  p->StatoDiFamiglia();
}

void Anagrafe::StampaVotanti(Data elezioni) const
{
  unsigned i, j = 1;
  for (i = 0; i < persone.size(); i++)
    {
      if (elezioni.Anno() > persone[i]->DataNascita().Anno() + 18
          || (elezioni.Anno() == persone[i]->DataNascita().Anno() + 18
              && elezioni.Mese() > persone[i]->DataNascita().Mese())
          || (elezioni.Anno() == persone[i]->DataNascita().Anno() + 18
              && elezioni.Mese() == persone[i]->DataNascita().Mese()
              && elezioni.Giorno() >= persone[i]->DataNascita().Giorno()))
	{
	  std::cout << "---------------------------------------------" << std::endl;
	  std::cout << "Elettore " << j << " : " << std::endl; 
	  persone[i]->StatoDiFamiglia();
	  j++;
	}
    }
}      

int Anagrafe::CercaPersona(Persona* p) const
{
  for(unsigned i = 0; i < persone.size(); i++)
    if (p == persone[i])
      return i;
  return -1;
}

int Anagrafe::CercaComune(Comune* c) const
{
  for(unsigned i = 0; i < comuni.size(); i++)
    if (c == comuni[i])
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Anagrafe& a)
{
  unsigned i;
  os << "-------------- Stato Anagrafe ------------------" << std::endl;
  os << "Comuni: " << std::endl;
  for (i = 0; i < a.comuni.size(); i++)
    os << *(a.comuni[i]) << std::endl;
  os << std::endl;

  os << "Persone: " << std::endl;
  for (i = 0; i < a.persone.size(); i++)
    os << *(a.persone[i]) << ", residente a " 
       << a.persone[i]->ComuneResidenza()->Nome() << std::endl;
  os << std::endl;

  os << "Coppie: " << std::endl;
  for (i = 0; i < a.persone.size(); i++)
    {
      if (a.persone[i]->Coniuge() != nullptr && a.persone[i]->Sesso() == 'f')
        os << '-' << a.persone[i]->Nome() << " " 
               << a.persone[i]->Cognome() << " e "
           << a.persone[i]->Coniuge()->Nome() << " " 
           << a.persone[i]->Coniuge()->Cognome() << std::endl;
    }
  os << std::endl;

  os << "Genitore-Figlio: " << std::endl;
  for (i = 0; i < a.persone.size(); i++)
    {
      if (a.persone[i]->Padre() != nullptr)
        os << '-' << a.persone[i]->Padre()->Nome() << " " 
           << a.persone[i]->Padre()->Cognome() << " padre di "
           << a.persone[i]->Nome() << " " << a.persone[i]->Cognome() << std::endl;
      if (a.persone[i]->Madre() != nullptr)
        os << '-' << a.persone[i]->Madre()->Nome() << " " 
           << a.persone[i]->Madre()->Cognome() << " madre di "
           << a.persone[i]->Nome() << " " << a.persone[i]->Cognome() << std::endl;
   }

  return os;
}
