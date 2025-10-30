#include "Pile.hpp"

Pila::Pila()
{
   dim = 100;  //decidiamo di default di partire con una pila di dimensione 100
   vet = new int[dim];
   top = -1;
}

ostream& operator<<(ostream& os, const Pila& p)
{
   os << '(';
   for(int i = 0; i < p.top; i++)
      os << p.vet[i] << ", ";
   os<< p.vet[p.top] << ')';
   return os;
}
istream& operator>>(istream& is, Pila& p)
{
   char ch;

   is >> ch;   //leggo la prima parentesi

   if(is.peek() != ')')
   do
      is >> p.vet[++p.top] >> ch;
   while(ch != ')');

   return is;
}

void Pila::Push(int elem)
{
   if(top == dim - 1)   //se sono arrivato alla dimensione massima del vettore lo devo riallocare 
   {
      //creo un vettore di appoggio 
      int* aux_vet = new int[dim*2];
      //ora vado a copiare il vecchio vettore in quello nuovo
      for(int i = 0; i <= dim; i++)
         aux_vet[i] = vet[i];
      //vado a cancellare il vecchio vettore 
      delete[] vet;
      //e vado ad assegare a vet il nuovo vettore
      vet = aux_vet;
      dim *= 2;   //raddoppio sempre la dimensione in quanto è un operazione costosa
   }
   vet[++top] = elem;
}