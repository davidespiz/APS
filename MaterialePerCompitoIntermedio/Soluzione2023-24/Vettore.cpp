// File Vettore.cpp
#include "Vettore.hpp"

ostream& operator<<(ostream& os, const Vettore& v)
{
  unsigned i;
  os << '[';  
  for (i = 0; i < v.num; i++)
  {
    os << '<' << v.ind[i] << ',' << v.val[i] << '>';
    if (i != v.num-1)
	  os << ',';
  }
  os << ']';
  return os;
}
 
istream& operator>>(istream& is, Vettore& v)
{
  // file format example: 
  // [<3,-14.2>,<6,0.33>,<10,-21.8>,<14,1.66>]
  unsigned i;
  char ch;
  float val;
  is >> ch;
  ch = is.peek();
  while (ch != ']')
  {
	is  >> ch >> i >> ch >> val >> ch >> ch;
	v.Set(i,val);
  }	   
	
  return is;
}
 
Vettore::Vettore(unsigned d)
{
  dim = d;
  num = 0;
  val = new float[dim];     
  ind = new unsigned[dim];  
}

Vettore::Vettore(const Vettore& v)
{

}

Vettore::~Vettore()
{

}

Vettore& Vettore::operator=(const Vettore&)
{
  return *this;
}
 
float Vettore::operator[](unsigned i) const
{
  int j = CercaElemento(i);
  if (j != -1)
    return val[j];	
  else
    return 0.0;
}

void Vettore::Set(unsigned i, float v)
{
  int j = CercaElemento(i);
  if (j != -1)
    val[j] = v;	
  else 
  {
	 if (num == dim)
     {	
	    dim = dim*2;
		float* aux_val = new float[dim];
		unsigned* aux_ind = new unsigned[dim];
		for (j = 0; j < num; j++)
		{
		  aux_val[j] = val[j];
		  aux_ind[j] = ind[j];
		}
		delete[] val;
		delete[] ind;
		val = aux_val;
		ind = aux_ind;
     }
     val[num] = v;
	 ind[num] = i;
	 num++;
  }
}
 
int Vettore::CercaElemento(unsigned i) const
{
  unsigned j;
  for (j = 0; j < num; j++)
    if (ind[j] == i)
      return j;	
  return -1;
}
