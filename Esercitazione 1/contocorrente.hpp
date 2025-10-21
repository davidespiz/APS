#include <iostream>

#ifndef CONTO
#define CONTO

class ContoCorrente
{
   public:
   const float valoreLire = 1936.27;
   ContoCorrente(){contoEuro = 0; contoCent = 0; interesse = 0.0;}
   ContoCorrente(double i){contoEuro = 0; contoCent = 0; interesse = i;}
   double TassoInteresse() const {return interesse;}
   unsigned SaldoInEuro() const {return contoEuro;}
   unsigned SaldoCentesimi() const {return contoCent;};

   void DepositaEuro(unsigned unita, unsigned centesimi);
   double SaldoInLire() const;


   private:
   unsigned contoEuro;
   unsigned contoCent;
   double interesse;



};

#endif