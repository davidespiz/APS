#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "polinomi.hpp"

int main(int argc, char* argv[])
{
   //apertura file 
   ifstream is;
   string nome_file;

   if(argc == 1)  //non ho un nome file in argv
   {
      cout << "Inserire nome file: ";
      cin >> nome_file;
   }
   else if (argc == 2)
      nome_file = argv[argc - 1];
   is.open(nome_file);

   Poli p1;
   is >> p1;
   Poli p2(p1);
   //p1 = p1 + p2;
   cout << p2(1) << endl;

   is.close();
   return 0;
}