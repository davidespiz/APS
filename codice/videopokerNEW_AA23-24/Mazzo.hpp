// File Mazzo.hpp
#ifndef MAZZO_HPP
#define MAZZO_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Carta.hpp"
#include "Random.hpp"

using namespace std;

class Mazzo
{ 
  friend ostream& operator<<(ostream&, const Mazzo&);
 public:
  Mazzo(unsigned p = 1);
  Carta PescaCarta();
  unsigned QuanteCarte() const { return mazzo.size(); }
  void Rimescola();
  const unsigned NUM_VALORI;
  const unsigned NUM_SEMI;
  const unsigned NUM_CARTE_PACCHETTO;
  const unsigned NUM_PACCHETTI;
 private:
  vector<Carta> mazzo;
};
#endif
