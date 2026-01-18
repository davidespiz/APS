#include "Insegnamento.hpp"

Insegnamento::Insegnamento(std::string t, unsigned c, std::string ssd, unsigned sem)
  : titolo(t), settore(ssd)
{
  crediti = c;
  semestre = sem;
}

std::ostream& operator<<(std::ostream& os, const Insegnamento& in)
{
  os << in.titolo << " - " << in.settore << " (" << in.crediti << " CFU) [" << in.semestre << " sem]";
  return os;
}

 
