#include <iostream>
using namespace std;

#include "contocorrente.hpp"



int main()
{
   ContoCorrente c1;
   c1.DepositaEuro(1, 50);
   cout << c1.SaldoInEuro() << "." << c1.SaldoCentesimi() << " " << c1.SaldoInLire() << endl;

   return 0;
}

