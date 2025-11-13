#include "vettore.hpp"

Vettore::Vettore(int d = 100)
{
   dim = d;
   term = -1;
   index = new int[dim];
   value = new float[dim];
}

Vettore::~Vettore()
{
   delete[] index;
   delete[] value;
}

Vettore::Vettore(const Vettore& v)
{
   dim = v.dim;
   term = v.term;
   index = new int[dim];
   value = new float[dim];
   for(int i = 0; i < dim; i++)
   {
      index[i] = v.index[i];
      value[i] = v.value[i];
   }
}

ostream& operator<<(ostream& os, const Vettore& v)
{
   os << '[';
   for(int i = 0; i <= v.term - 1; i++)
      os << '<' << v.index[i] << ',' << v.value[i] << ">,";
   os << '<' << v.index[v.term] << ',' << v.value[v.term] << ">]";
   return os;
}

istream& operator>>(istream& is, Vettore& v)
{
   char ch;
   is >> ch >> ch;
   int ind;
   float val;
   while(ch != ']')
   {
      is >> ind >> ch >> val >> ch >> ch;
      v.Set(ind, val);
      if(ch == ',')
         is >> ch;
   }   
   return is;
}

void Vettore::Set(int i, float v)
{
   if(term + 1 == dim)
   {
      int* aux_i = new int[dim*2];
      float* aux_v = new float[dim*2];
      for(int i = 0; i < dim; i++)
      {
         aux_i[i] = index[i];
         aux_v[i] = value[i];
      }
      delete[] index;
      delete[] value;
      index = aux_i;
      value = aux_v;
      dim *= 2;
   }
   int k;
   for(k = 0; k <= term; k++)
      if(index[k] == i)
      {
         value[k] = v;
         return;
      }
   term++;
   value[term] = v;
   index[term] = i;
   
   return;  
}