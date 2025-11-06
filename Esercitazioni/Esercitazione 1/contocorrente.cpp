#include <iostream>
#include <cmath>
using namespace std;

#include "contocorrente.hpp"

void ContoCorrente::DepositaEuro(unsigned unita, unsigned centesimi)
{
   contoEuro += unita;
   contoCent += centesimi;
}

double ContoCorrente::SaldoInLire() const
{
   return (contoEuro + contoCent * 0.01) * valoreLire;
}

void ContoCorrente::PrelevaEuro(unsigned unita, unsigned centesimi)
{
   if(contoEuro < unita)
      return;
   else 
      contoEuro -= unita;
      
   if(contoCent < centesimi)
      return;
   else  
      contoCent -= centesimi;
}

void ContoCorrente::AggiornaSaldo()
{
   double saldo = (contoEuro + contoCent * 0.01) * (1 + interesse);
   contoEuro = round(saldo);
   contoCent = round((saldo - contoEuro) * 100);

   if(contoCent == 0 && saldo - contoEuro * 100 > 1)
      contoEuro++;
}

void ContoCorrente::FissaTassoInteresse(double t)
{
   interesse = t;
}