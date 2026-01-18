#include "Curriculum.hpp"

Curriculum::Curriculum(std::string n)
  : nome(n)
{
  crediti_totali = 0;
}
  
void Curriculum::InserisciInsegnamento(Insegnamento* in)
{
  if (CercaInsegnamento(in) == -1)
    {
      insegnamenti.push_back(in);
      crediti_totali += in->Crediti();
    }
}

int Curriculum::CercaInsegnamento(Insegnamento* in) const
{
  for (unsigned i = 0; i < insegnamenti.size(); ++i)
    if (insegnamenti[i] == in)
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Curriculum& cur)
{
  os << "Insegnamenti del curriculum: " << cur.nome << " (" << cur.crediti_totali << " CFU)" << std::endl; 
  for (unsigned i = 0; i < cur.insegnamenti.size(); ++i)
    os << *(cur.insegnamenti[i]) << std::endl;

  return os;
}
