//file cliente.hpp

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>

class Cliente
{
  friend std::ostream& operator<<(std::ostream& os, const Cliente& c);
public:
  Cliente(int num_t, int c = 0); 
  int NTessera() const 	{ return n_tessera; }
  int Credito() const 	{ return credito; }
  void Prelievo(unsigned c);
  void AggiungiCredito(unsigned c);
private:
  int n_tessera;
  int credito;
};

#endif

