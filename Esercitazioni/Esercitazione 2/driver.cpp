#include <iostream>
using namespace std;

#include "vettori3D.hpp"

int main()
{
   Vettori3D v1(1, 2, 3);
   Vettori3D v2;
   cin >> v2;

   v1 = v1 & v2;
   
   cout << v1 << endl;

   return 0;
}