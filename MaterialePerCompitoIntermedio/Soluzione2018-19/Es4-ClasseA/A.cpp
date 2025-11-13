#include "A.hpp"

A::A(unsigned d)
{ dim = d;
  b = true;
  v = new int[d];
  for (unsigned i = 0; i < dim; i++)
    v[i] = 0;
  w = nullptr;
}

void A::X()
{ b = false;
  w = new int[dim];
  for (unsigned i = 0; i < dim; i++)
    w[i] = 0;
}

A::A(const A& a)
{
  unsigned i;
  dim = a.dim;
  b = a.b;
  v = new int[dim];
  for (i = 0; i < dim; i++)
    v[i] = a.v[i];
  if (b)
    w = nullptr;
  else
    {
      w = new int[dim];
      for (i = 0; i < dim; i++)
        w[i] = a.w[i];
    }
}

A& A::operator=(const A& a)
{
  unsigned i;
  if (dim != a.dim)
  {	  
    delete[] v;
    v = new int[a.dim];
  }	
  for (i = 0; i < a.dim; i++)
    v[i] = a.v[i];
  if (a.b)
  {	  
    if (!b)
	{	  
      delete[] w;
	  w = nullptr;
	}
  }	
  else
  {
     if (dim != a.dim)
	 {
	   if (!b) 
		 delete[] w;
	   w = new int[dim];
	 }
	 if (b)
	    w = new int[dim]; 
	 for (i = 0; i < dim; i++)
       w[i] = a.w[i];
  }
  dim = a.dim;
  b = a.b;
  return *this;
}

A::~A()
{
  delete[] v;
  if (!b)
    delete[] w;
}
