// File GiocoOca.cpp
#include <stdexcept>
#include "GiocoOca.hpp"

GiocoOca::GiocoOca()
  // crea un tabellone ed un numero di giocatori di default: 
  // 10 caselle tutte normali, 2 giocatori
  : tabellone(10,0), posizione_giocatore(2,0)
{
  num_giocatori = 2;
  giocatore_di_turno = 0;
  vincitore = -1;
}

GiocoOca::GiocoOca(const std::vector<int>& t, unsigned k)
  : tabellone(t), posizione_giocatore(k,0)
{
  num_giocatori = k;
  giocatore_di_turno = 0;
  vincitore = -1;
}

void GiocoOca::Ricomincia()
{
  for (unsigned i = 0; i < num_giocatori; i++)
    posizione_giocatore[i] = 0;
  giocatore_di_turno = 0;
  vincitore = -1;
}

void GiocoOca::DefinisciTabellone(const std::vector<int>& t)
{
  tabellone = t;
  Ricomincia();
}

void GiocoOca::DefinisciGiocatori(unsigned k)
{
  num_giocatori = k;
  posizione_giocatore.resize(k);
  Ricomincia();
}  

void GiocoOca::EseguiMossa(unsigned d)
{
  if (vincitore != -1)
    throw std::invalid_argument("Partita gia' finita");
  // esegui lancio
  posizione_giocatore[giocatore_di_turno] += d; 
  if (posizione_giocatore[giocatore_di_turno] >= tabellone.size())
    {
      vincitore = giocatore_di_turno;
      return;
    }
  // esegui l'istruzione
  while (tabellone[posizione_giocatore[giocatore_di_turno]] != 0) // esegui casella
    {
      // non si puo' tornare ad una casella prima dell'inizio
      if (posizione_giocatore[giocatore_di_turno] 
	     + tabellone[posizione_giocatore[giocatore_di_turno]] < 0)
        throw std::invalid_argument("Casella precedente all'inizio");
      posizione_giocatore[giocatore_di_turno] += 
	tabellone[posizione_giocatore[giocatore_di_turno]];
    }
  // passa il turno al giocatore successivo 
  if (giocatore_di_turno == num_giocatori - 1)
    giocatore_di_turno = 0;
  else
    giocatore_di_turno++;
}

std::istream& operator>>(std::istream& is, GiocoOca& g)
{
  // Formato 
  // Caselle: <num_caselle> 
  // <casella1> <casella2> ...
  // Giocatori: <num_giocatori> 
  // <pos_gioc1> <pos gioc2> ...
  // Turno: <giocatore_di_turno>
  // si assume che la partita sia in corso
  unsigned dim_tabellone, i;
  std::string buffer;

  is >> buffer >> dim_tabellone;
  g.tabellone.resize(dim_tabellone);
  for (i = 0; i < dim_tabellone; i++)
    is >> g.tabellone[i];
  is >> buffer >> g.num_giocatori;
  g.posizione_giocatore.resize(g.num_giocatori);
  for (i = 0; i < g.num_giocatori; i++)
    is >> g.posizione_giocatore[i];
  is >> buffer >> g.giocatore_di_turno;
  return is;
}

std::ostream& operator<<(std::ostream& os, const GiocoOca& g)
{
  unsigned i;
  os << "Caselle: " << g.tabellone.size() << std::endl;
  for (i = 0; i < g.tabellone.size(); i++)
    os << g.tabellone[i] << ' ' ;
  os << std::endl;
  os << "Giocatori: " << g.num_giocatori << std::endl;
  for (i = 0; i < g.num_giocatori; i++)
    os << g.posizione_giocatore[i] << ' '; 
  os << std::endl;
  if (g.vincitore == -1)
    os << "Turno: " << g.giocatore_di_turno << std::endl;
  else
    os << "Vincitore: " << g.vincitore << std::endl;
  return os;
}
