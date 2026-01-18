// File cliente.cpp
#include "cliente.hpp"

Cliente::Cliente(int num_t, int c)
{
  n_tessera = num_t;
  credito = c;
}

void Cliente::Prelievo(unsigned c)
{
  //assumo il credito possa diventare negativo
  credito -=(int) c;
}

void Cliente::AggiungiCredito(unsigned c)
{
  credito +=(int) c;
}

std::ostream& operator<<(std::ostream& os, const Cliente& c)
{
  os << "Cliente: " << c.n_tessera << std::endl
     << "credito: " << c.credito << std::endl;	 
  return os;
}

