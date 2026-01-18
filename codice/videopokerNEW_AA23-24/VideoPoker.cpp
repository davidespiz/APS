// File Videopoker.cpp
#include <iostream>
#include <iomanip>  // Per setf, setw e setfill
#include <cassert>
#include "Mazzo.hpp"
#include "Mano.hpp"
#include "VideoPoker.hpp"

VideoPoker::VideoPoker(unsigned c)
  :  vincite{0,0,1,2,3,4,6,9,25,50,800}, mano(&mazzo)
{
  credito = c;
}

void VideoPoker::DistribuisciMano()
{
  if (CarteNelMazzo() < 10)
	mazzo.Rimescola();
  mano.Distribuisci();
}

void VideoPoker::CambiaCarte()
{
  cout << "---- Cambio carte ----" << endl;
  for (unsigned i = 0; i < 5; i++)
  {
    char ch;
    cout << "Cambio carta " << i+1 << "? (s/n) : ";
    cin >> ch;
    if (tolower(ch) == 's' || tolower(ch) == 'y') // 'S' e 's' sono SI, il resto e' NO
      mano.CambiaCarta(i);
  }
}

void VideoPoker::Punta()
{
  unsigned puntata_proposta;
  do
    {
      cout << "Crediti : " << credito << endl 
           << "Quanto punti? : ";
      cin >> puntata_proposta;
      if (puntata_proposta == 0)
         cout << "Puntata impossibile!" << endl;        
      else if (puntata_proposta > credito) 
         cout << "Credito insufficiente!" << endl;
    }
  while (puntata_proposta > credito || puntata_proposta == 0);
  credito -= puntata_proposta;
  puntata = puntata_proposta;
}

void VideoPoker::AggiungiCredito()
{
  unsigned credito_aggiunto;
  cout << "Quanto credito vuoi aggiungere? : ";
  cin >> credito_aggiunto;
  credito += credito_aggiunto;
}

void VideoPoker::AggiungiVincita()
{
  credito += puntata * vincite[static_cast<unsigned>(mano.Valuta())];
}

void VideoPoker::Gioca()
{
  Punta();
  DistribuisciMano();
  cout << "Situazione iniziale" << endl << mano << endl;
  CambiaCarte();
  cout << "Situazione finale" << endl << mano << endl;
  AggiungiVincita();
}
 
void VideoPoker::VediVincite() const
{
  cout << "Vincite dei punti:" << endl;
  for (unsigned i = 0; i < vincite.size(); i++)
    { // al fine di ottenere la visualizzazione nel formato desiderato 
      // si utilizzano i manipolatori degli stream setf, setfill 
      // e setw (non compresi nel programma del corso)
      cout.setf(ios::left, ios::adjustfield);      
      cout << setfill('.') << setw(25) << mano.NomePunto(Punto(i)); 
      cout.setf(ios::right, ios::adjustfield);      
      cout << setfill('.') << setw(3) << vincite[i] << endl;
    }
}

ostream& operator <<(ostream& os, const VideoPoker& vp)
{ // utilizzato solo per debugging
  os << "Stampa del VideoPoker" << endl;
  os << "Mazzo: " << vp.mazzo << endl;
  os << "Mano: " << vp.mano << endl;
  os << "Crediti: " << vp.credito << endl;
  os << "Vincite dei punti:" << endl;
  for (unsigned i = 0; i < vp.vincite.size(); i++)
    os << vp.mano.NomePunto(Punto(i)) << " " << vp.vincite[i] << endl;
  return os;
}
