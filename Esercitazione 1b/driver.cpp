#include <iostream>
using namespace std;

#include "orario.hpp"

int main()
{
   Orario t;
   cout << t.Ore() << ":" << t.Minuti() << ":" <<t.Secondi() << endl;

   return 0;
}