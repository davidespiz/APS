#include <stdexcept>
#include "CorsoStudi.hpp"

Erogazione::Erogazione(Insegnamento* in, Tipologia t, unsigned a)
{
  insegnamento = in;
  tipo = t;
  anno = a;
}

std::ostream& operator<<(std::ostream& os, const CorsoStudi& cs)
{
  os << cs.nome << " (classe " << cs.classe << ", " 
     << cs.crediti_necessari << ")" << std::endl;
  os << "Insegnamenti:" << std::endl;
  for (unsigned i = 0; i < cs.erogazioni.size(); ++i)
  {
    os << *(cs.erogazioni[i].insegnamento) << " " << cs.erogazioni[i].anno << " "; 
    if (cs.erogazioni[i].tipo == Tipologia::obbligatorio)
      os << "obbligatorio";
    else if (cs.erogazioni[i].tipo == Tipologia::scelta)
      os << "a scelta";
    else
      os << "curricolare";  
    os << std::endl;
  }
  os << "Curricula:" << std::endl;
  for (unsigned i = 0; i < cs.curricula.size(); ++i)
    {
      os << cs.curricula[i] << std::endl;
    }
  return os;
}

CorsoStudi::CorsoStudi(std::string n, std::string c, unsigned cn)
  : nome(n), classe(c) 
{
  crediti_necessari = cn;
}

void CorsoStudi::InserisciInsegnamento(Insegnamento* in, Tipologia t, unsigned a)
{
  if (CercaInsegnamento(in) == -1)
    erogazioni.push_back(Erogazione(in,t,a));
}

void CorsoStudi::CreaCurriculum(std::string nome)
{
  if (CercaCurriculum(nome) != -1)
    throw std::logic_error("Nome curriculum duplicato");
  curricula.push_back(Curriculum(nome));
}

void CorsoStudi::InserisciInCurriculum(Insegnamento* in, std::string cu)
{
  int i = CercaInsegnamento(in);
  int c = CercaCurriculum(cu);
  if (i == -1)
    throw std::logic_error("Insegnamento inesistente");
  if (erogazioni[i].tipo != Tipologia::curricolare)
    throw std::logic_error("Insegnamento di tipo sbagliato");
  if (c == -1)
    throw std::logic_error("Curriculum inesistente");
  curricula[c].InserisciInsegnamento(in);
} 

bool CorsoStudi::VerificaCrediti() const
{ 
  unsigned crediti_obbligatori, crediti_scelta, crediti_curriculum = 0;
  crediti_obbligatori = SommaCrediti(Tipologia::obbligatorio);
  crediti_scelta = SommaCrediti(Tipologia::scelta);
 
  for (unsigned i = 0; i < curricula.size(); ++i)
  {
    crediti_curriculum = curricula[i].CreditiTotali();
    if (crediti_obbligatori + crediti_curriculum >= crediti_necessari) 
      return false;
    if (crediti_obbligatori + crediti_scelta + crediti_curriculum 
        <= crediti_necessari) 
      return false;
  }
  return true;
}

bool CorsoStudi::EsisteInsegnamento(Insegnamento* in, Tipologia t) const
{
  for (unsigned i = 0; i < erogazioni.size(); ++i)
    if (erogazioni[i].insegnamento == in)
      return erogazioni[i].tipo == t;
  return false;
}


unsigned CorsoStudi::SommaCrediti(Tipologia t) const 
{
  unsigned crediti = 0;
  for (unsigned i = 0; i < erogazioni.size(); ++i)
    if (erogazioni[i].tipo == t)
      crediti += erogazioni[i].insegnamento->Crediti();
  return crediti;
}

bool CorsoStudi::PresenteInCurricula(Insegnamento* in) const
{
  for (unsigned i = 0; i < curricula.size(); ++i)
    if (curricula[i].Membro(in))
      return true;
  return false;
}

int CorsoStudi::CercaCurriculum(std::string nome) const
{
  for (unsigned i = 0; i < curricula.size(); ++i)
    if (curricula[i].Nome() == nome)
      return i;
  return -1;
}

int CorsoStudi::CercaInsegnamento(Insegnamento* in) const
{
  for (unsigned i = 0; i < erogazioni.size(); ++i)
    if (erogazioni[i].insegnamento == in)
      return i;
  return -1;
}
