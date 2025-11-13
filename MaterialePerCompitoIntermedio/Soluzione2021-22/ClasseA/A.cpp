#include "A.hpp"

A::A(bool empty, float val)
{ 
  if (empty)
    v = nullptr;
  else
  {
    v = new float[DIM];
    for (unsigned i = 0; i < DIM; i++)
      v[i] = val;
  }
}

A::A(const A& a)
{
  if (a.v == nullptr)
   v = nullptr;
  else
  {
	 v = new float[DIM];
     for (unsigned i = 0; i < DIM; i++)
       v[i] = a.v[i];
  }
}

A& A::operator=(const A& a)
{
  if (a.v != nullptr)
  {
	  if (v == nullptr)
		 v = new float[DIM]; 
      for (unsigned i = 0; i < DIM; i++)
          v[i] = a.v[i];
  }
  else
	 if (v != nullptr)
	 {
		delete[] v;
        v = nullptr;		
	 }
  return *this;
}

A::~A()
{
  if (v != nullptr)
    delete[] v;
}

ostream& operator<<(ostream& os, const A& a)
{
  unsigned i;
  os << '[';
  if (a.v != nullptr)
  {  
    for (i = 0; i < DIM-1; i++)
	  os << a.v[i] << ", ";
	os << a.v[i];   
  }    
  os << ']';
  return os;
}
