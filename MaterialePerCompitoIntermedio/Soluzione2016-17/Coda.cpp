//File Coda.cpp
#include "Coda.hpp"

Coda::Coda()
{ // non usare nullptr: in vettore e' sempre allocato
  dim = 10; // fissato a 10 per debugging (per poter verificare le riallocazioni)
  vet = new int[dim];
  head = 0; 
  tail = -1; 
}

Coda::~Coda()
{ 
  delete [] vet;
}

Coda::Coda(const Coda& c)
{ // copia la coda p nella parte bassa del vettore, per evitare spostamenti futuri
  // (anche la copia "sul posto" era accettabile)
  dim = c.dim;
  vet = new int[dim];
  tail = c.Length() - 1;
  head = 0;
  for (int i = 0; i < c.Length(); i++)
    vet[i] = c.vet[i+c.head];
}

Coda& Coda::operator=(const Coda& c)
{ 
  if (c.Length() > dim) 
    { // riallocare solo se strettamente necessario
      delete[] vet;
      dim = c.dim;
      vet = new int[dim];
    }
  tail = c.Length() - 1;
  head = 0;
  for (int i = 0; i < c.Length(); i++)
    vet[i] = c.vet[i+c.head];
  return *this;
}

void Coda::Push(int elem)
{ 
  if (Length() == dim)
    { // ingrandisci il vettore solo se strettamente necessario
      int* aux_vet = new int[dim*2];
      for (int i = head; i <= tail; i++)
        aux_vet[i] = vet[i];
      delete [] vet;
      vet = aux_vet;
      dim = 2*dim;
    }
  else if (tail == dim - 1)
    { // ritira indietro la coda, senza riallocare il vettore
      for (int i = 0; i < Length(); i++)
        vet[i] = vet[i+head];
      tail = Length() - 1;
      head = 0;
    }
  tail++;
  vet[tail] = elem;
}

void Coda::Pop()
{ // la coda e' vuota se head > tail, non se tail == -1
  if (head > tail)
    throw logic_error("Coda vuota");
  head++; 
}

int Coda::Top() const 
{ 
  if (head > tail)
    throw logic_error("Coda vuota");
  return vet[head]; 
}

bool operator==(const Coda& c1, const Coda& c2)
{ // confronto tra le Code a livello logico, non fisico
  int i, j;
  if (c1.Length() != c2.Length())
    return false;
  for (i = c1.head, j = c2.head; i <= c1.tail; i++, j++)
    if (c1.vet[i] != c2.vet[j]) 
      return false; 
  // usare true e false, non 1 e 0
  return true;
}

ostream& operator<<(ostream& os, const Coda& c)
{ // operatore di output (non richiesto per il compito)
  os << "(";
  for (int i = c.head; i < c.tail; i++)
    os << c.vet[i] << ", ";
  if (c.head <= c.tail)
    os << c.vet[c.tail];
  os << ")";
  return os;
}

void Coda::Stampa(ostream& os) const
{ // stampa lo stato interno dell'oggetto (non richiesto per il compito)
  os << "head = " << head << ", tail = " << tail << ", dim = " << dim 
     << ", vet = [";
  for (int i = 0; i < dim-1; i++)
    os << vet[i] << ", ";
  os << vet[dim-1];
  os << "]" << endl;
}

istream& operator>>(istream& is, Coda& c)
{// operatore di input (non richiesto per il compito)
  // assume gli elementi della coda tra parentesi e separati da virgole 
  int elem;
  char ch;

  c.head = 0;  // svuota
  c.tail = -1; // la coda 

  is >> ch; // legge la parentesi aperta
  ch = is.peek();
  if (ch != ')')
    {
      do 
        {
          is >> elem >> ch;
          c.Push(elem); // il problema del ridimensionamento e' 
                        // demandato a Push()
        }
      while (ch != ')');
    }
  else
    is >> ch;
  return is;
}
