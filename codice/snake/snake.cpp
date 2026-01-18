// File snake.cpp
#include <stdexcept>
#include "snake.hpp"

Snake::Snake(unsigned n, unsigned k)
  : corpo(k)
{
  unsigned i;
  if (k >= 2*n || k > 9)
    throw std::domain_error("Serpente troppo lungo per la scacchiera");
  vivo = true;
  dim = n;
  if (k <= n) 
    {// si posiziona lo snake sulla prima riga (testa in 0,0)
      for (i = 0; i < k; i++)
        corpo[i] = Casella(0,i);
    }
  else
    {// si posiziona lo snake ad L sulla prima riga (testa in 0,0) 
     // e l'ultima colonna
      for (i = 0; i < n; i++)
        corpo[i] = Casella(0,i);
      for (; i < k; i++)
        corpo[i] = Casella(i+1-n,n-1);
    }
}

void Snake::Muovi(char dir)
{
  unsigned presenza;
  Casella testa = corpo[0];

  if (toupper(dir) == 'S')
    {
      if (testa.Riga() < dim-1)
        testa.Set(testa.Riga()+1, testa.Colonna());
      else
        vivo = false;
    }
  else if (toupper(dir) == 'N')
    {
      if (testa.Riga() > 0)
        testa.Set(testa.Riga()-1, testa.Colonna());
      else
        vivo = false;
    }
  else if (toupper(dir) == 'E')
    {
      if (testa.Colonna() < dim-1)
        testa.Set(testa.Riga(), testa.Colonna()+1);
      else
        vivo = false;
    }
  else if (toupper(dir) == 'O')
    {
      if (testa.Colonna() > 0)
        testa.Set(testa.Riga(), testa.Colonna()-1);
      else
        vivo = false;
    }
  else
    throw std::invalid_argument("direzione inesistente");
  if (vivo)
    { // verifichiamo ora se la nuova posizione della testa e' occupata
      presenza = Presenza(testa); 
      if (presenza == 0 || presenza == corpo.size()) 
        { // se il movimento e' verso la posizione della coda, si puo' andare
          corpo.pop_back();
          corpo.insert(corpo.begin(), testa);
        }
      else
        vivo = false;
    }
}

unsigned Snake::Presenza(Casella c) const
{ // restituisce 0 se la casella c e' vuota, 
  // 1, 2, ... se c'e' un pezzo del serpente
  unsigned i;
  for (i = 0; i < corpo.size(); i++)
    if (corpo[i] == c)
      return i+1;
  return 0;
}

std::ostream& operator<<(std::ostream& os, const Snake& sn)
{
  unsigned i, j, p;

  os << "Dimensioni: scacchiera = " << sn.dim << ", serpente = " 
     << sn.corpo.size() << std::endl;
  for (i = 0; i < sn.dim; i++)
    {
      for (j = 0; j < sn.dim; j++)
        {
          p = sn.Presenza(Casella(i,j));        
          if (p == 0)
            os << '.';
          else if (p == 1)
            if (sn.vivo)
              os << p;
            else
              os << 'x';
          else
            os << p;
        }
      os << std::endl;
    }
  return os;
}

std::istream& operator>>(std::istream& is, Snake& sn)
{ 
  std::string buffer;
  char ch;
  unsigned i, j, num, dim_snake;

  is >> buffer >> buffer >> ch >> sn.dim >> ch >> buffer >> ch >> dim_snake;
  sn.corpo.resize(dim_snake);
  sn.vivo = true;
  for (i = 0; i < sn.dim; i++)
    {
      for (j = 0; j < sn.dim; j++)
        {
          is >> ch;
          if (isdigit(ch))
            {
              num = ch - '0';
              sn.corpo[num-1] = Casella(i,j);
            }
          else if (ch == 'x')
            {
              sn.corpo[0] = Casella(i,j);
              sn.vivo = false;
            }
        }
    }
  return is;
}
