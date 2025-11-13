#include "A.hpp"

A::A(unsigned nr, unsigned nc)
{ 
  unsigned i;
  r = nr;
  c = nc;
  v = new double[r*c];
  for (i = 0; i < r*c; i++)
    v[i] = 0.0;
}

A::A(const A& a)
{
  unsigned i;
  r = a.r;
  c = a.c;
  v = new double[r*c];
  for (i = 0; i < r*c; i++)
    v[i] = a.v[i];
}

A& A::operator=(const A& a)
{
  unsigned i;
  if (r*c != a.r*a.c)
  {	
    delete[] v;
    v = new double[a.r*a.c];
  }
  r = a.r;
  c = a.c;
  for (i = 0; i < r*c; i++)
    v[i] = a.v[i];
  return *this;
}

A::~A()
{
  delete[] v;
}

A operator*(const A& a1, const A& a2)
{
   unsigned i, j, k;
   if (a1.c != a2.r)
     throw logic_error("Dimensioni delle matrici incompatibili");
   A a(a1.r, a2.c);
   for (i = 0; i < a1.r; i++)
     for (j = 0; j < a2.c; j++)
       for (k = 0; k < a1.c; k++)
         a(i,j) += a1(i,k)*a2(k,j);
   return a;
}

ostream& operator<<(ostream& os, const A& a)
{
  unsigned i, j;
  
  for (i = 0; i < a.r; i++)
  {
    for (j = 0; j < a.c; j++)
	  os << a(i,j) << " ";
    os << endl;
  }
  return os;
}
