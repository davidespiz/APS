#include <stdexcept>
#include "BiPila2.hpp"

BiPila::BiPila()
{
  dim = 100;
  vet = new int[dim];
  top1 = -1; 
  top2 = 100;
}

BiPila::BiPila(const BiPila& p)
{  
  int i;
  dim = p.dim;
  top1 = p.top1;
  top2 = p.top2;
  vet = new int[dim];
  for (i = 0; i <= top1; i++)
    vet[i] = p.vet[i];
  for (i = dim-1; i >= top2; i--)
    vet[i] = p.vet[i];
}

BiPila::~BiPila()
{
  delete [] vet;
}

BiPila& BiPila::operator=(const BiPila& p)
{
  int i;
  if (p.top1 + (p.dim - p.top2) >= dim)
    {
      delete [] vet;
      dim = p.dim;
      vet = new int[dim];
    }
  top1 = p.top1;
  top2 = p.top2;
  for (i = 0; i <= top1; i++)
    vet[i] = p.vet[i]; 
  for (i = dim-1; i >= top2; i--)
    vet[i] = p.vet[i];
  return *this;
}

void BiPila::Pop(int lato)
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (lato == 1)
    top1--;
  else
    top2++;
}
 
void BiPila::Push(int elem, int lato)
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (top2 == top1 + 1)
    { // ingrandisci il vettore
      int* aux_vet = new int[dim*2];
      int i;
      for (i = 0; i <= top1; i++)
        aux_vet[i] = vet[i];
      for (i = dim-1; i >= top2; i--)
	aux_vet[i+dim] = vet[i];
      delete [] vet;
      vet = aux_vet;
      top2 += dim;
      dim = 2*dim;
    }
  if (lato == 1)
    {
      top1++;
      vet[top1] = elem;
    }
  else
    {
      top2--;
      vet[top2] = elem;
    }
}
 
int BiPila::Top(int lato) const
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (lato == 1)
    return vet[top1];
  else
    return vet[top2];
}
 
bool BiPila::EstVuota(int lato) const
{
  if (lato != 1 && lato != 2)
    throw std::domain_error("Lato inesistente");
  if (lato == 1)
    return top1 == -1;
  else
    return top2 == dim;
}  

std::ostream& operator<<(std::ostream& os, const BiPila& p)
{
  int i;
  os << "(";
  for (i = 0; i < p.top1; i++)
    os << p.vet[i] << ", ";
  if (p.top1 != -1)
    os << p.vet[p.top1];
  os << ") | (";
  for (i = p.dim-1; i > p.top2; i--)
    os << p.vet[i] << ", ";
  if (p.top2 != p.dim)
    os << p.vet[p.top2];
  os << ")";
  return os;
}

