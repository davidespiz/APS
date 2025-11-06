#include "polinomi.hpp"

Poli::Poli()
{
   dim = -1;
   vet = nullptr;
}

Poli::Poli(float term, int exp)
{
   vet = new float[exp + 1];
   vet[dim = exp] = term;
}

float Poli::GetTerm(const int exp) const
{
   return exp <= dim ? vet[exp] : 0; 
}
 Poli::~Poli()
 {
   delete[] vet;
 }

Poli operator+(const Poli& p1, const Poli& p2)
{ 
   Poli p;
   p.dim = max(p1.dim, p2.dim);
   p.vet = new float[p.dim + 1];

   for(int i = 0; i < p.dim; i++)
      p.vet[i] = (i <= p1.dim ? p1.vet[i] : 0) + (i <= p2.dim ? p2.vet[i] : 0);
   return p;
}

Poli operator-(const Poli& p1, const Poli& p2)
{ 
   Poli p;
   p.dim = max(p1.dim, p2.dim);
   p.vet = new float[p.dim + 1];

   for(int i = 0; i < p.dim; i++)
      p.vet[i] = (i <= p1.dim ? p1.vet[i] : 0) - (i <= p2.dim ? p2.vet[i] : 0);
   return p;
}

ostream& operator<<(ostream& os, const Poli& p)
{
   if(p.dim == -1)
   {
      os << "<>";
      return os;
   }
   os << '<'<< p.vet[p.dim] << "x^" << p.dim; 

   int i = p.dim - 1;
   while(i >= 0)
   { 
      if(p.vet[i] != 0)
      {
         os << " + " << p.vet[i] << "x^" << i;
         i--;
      }
      else
         i--;
   }
   cout << '>';
   return os;
}

istream& operator>>(istream& is, Poli& p)
{
   char ch;
   float t;
   int d;
   is >> ch;
   if(is.peek() != '>')
      is >> t >> ch >> ch >> d >> ch;
   else 
      return is;
   //vedo se devo riallocare la memoria
   if(d > p.dim)
   {
      delete[] p.vet;
      p.vet = new float[p.dim = d];
      p.vet[p.dim] = t;
   }
   while(ch != '>')
   {
      is >> t >> ch >> ch >> d >> ch;
      p.vet[d] = t;
   }
   return is;
}

Poli& Poli::operator=(const Poli& p)   //operatore di copia profonda
{
   if(dim < p.dim)   //rialloco
   {
      delete[] vet;
      vet = new float[p.dim + 1];
      dim = p.dim;
   }
   for(int i = 0; i <= dim; i++)
      vet[i] = p.vet[i];
   return *this;
}

Poli::Poli(Poli& p)
{
   //non serve riallocare, il polinomio è nuovo 
   dim = p.dim;
   vet = new float[dim + 1];
   for(int i = 0; i <= dim; i++)
      vet[i] = p.vet[i];
}

float Poli::operator()(float x)  //restituisce il valore del polinomio in x
{
   float y;
   for(int i = 0; i <= dim; i++)
      y += vet[i] * pow(x, i);
   return y;
}