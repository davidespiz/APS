// File DriverGestione.cpp
#include "Pacchetto.hpp"  
#include "Versione.hpp"  
#include "Gestione.hpp"  
#include "../utils/Data.hpp"  

unsigned RitardoAggiornamenti(const Gestione& g);

int main()
{
  Data d(10,10,2011); 
  Pacchetto p1("Firefox","Browser di Mozilla"), 
    p2("Acroread","Lettore di file PDF di Adobe"),
    p3("Notepad++","Editor di testi");
  Versione v1(2,10,d,&p1), v2(3,10,d+3,&p1), v3(5,12,d+10,&p1), v4(2,100,d,&p2),
    v5(6,5,d,&p3), v6(8,6,d+10,&p3), v7(10,7,d+20,&p3), v8(12,9,d+30,&p3);
  Gestione g("Portatile 1",200);

  p3.InserisciDipendenza(&p2);
  p2.InserisciDipendenza(&p1);
  g.InserisciPacchettoDisponibile(&p1);
  g.InserisciPacchettoDisponibile(&p2);
  g.InserisciPacchettoDisponibile(&p3);
  g.InserisciVersioneDisponibile(&v1);
  g.InserisciVersioneDisponibile(&v2);
  g.InserisciVersioneDisponibile(&v3);
  g.InserisciVersioneDisponibile(&v4);
  g.InserisciVersioneDisponibile(&v5);
  g.InserisciVersioneDisponibile(&v6);
  g.InserisciVersioneDisponibile(&v7);
  g.InserisciVersioneDisponibile(&v8);

  std::cout << "Pacchetti: " << std::endl;
  std::cout << p1 << std::endl << p2 << std::endl<< p1 << std::endl << std::endl;

  std::cout << "Versioni: " << std::endl;
  std::cout << v1 << std::endl << v2 << std::endl << v3 << std::endl << v4 << std::endl
       << v5 << std::endl << v6 << std::endl << v7 << std::endl << v8 << std::endl << std::endl;

  std::cout << "Gestione senza installazioni: " << std::endl << g << std::endl;

  g.InstallaVersione(&v1);
  g.InstallaVersione(&v2);
  g.InstallaVersione(&v3);
  g.InstallaVersione(&v4);
  g.InstallaVersione(&v5);
  g.InstallaVersione(&v6);
  g.InstallaVersione(&v7);
  g.InstallaVersione(&v8);
  std::cout << "Gestione con installazioni: " << std::endl << g << std::endl;

  g.RimuoviVersione(&v3);
  g.RimuoviVersione(&v4);
  g.RimuoviVersione(&v8);
  std::cout << "Gestione nuovamente senza installazioni: " << std::endl << g << std::endl;

  g.InstallaVersione(&v1);
  g.InstallaVersione(&v3);
  g.InstallaVersione(&v4); // togliendo questa manca una dipendenza
  g.InstallaVersione(&v5);

  std::cout << "Gestione con installazioni vecchio: " << std::endl << g;
  std::cout << "Massimo ritardo di aggiornamento: " <<  RitardoAggiornamenti(g) << std::endl;
  std::cout <<  std::endl;
  return 0;
}

unsigned RitardoAggiornamenti(const Gestione& g)
{
  unsigned i, j, max = 0;
  int diff;
  Pacchetto* p;
  Data d;
  for (i = 0; i < g.VersioniInstallate(); i++)
    {
      p = g.VediVersioneInstallata(i)->VediPacchetto();
      d = g.VediVersioneInstallata(i)->Rilascio();
      for (j = 0; j < g.VersioniDisponibili(); j++)
	if (g.VediVersioneDisponibile(j)->VediPacchetto() == p)
	  {
	    diff = g.VediVersioneDisponibile(j)->Rilascio() - d;
	    if (diff > static_cast<int>(max))
	      max = diff;
	  }
    }
  return max;
}
