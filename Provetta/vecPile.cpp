#include "Pile.hpp"
#include <vector>
#include <iostream>

using namespace std;

Pila PilaPositivi(vector<Pila> v)
{
   Pila p;
   unsigned i;
   for(i = 0; i < v.size(); i++)
      while(v[i].IsEmpty() != 1)
         if(v[i].Top() > 0)
         {
            p.Push(v[i].Top());
            v[i].Pop();
         }
         else 
            v[i].Pop();
   return p;
}

int main()
{
   vector<Pila> v;
   int vec[] = {3,-5,2,-32,21};

   for(int i = 0; i < 4; i++)
   {
      Pila p;
      for(int k = 0; k < i + 2; k++)
         p.Push(vec[k]);
      cout << p << endl;
      v.push_back(p);
   }
   cout << PilaPositivi(v) << endl;
}