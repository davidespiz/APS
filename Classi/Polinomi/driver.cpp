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

   Poli p1, p2;
   cin >> p1 >> p2;

   //p1 = p1 + p2;
   cout << p1 * p2 << endl;

   is.close();
   return 0;
}