// File Mondo.cpp
#include "Mondo.hpp"

Mondo::Mondo(unsigned n)
  : scacchiera(n, std::vector<bool>(n,false))
{
  dim = n;
}

void Mondo::InizializzaCella(unsigned i, unsigned j, bool vivo)
{
  scacchiera[i][j] = vivo;
}

bool Mondo::EsisteVita() const
{
  unsigned i, j;
  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
      if (scacchiera[i][j])
	return true;
  return false;
}

void Mondo::Evolvi()
{
  std::vector<std::vector<unsigned>> num_vicini(dim,std::vector<unsigned>(dim,0));
  unsigned i, j;
  
  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
      num_vicini[i][j] = NumeroViciniVivi(i,j);

  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
      {
	if (!scacchiera[i][j] && num_vicini[i][j] == 3)
	  scacchiera[i][j] = true; // nascita della casella
	else if (scacchiera[i][j] && 
		 (num_vicini[i][j] <= 1 || num_vicini[i][j] >= 4))
	  scacchiera[i][j] = false; // morte della casella
      }  
}

unsigned Mondo::NumeroViciniVivi(unsigned ui, unsigned uj) const
{
  int h, k;
  int i = static_cast<int>(ui), 
      j = static_cast<int>(uj), 
      d = static_cast<int>(dim);

  unsigned conta = 0;
  for (h = i - 1; h <= i + 1; h++)
    for (k = j - 1; k <= j + 1; k++)
      if (h >= 0 && k >= 0 
	  && h < d && k < d && 
	  (h != i || k != j))
	if (scacchiera[h][k])
	  conta++;
  return conta;       
}

std::ostream& operator<<(std::ostream& os, const Mondo& m)
{
  unsigned i, j;

  os << m.dim << std::endl;
  for (i = 0; i <  m.dim; i++)
    {
      for (j = 0; j <  m.dim; j++)
	if (m.scacchiera[i][j])
	  os << '1';
	else
	  os << '0';
      os << std::endl;
    }
  return os;
}
  
std::istream& operator>>(std::istream& is, Mondo& m)
{
  unsigned i, j;
  char ch;
  is >> m.dim;
  m.scacchiera.resize(m.dim, std::vector<bool>(m.dim));
  for (i = 0; i <  m.dim; i++)
    {
      for (j = 0; j <  m.dim; j++)
	{
	  is >> ch; 
	  if (ch == '1')
	    m.scacchiera[i][j] = true;
	  else
	    m.scacchiera[i][j] = false;
	}
    }
  return is;
}

bool operator==(const Mondo& m1, const Mondo& m2)
{
  unsigned i, j;
  if (m1.dim != m2.dim)
    return false;
  else
    {
      for (i = 0; i < m1.dim; i++)
	for (j = 0; j < m1.dim; j++)
	  if (m1.scacchiera[i][j] != m2.scacchiera[i][j])
	    return false;
      return true;
    }
}

