#include <iostream>
using namespace std;

#include "contocorrente.hpp"

void ContoCorrente::DepositaEuro(unsigned unita, unsigned centesimi)
{
   contoEuro += unita;
   contoCent += centesimi;
}

double ContoCorrente::SaldoInLire() const
{
   return (contoEuro + contoCent * 0.01) + valoreLire;
}