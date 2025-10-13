#include <iostream>
using namespace std;

#include "Eser_0.hpp"
#include <cmath>

int main()
{
   for (int i = 1; i <= 100; i++)
      if(numFelice(i) == true)
         cout << i << ", ";
   cout << endl;
}
