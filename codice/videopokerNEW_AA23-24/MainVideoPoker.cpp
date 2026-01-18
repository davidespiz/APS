// File MainVideopoker.cpp
#include <cstdlib>
#include "VideoPoker.hpp"

int main(int argc, char* argv[])
{
  unsigned credito_iniziale, scelta;        
  if (argc > 2)
    {
      cerr << "Uso corretto: " << argv[0] << " [<CreditoIniziale>]" << endl;
      exit(1);
    }  
  if (argc == 2)
    credito_iniziale = atoi(argv[1]);
  else // argc == 1
    credito_iniziale = 1000;
  VideoPoker vp(credito_iniziale);
  do
    {
	  // cout << vp << endl;
      cout << "Hai " << vp.Credito() << " crediti" << endl;
      cout << "Menu : " << endl
           << "  (1) Esegui una partita" << endl
           << "  (2) Aggiungi credito" << endl
           << "  (3) Vedi vincite" << endl
           << "  (0) Esci" << endl
           << " Scelta : ";
      cin >> scelta;
      switch (scelta)
        {
        case 1:
          vp.Gioca();
          break;
        case 2:
          vp.AggiungiCredito();
          break;
        case 3:
          vp.VediVincite();
          break;
        }
    }
 while (scelta != 0);     
 cout << "Grazie per aver giocato con noi!" << endl;
 return 0;
}
