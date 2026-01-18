// File DriverAnagrafe.cpp
#include <fstream>
#include "Anagrafe.hpp"

int main()
{
  Anagrafe anag("Test anagrafe");
  unsigned scelta,i,c,p,p1,p2;
  Data data_nascita, data_elezioni;
  std::vector<Persona*> test_persone(7);
  std::vector<Comune*> test_comuni(5);

  test_comuni[0] = new Comune("Udine","UD");
  test_comuni[1] = new Comune("Gorizia","GO");
  test_comuni[2] = new Comune("Fagagna","UD");
  test_comuni[3] = new Comune("Monfalcone","GO");
  test_comuni[4] = new Comune("Magnano in riviera","UD");

  test_persone[0] = new Persona("Mario","Rossi",'m',Data(3,2,2001),"San Paolo (Brasile)", test_comuni[0]);
  test_persone[1] = new Persona("Maria","Rossi",'f',Data(3,2,2001),"San Paolo (Brasile)", test_comuni[1]);
  test_persone[2] = new Persona("Giuseppe","Rossi",'m',Data(21,4,1970),"Milano", test_comuni[1]);
  test_persone[3] = new Persona("Giuseppe","Gialli",'m',Data(20,6,1979),"Milano", test_comuni[2]);
  test_persone[4] = new Persona("Paola","Verdi",'f',Data(1,2,1973),"Udine", test_comuni[2]);
  test_persone[5] = new Persona("Ugo","Marroni",'m',Data(2,12,1946),"Saskatoon (Saskatchewan, Canada)", test_comuni[3]);
  test_persone[6] = new Persona("Francesca","Blu",'f',Data(6,6,1952),"Udine", test_comuni[4]);

  // Crea uno stato iniziale
  anag.InserisciComune(test_comuni[0]);
  anag.InserisciComune(test_comuni[1]);
  anag.InserisciComune(test_comuni[2]);
  anag.InserisciComune(test_comuni[3]);
  anag.InserisciComune(test_comuni[4]);
  anag.InserisciPersona(test_persone[0]);
  anag.InserisciPersona(test_persone[1]);
  anag.InserisciPersona(test_persone[2]);
  anag.InserisciPersona(test_persone[3]);
  anag.InserisciPersona(test_persone[4]);
  anag.InserisciPersona(test_persone[5]);
  anag.InserisciPersona(test_persone[6]);
  anag.InserisciConiugio(test_persone[2], test_persone[4]);
  anag.InserisciGenitoreFiglio(test_persone[2], test_persone[0]);
  anag.InserisciGenitoreFiglio(test_persone[2], test_persone[1]);
  anag.InserisciGenitoreFiglio(test_persone[4], test_persone[0]);
  anag.InserisciGenitoreFiglio(test_persone[4], test_persone[1]);
  anag.InserisciGenitoreFiglio(test_persone[4], test_persone[3]);

  do
    {
      std::cout << anag << std::endl;
      std::cout << "Menu : " << std::endl
           << "  (1) Inserisci comune" << std::endl
           << "  (2) Elimina comune" << std::endl
           << "  (3) Inserisci persona" << std::endl
           << "  (4) Elimina persona" << std::endl
           << "  (5) Inserisci relazione coniugio" << std::endl
           << "  (6) Rimuovi relazione coniugio" << std::endl
           << "  (7) Inserisci relazione genitore-figlio" << std::endl
           << "  (8) Stato di famiglia" << std::endl
           << "  (9) Lista votanti" << std::endl
           << "  (0) Esci" << std::endl
           << " Scelta : ";
      std::cin >> scelta;
      switch (scelta)
        {
        case 1:
          {
            std::cout << "Comuni: " << std::endl;
            for (i = 0; i < test_comuni.size(); i++)
              std::cout << i << ": " << *(test_comuni[i]) << std::endl;
            std::cout << "Quale vuoi inserire (0-" << test_comuni.size()-1 << "): ";
            std::cin >> c;
            anag.InserisciComune(test_comuni[c]);
            std::cout << "Comune inserito" << std::endl;
            break;
          }
        case 2:
          {
            std::cout << "Comuni: " << std::endl;
            for (i = 0; i < test_comuni.size(); i++)
              std::cout << i  << ": " << *(test_comuni[i]) << std::endl;
            std::cout << "Quale vuoi eliminare (0-" << test_comuni.size()-1 << "): ";
            std::cin >> c;
            anag.EliminaComune(test_comuni[c]);
            std::cout << "Comune eliminato" << std::endl;
            break;
          }
        case 3:
          {
            std::cout << "Persone: " << std::endl;
            for (i = 0; i < test_persone.size(); i++)
              std::cout << i  << ": " << *(test_persone[i]) << std::endl;
            std::cout << "Quale vuoi inserire (0-" << test_persone.size()-1 << "): ";
            std::cin >> p;
            anag.InserisciPersona(test_persone[p]);
            std::cout << "Persona inserita" << std::endl;
            break;
          }
        case 4:
          {
            std::cout << "Persone: " << std::endl;
            for (i = 0; i < test_persone.size(); i++)
              std::cout << i  << ": " << *(test_persone[i]) << std::endl;
            std::cout << "Quale vuoi eliminare (0-" << test_persone.size()-1 << "): ";
            std::cin >> p;
            anag.EliminaPersona(test_persone[p]);
            std::cout << "Persona eliminata" << std::endl;
            break;
          }
        case 5:
          {
            std::cout << "Persone: " << std::endl;
            for (i = 0; i < test_persone.size(); i++)
              std::cout << i  << ": " << *(test_persone[i]) << std::endl;
            std::cout << "Quali vuoi associare (0-" << test_persone.size()-1 << "): ";
            std::cin >> p1 >> p2;
            anag.InserisciConiugio(test_persone[p1], test_persone[p2]);
            std::cout << "Coniugio inserito" << std::endl;
            break;
          }
        case 6:
          {
            std::cout << "Persone: " << std::endl;
            for (i = 0; i < test_persone.size(); i++)
              std::cout << i  << ": " << *(test_persone[i]) << std::endl;
            std::cout << "Quale legame vuoi rimuovere (0-" << test_persone.size()-1 << "): ";
            std::cin >> p1 >> p2;
            anag.InserisciDivorzio(test_persone[p1], test_persone[p2]);
            std::cout << "Coniugio rimosso" << std::endl;
            break;
          }
        case 7:
          {
            std::cout << "Persone: " << std::endl;
            for (i = 0; i < test_persone.size(); i++)
              std::cout << i  << ": " << *(test_persone[i]) << std::endl;
            std::cout << "Quali vuoi associare (0-" << test_persone.size()-1 << "): [genitore figlio]";
            std::cin >> p1 >> p2;
            anag.InserisciGenitoreFiglio(test_persone[p1], test_persone[p2]);
            std::cout << "Parentela inserita" << std::endl;
            break;
          }
        case 8:
          {
            std::cout << "Persone: " << std::endl;
            for (i = 0; i < test_persone.size(); i++)
              std::cout << i  << ": " << *(test_persone[i]) << std::endl;
            std::cout << "Quale vuoi vedere (0-" << test_persone.size()-1 << "): ";
            std::cin >> p;
            anag.StampaCertificato(test_persone[p]);
            break;
          }
        case 9:
          {
            std::cout << "Data elezioni : ";
            std::cin >> data_elezioni;
            anag.StampaVotanti(data_elezioni);
            break;                       
          }
        }
    }
  while (scelta != 0);              
  return 0;
}
 
