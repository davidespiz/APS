// File main.cpp
#include "campominato.hpp"

int main()
{
  unsigned dimensione, bombe, mosse = 0, scelta;
  int stato;
  std::cout << "Dimensione della scacchiera : ";
  std::cin >> dimensione;
  std::cout << "Numero di bombe : ";
  std::cin >> bombe;
  CampoMinato cm(dimensione,bombe);

  do
    {
      // std::cout << cm; //   da inserire solo per il debugging
      std::cout << "Sei in posizione " << cm.Posizione() << std::endl;
      std::cout << "Hai fatto " << mosse << " mosse" << std::endl;
      std::cout << "Hai ancora " << cm.ScoppiRimasti() << " scoppi" << std::endl;
      std::cout << "Cosa vuoi fare (1: esplora, 2: muovi, 0: esci) : ";
      std::cin >> scelta;
      if (scelta == 1)
        {
          int r;
          std::cout << "Raggio di esplorazione : ";
          std::cin >> r;
          std::cout << "Ci sono " << cm.Esplora(r) << " bombe nel raggio " << r << std::endl;
        }
      else if (scelta == 2)
        {
          char dir;
          std::cout << "Direzione (N,S,E,O) : ";
          std::cin >> dir;
          stato = cm.Muovi(dir);
          if (stato == -1)
            std::cout << "Mossa fuori scacchiera" << std::endl;
          if (stato == 1 || stato == 2)
            std::cout << "BUUUUUM" << std::endl;
          if (stato == 2 || stato == 3)
            break;
        }
      mosse++;
    }
  while (scelta != 0); 
  std::cout << cm << std::endl;
  if (stato == 2) 
    std::cout << "HAI PERSO!!" << std::endl;
  else if (stato == 3)
    std::cout << "HAI VINTO!!" << std::endl;
  else
    std::cout << "CIAO, CIAO " << std::endl;
}
