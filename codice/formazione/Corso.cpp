//File Corso.cpp
#include <stdexcept>
#include "Corso.hpp"

Corso::Corso(std::string n, std::string des, Data i, Data f,  unsigned max, Docente* doc)
  : nome(n),  descrizione(des), inizio(i), fine(f)
{
  docente = doc;
  n_max_clienti = max;
}

void Corso::AggiungiLezione(Lezione* l)
{
  if (l->Giorno() < inizio || l->Giorno() > fine)
    throw std::invalid_argument("Giorno non in intervallo");
  if (lezioni.size() > 0 && lezioni[lezioni.size()-1]->Giorno() + 1 != l->Giorno())
    throw std::invalid_argument("Lezioni non in giorni consecutivi");
  lezioni.push_back(l);
}

void Corso::RimuoviLezione(Lezione* l)
{
  if (l != lezioni[lezioni.size()-1])
    throw std::invalid_argument("Solo l'ultima lezione puo' essere rimossa");
  lezioni.pop_back();
}

void Corso::AggiungiPartecipante(Cliente* c)
{
  if (CercaPartecipante(c) != -1)
    throw std::invalid_argument("Partecipante gia' presente");
  if (NumPartecipanti() == NMaxClienti())
    throw std::invalid_argument("Numero massimo di clienti per corso raggiunto");
  partecipanti.push_back(c);
}

void Corso::RimuoviPartecipante(Cliente* c)
{
  int i;
  i = CercaPartecipante(c);
  if (i == -1)
    throw std::invalid_argument("Partecipante assente");
  partecipanti.erase(partecipanti.begin() + i);
}

int Corso::CercaPartecipante(Cliente* c) const
{
  unsigned i;
  for(i = 0; i < partecipanti.size(); i++)
    if(c == partecipanti[i])
      return i;
  return -1;
}

int Corso::CercaLezione(Lezione* l) const
{
  unsigned i;
  for(i = 0; i < lezioni.size(); i++)
    if(l == lezioni[i])
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Corso& c)
{
  unsigned i;
  os << c.nome << std::endl;
  os << "Descrizione: " << c.descrizione << std::endl;
  os << "Data inizio: " << c.inizio << std::endl;
  os << "Data fine: " << c.fine << std::endl;
  os << "Numero massimo di partecipanti: " << c.n_max_clienti << std::endl;
  os << "Clienti partecipanti:" << std::endl;
  if (c.partecipanti.size() > 0)
    {
      for(i = 0; i < c.partecipanti.size(); i++)
	os << *(c.partecipanti[i]) << std::endl;
    }
  else
    os << "Nessun partecipante attualmente iscritto al corso." << std::endl;
  os << "Lezioni inserite:" << std::endl;
  if (c.lezioni.size() > 0)
    {
      for(i = 0; i < c.lezioni.size(); i++)
	os << *(c.lezioni[i]) << std::endl;
    }
  else
    os << "Nessuna lezione inserita al momento." << std::endl;
  return os;
}
