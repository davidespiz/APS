// File campominato.cpp
#include <stdexcept>
#include "campominato.hpp"
#include "../utils/Random.hpp"

CampoMinato::CampoMinato(unsigned d, unsigned num_b)
{
  Casella c;
  unsigned i;
  dim = d;
  max_scoppi = num_b/2;  // arrotondato per difetto
  scoppi = 0;
  if (num_b >= dim * dim / 2)
    throw std::invalid_argument("Troppe bombe");
 
  for (i = 0; i < num_b; i++)
    {
      do 
        c.Set(Random(0,dim-1), Random(0,dim-1));
      while (CasellaProibita(c));
      bombe.push_back(c);
    }
  do 
    c.Set(Random(0,dim-1), Random(0,dim-1));
  while (CasellaProibita(c));
  tesoro = c;
}

bool CampoMinato::CasellaProibita(Casella c)
{
  return c == posizione || EstBomba(c) || c == tesoro;
}

bool CampoMinato::EstBomba(Casella c)
{
  for (unsigned i = 0; i < bombe.size(); i++)
    if (c == bombe[i])
      return true;
  return false;
}

int CampoMinato::Muovi(char dir)
{
  Casella c;
  if (toupper(dir) == 'N')
    {
      if (posizione.Riga() < dim-1)
        c.Set(posizione.Riga()+1, posizione.Colonna());
      else
        return -1;
    }
  else if (toupper(dir) == 'S')
    {
      if (posizione.Riga() > 0)
        c.Set(posizione.Riga()-1, posizione.Colonna());
      else
        return -1;
    }
  else if (toupper(dir) == 'E')
    {
      if (posizione.Colonna() < dim-1)
        c.Set(posizione.Riga(), posizione.Colonna()+1);
      else
        return -1;
    }
  else if (toupper(dir) == 'O')
    {
      if (posizione.Colonna() > 0)
        c.Set(posizione.Riga(), posizione.Colonna()-1);
      else
        return -1;
    }
  else
    throw std::domain_error("direzione inesistente");
      
  if (c == tesoro)
    return 3;
  else if (EstBomba(c))
    if (scoppi < max_scoppi - 1)
      {
        scoppi++;
        return 1;
      }
    else
      return 2;
  else
    {
      posizione = c;
      return 0;
    }
}

unsigned CampoMinato::Esplora(unsigned r)
{
  unsigned conta = 0;
  for (int i = posizione.Riga() - r; 
       i <= static_cast<int>(posizione.Riga() + r); i++)
    for (int j = posizione.Colonna() - r; 
         j <= int(posizione.Colonna() + r); j++)
      {
        if (i >= 0 && i < int(dim) && j >= 0 && j < int(dim))
          {
            if (EstBomba(Casella(i,j)))
              conta++;
          }
      }
  return conta;
}

std::ostream& operator<<(std::ostream& os, const CampoMinato& u)
{
  os << "Dimensione : " << u.dim << std::endl;
  os << "Posizione attuale: " << u.posizione << std::endl;
  os << "Tesoro : " << u.tesoro << std::endl;
  os << "Scoppi : " << u.scoppi << '/' << u.max_scoppi << std::endl;
  for (unsigned i = 0; i < u.bombe.size(); i++)
    os << "Bomba " << i << " in " << u.bombe[i] << std::endl;
  return os;
}
