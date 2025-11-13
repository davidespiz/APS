#include <iostream>
#include <cassert>
#include "A.hpp"

A::A(unsigned n)
{
  unsigned i;
  dim = n;
  v = new int[dim];
  for (i = 0; i < dim; i++)
    v[i] = 1;
  vb = nullptr;
}

void A::BackUp()
{
  unsigned i;
  if (vb == nullptr)
    vb = new int[dim];
  for (i = 0; i < dim; i++)
    vb[i] = v[i];
}

void A::Restore()
{
  unsigned i;
  assert (vb != nullptr);
  for (i = 0; i < dim; i++)
    v[i] = vb[i];
}

ostream& operator<<(ostream& os, const A& a)
{
  unsigned i;
  if (a.vb == nullptr)
    for (i = 0; i < a.dim; i++)
      os << a.v[i] << " ";
  else
    for (i = 0; i < a.dim; i++)
      os << a.v[i] << "/" << a.vb[i] << " ";
  return os;
}

A::A(const A& a)
{
  unsigned i;
  dim = a.dim;
  v = new int[dim];
  for (i = 0; i < dim; i++)
    v[i] = a.v[i];
  if (a.vb == nullptr)
    vb = nullptr;
  else
    {
      vb = new int[dim];
      for (i = 0; i < dim; i++)
	vb[i] = a.vb[i];
    }
}

A& A::operator=(const A& a)
{
  unsigned i;
  dim = a.dim;
  delete[] v;
  v = new int[dim];
  for (i = 0; i < dim; i++)
    v[i] = a.v[i];

  if (a.vb == nullptr)
    {
      if (vb != nullptr)
	{
	  delete[] vb;
	  vb = nullptr;
	}
    }
  else
    {
      if (vb != nullptr)
	delete[] vb;
      vb = new int[dim];
      for (i = 0; i < dim; i++)
	vb[i] = a.vb[i];
    }
  return *this;
}

A::~A()
{
  delete[] v;
  delete[] vb;
}

