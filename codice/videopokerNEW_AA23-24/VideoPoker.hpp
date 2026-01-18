// File VideoPoker.hpp
#ifndef VIDEOPOKER_HPP
#define VIDEOPOKER_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Mazzo.hpp"
#include "Mano.hpp"

class VideoPoker
{ 
  friend ostream& operator <<(ostream&, const VideoPoker&);
 public:
  VideoPoker(unsigned c = 100);
  void Gioca();
  void AggiungiCredito(); 
  unsigned Credito() const { return credito; }
  void VediVincite() const;
  unsigned CarteNelMazzo() const { return mazzo.QuanteCarte(); }
private:
  void DistribuisciMano();
  void CambiaCarte();
  void Punta();
  void AggiungiVincita();

  unsigned credito;
  unsigned puntata;
  vector<unsigned> vincite;
  Mazzo mazzo;
  Mano mano;
};
#endif






