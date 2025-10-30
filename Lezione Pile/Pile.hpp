#ifndef PILE
#define PILE

#include <iostream>
using namespace std;

class Pila
{
   friend ostream& operator<<(ostream& os, const Pila& p);
   friend istream& operator>>(istream& is, Pila& p);

   public:
   Pila();
   void Push(int elem);                      //aggiunge un elemento in cima alla pila (gestisce vet dinamico)
   void Pop() {top--;}                       //toglie l'elemento in superficie
   int Top() const {return vet[top];}        //restituisce l'elemento in superficie 
   bool IsEmpty() const {return top == -1;}  //mi dice se la pila è vuota

   private:
   int* vet;
   int dim;
   int top;
};
#endif