// File GiocoOca.hpp
#ifndef GIOCO_OCA_HPP
#define GIOCO_OCA_HPP
#include <vector>
#include <fstream>

class GiocoOca
{
  friend std::istream& operator>>(std::istream& is, GiocoOca& g);
  friend std::ostream& operator<<(std::ostream& os, const GiocoOca& g);
public:
  GiocoOca();
  GiocoOca(const std::vector<int>& t, unsigned k);
  void Ricomincia();
  void DefinisciTabellone(const std::vector<int>& t);
  void DefinisciGiocatori(unsigned k);
  void EseguiMossa(unsigned d);
  int Vincitore() const { return vincitore; }
private:
  std::vector<int> tabellone; 
  std::vector<unsigned> posizione_giocatore; 
  unsigned num_giocatori;
  unsigned giocatore_di_turno;
  int vincitore; // -1 = nessun vincitore, la partita e' in corso
};
#endif
