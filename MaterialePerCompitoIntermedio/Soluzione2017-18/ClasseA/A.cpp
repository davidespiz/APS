#include "A.hpp"

A::A(unsigned d, bool split)
{ 
  unsigned i;
  dim = d;
  p1 = new double[d];
  for (i = 0; i < dim; i++)
    p1[i] = 0.0;
  if (split)
    { 
      p2 = new double[d];
      for (i = 0; i < dim; i++)
        p2[i] = 0.0;
    }
  else
    p2 = p1;	   
}

A::A(const A& a)
{
  unsigned i;
  dim = a.dim;
  p1 = new double[dim];
  for (i = 0; i < dim; i++)
    p1[i] = a.p1[i];
  if (a.p2 == a.p1)
	p2 = p1;
  else
  {
	  p2 = new double[dim];
	  for (i = 0; i < dim; i++)
         p2[i] = a.p2[i];
  }
}

A& A::operator=(const A& a)
{
  unsigned i;
  if (p2 != p1)
	delete[] p2;
  delete[] p1;
  dim = a.dim;
  p1 = new double[dim];
  for (i = 0; i < dim; i++)
    p1[i] = a.p1[i];
  if (a.p2 == a.p1)
	p2 = p1;
  else
  {
	 p2 = new double[dim];
	 for (i = 0; i < dim; i++)
       p2[i] = a.p2[i];
  }
  return *this;
}

A::~A()
{
  if (p2 != p1)
	delete[] p2;
  delete[] p1;
}

void A::Merge()
{ 
  if (p1 != p2)
    { 
      delete[] p2;
      p2 = p1;
    }
}

void A::Split()
{ 
  unsigned i;
  if (p1 == p2)
    { 
      p2 = new double[dim];
      for (i = 0; i < dim; i++)
        p2[i] = p1[i];
    }
}
