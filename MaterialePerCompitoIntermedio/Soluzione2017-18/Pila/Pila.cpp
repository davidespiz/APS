//File Pila.cpp
#include "Pila.hpp"

Pila::Pila()
{ 
  dim = 100;
  vet = new int[dim];
  top = -1; 
}

Pila::~Pila()
{ 
  delete [] vet;
}

bool operator==(const Pila& p1, const Pila& p2)
{ 
  if (p1.top != p2.top) 
    return false;
  for (int i = 0; i <= p1.top ; i++)
    if (p1.vet[i] != p2.vet[i]) 
      return false; 
  return true;
}

Pila::Pila(const Pila& p)
{ 
  dim = p.dim;
  top = p.top;
  vet = new int[dim];
  for (int i = 0; i <= top; i++)
    vet[i] = p.vet[i];
}

Pila& Pila::operator=(const Pila& p)
{ 
  if (p.top >= dim)
    {
      delete [] vet;
      dim = p.dim;
      vet = new int[dim];
    }
  top = p.top;
  for (int i = 0; i <= top; i++)
    vet[i] = p.vet[i]; 
  return *this;
}

void Pila::Push(int elem)
{ 
  if (top == dim - 1)
    { // ingrandisci il vettore
      int* aux_vet = new int[dim*2];
      for (int i = 0; i <= top; i++)
        aux_vet[i] = vet[i];
      delete [] vet;
      vet = aux_vet;
      dim = 2*dim;
    }
  top++;
  vet[top] = elem;
}

void Pila::Pop()
{ 
  if (top == -1)
    throw logic_error("ERRORE!! Pop su pila vuota");
  top--; 
}

Pila& Pila::operator-=(int e)
{
  int i, j;
  for (i = top; i >= 0; i--)
    if (vet[i] == e)
      {
        for (j = i; j < top; j++)
           vet[j] = vet[j+1];
        top--;
      }
  return *this;
}


ostream& operator<<(ostream& os, const Pila& p)
{
  os << "(";
  for (int i = 0; i < p.top; i++)
    os << p.vet[i] << ", ";
  if (p.top != -1)
    os << p.vet[p.top];
  os << ")";
  return os;
}

istream& operator>>(istream& is, Pila& p)
{
  // assume gli elementi della pila tra parentesi e separati da virgole 
  int elem;
  char ch;

  p.top = -1; // Svuota la pila 

  is >> ch; // legge la parentesi aperta
  ch = is.peek();
  if (ch != ')')
    {
      do 
        {
          is >> elem >> ch;
          p.Push(elem); // il problema del ridimensionamento e' 
                        // demandato a Push()
        }
      while (ch != ')');
    }
  else
    is >> ch;
  return is;
}
