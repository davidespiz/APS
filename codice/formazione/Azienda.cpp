//File Azienda.cpp
#include <stdexcept>
#include "Azienda.hpp"

Azienda::Azienda(std::string n)
  : nome(n)
{}

void Azienda::InserisciDocente(Docente* d)
{
  if (CercaDocente(d) != -1)
    throw std::invalid_argument("Docente gia' presente");
  docenti.push_back(d);

}
void Azienda::InserisciCorso(Corso* c)
{
  if (CercaCorso(c) != -1)
    throw std::invalid_argument("Corso gia' presente");
  corsi.push_back(c);
}

void Azienda::InserisciLezioneCorso(Lezione* l, Corso* c)
{
  if (CercaCorso(c) == -1)
    throw std::invalid_argument("Corso assente");
  c->AggiungiLezione(l);
}

void Azienda::InserisciCliente(Cliente* c)
{
  if (CercaCliente(c) != -1)
    throw std::invalid_argument("Cliente già presente");
  clienti.push_back(c);
}

void Azienda::InserisciClienteCorso(Cliente* cl,Corso* co)
{
  if (CercaCliente(cl) == -1)
    throw std::invalid_argument("Cliente assente");
  if (CercaCorso(co) == -1)
    throw std::invalid_argument("Corso assente");
  co->AggiungiPartecipante(cl);
}

void Azienda::RimuoviClienteCorso(Cliente* cl,Corso* co)
{
  if (CercaCliente(cl) == -1)
    throw std::invalid_argument("Cliente assente");
  co->RimuoviPartecipante(cl);
}

void Azienda::CancellaLezione(Lezione* l)
{
  unsigned i, j;
  for(i = 0; i < corsi.size(); i++)
    for(j = 0; j < corsi[i]->NumLezioni(); j++)
      if(corsi[i]->VediLezione(j) == l)
	corsi[i]->RimuoviLezione(l);
}

int Azienda::CercaCliente(Cliente* c) const
{
  unsigned i;
  for(i = 0; i < clienti.size(); i++)
    if(c == clienti[i])
      return i;
  return -1;
}

int Azienda::CercaCorso(Corso* c) const
{
  unsigned i;
  for(i = 0; i < corsi.size(); i++)
    if(c == corsi[i])
      return i;
  return -1;
}

int Azienda::CercaDocente(Docente* d) const
{
  unsigned i;
  for(i = 0; i < docenti.size(); i++)
    if(d == docenti[i])
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Azienda& a)
{
  os << a.nome;
  return os;
}
