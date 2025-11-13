//File MultiPila.cpp
#include "MultiPila.hpp"

MultiPila::MultiPila(unsigned num)
{ 
  int i;
  n = num;
  dim = 100;
  total_dim = dim*n;
  vet = new int[total_dim];
  top = new int[n];
  for (i = 0; i < n; i++)
    top[i] = dim*i - 1;
}

MultiPila::~MultiPila()
{ 
  delete [] vet;
  delete [] top;
}

MultiPila::MultiPila(const MultiPila& p)
{ 
  int i, j;
  n = p.n;
  dim = p.dim;
  total_dim = p.total_dim;
  top = new int[n];  
  for (i = 0; i < n; i++)
    top[i] = p.top[i];
  vet = new int[total_dim];

  // copiare solo le parti significative
  for (i = 0; i < n; i++)
    for (j = dim*i; j <= top[i]; j++)
      vet[j] = p.vet[j];
}

MultiPila& MultiPila::operator=(const MultiPila& p)
{ 
  int i, j;
  // per semplicità si rialloca sempre se almeno una dimensione è diversa
  if (n != p.n || dim != p.dim)
    {
      delete [] top;
      delete [] vet;
      n = p.n;
      dim = p.dim;
      total_dim = p.total_dim;      
      top = new int[n]; 
      vet = new int[total_dim];
    }
  for (i = 0; i < n; i++)
    top[i] = p.top[i];
  // copiare solo le parti significative
  for (i = 0; i < n; i++)
    for (j = dim*i; j <= top[i]; j++)
      vet[j] = p.vet[j];      
  return *this;
}

void MultiPila::Push(int elem, unsigned i)
{ 
  int j, k;
  if (top[i] == dim*((int)i+1) - 1)
    { // ingrandisci il vettore
      int* aux_vet = new int[total_dim*2];
      for (k = 0; k < n; k++)
        {
          for (j = dim*k; j <= top[k]; j++)
            aux_vet[dim*k + j] = vet[j];
          top[k] += dim*k; 
        }
      delete [] vet;
      vet = aux_vet;
      dim = 2*dim;
      total_dim = total_dim*2;
    }
  top[i]++;
  vet[top[i]] = elem;
}

void MultiPila::Pop(unsigned i)
{ 
  assert (top[i] >= dim * static_cast<int>(i));
  top[i]--; 
}

int MultiPila::Top(unsigned i) const 
{ 
  assert (top[i] >= dim * static_cast<int>(i));
  return vet[top[i]]; 
}

ostream& operator<<(ostream& os, const MultiPila& p)
{
  int i, j;
  for (i = 0; i < p.total_dim; i++)
    os << p.vet[i] << " ";
  os << endl;
  for (i = 0; i < p.n; i++)
    os << p.top[i] << " ";
  os << endl;
 
  os << "[";
  for (i = 0; i < p.n; i++)
    {
      os << "(";
      for (j = p.dim*i; j < p.top[i]; j++)
        os << p.vet[j] << ", ";
      if (p.top[i] != p.dim*i-1)
        os << p.vet[p.top[i]];
      os << ")";
      if (i != p.n - 1)
        os << ", ";
      else
        os << "]";
    }
  return os;
}

