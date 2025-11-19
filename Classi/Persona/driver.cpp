#include "persona.hpp"
#include <vector>
#include <iostream>

int main(int argv, char* argc[])
{
   string nome_f;
   vector<Persona> p;
  
   if (argv == 1)
   {
      cout << "Nome file : ";
      cin >> nome_f;
   }
   else if (argv == 2)
      nome_f = argc[1];
   else
      exit(1); 
   //OrdinaFile(nome_f);
   LeggiPersone(p, nome_f);
   pair<string, unsigned> out;
   out = NomeFrequente(p);
   cout << out.first << ' ' << out.second << endl;
   return 0;
}