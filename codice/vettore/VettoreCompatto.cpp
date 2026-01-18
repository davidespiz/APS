// file VettoreCompatto.cpp
#include <stdexcept>
#include "VettoreCompatto.hpp"

VettoreCompatto::VettoreCompatto()
{
  vet = nullptr;
  num_elem = 0;
  dim = 0;
}

VettoreCompatto::VettoreCompatto(const VettoreCompatto& v)
{
  dim = v.dim;
  num_elem = v.num_elem;
  vet = new Elemento[dim];
  for (unsigned i = 0; i < dim; i++)
    vet[i] = v.vet[i];
}

VettoreCompatto::~VettoreCompatto()
{
  delete [] vet;
}

VettoreCompatto& VettoreCompatto::operator=(const VettoreCompatto& v)
{
  delete [] vet;
  dim = v.dim;
  num_elem = v.num_elem;
  vet = new Elemento[dim];
  for (unsigned i = 0; i < dim; i++)
    vet[i] = v.vet[i];
  return *this;
}

void VettoreCompatto::Inserisci(int e)
{
  if (num_elem == 0)
    {
      vet = new Elemento(e,1);
      dim = 1;
    }
  else if (vet[dim-1].valore == e)
    vet[dim-1].ripetizioni++;
  else
    {
      Elemento* aux_vet = new Elemento[dim+1];
      for (unsigned i = 0; i < dim; i++)
        aux_vet[i] = vet[i];
      aux_vet[dim] = Elemento(e,1);
      delete [] vet;
      vet = aux_vet;
      dim++;
    }
  num_elem++;
}
                                       
void VettoreCompatto::Elimina()
{
  if (num_elem == 0)
    throw std::invalid_argument("Vettore gia' vuoto");
  if (vet[dim-1].ripetizioni > 1)
    vet[dim-1].ripetizioni--;
  else if (num_elem == 1)
    {
      delete vet;
      vet = nullptr;
      dim = 0;
    }
  else
    {
      Elemento* aux_vet = new Elemento[dim-1];
      for (unsigned i = 0; i < dim-1; i++)
        aux_vet[i] = vet[i];
      delete [] vet;
      vet = aux_vet;
      dim--;
    }
  num_elem--;
}

int VettoreCompatto::operator[](unsigned i) const
{
  unsigned k = 0, h = 0;
  for (unsigned j = 0; j < i; j++)
    {
      h++;
      if (h == vet[k].ripetizioni)
        {
          h = 0;
          k++;
        }
    }
  return vet[k].valore;
}

std::ostream& operator<<(std::ostream& os, const VettoreCompatto& vc)
{
  os << "[";
  if (vc.dim > 0)
    {
      for (unsigned i = 0; i < vc.dim; i++)
        os << "(" << vc.vet[i].valore << "," << vc.vet[i].ripetizioni << ")";
    }
  os << "]";
  return os;
}
