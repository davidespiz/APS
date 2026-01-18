//file driver1.cpp
#include "video_noleggio.hpp"

int GiorniNoleggioRegista(const VideoNoleggio& vn, std::string r, std::vector <int> t);

int main()
{
  VideoNoleggio vn("My Home Movie");
  //CREAZIONE DI UNO STATO INIZIALE
  
  //Vettori utili a contenere le classi del driver
  std::vector <Film> driver_film;
  std::vector <Cliente> driver_clienti;
  
  //dichiarazione di alcuni film
  driver_film.push_back(Film("Bastardi senza gloria", "Quentin Tarantino", 2009));
  driver_film.push_back(Film("Kill Bill vol.1", "Quentin Tarantino", 2003));
  driver_film.push_back(Film("Sherlock Holmes", "Guy Ritchie", 2009));
  driver_film.push_back(Film("The Snatch", "Guy Ritchie", 2000));
  driver_film.push_back(Film("La guerra dei mondi", "Steven Spielberg", 2005));
  driver_film.push_back(Film("Prova a prendermi", "Steven Spielberg", 2002));
  driver_film.push_back(Film("The social network", "David Fincher", 2010));
  driver_film.push_back(Film("Fight Club", "David Fincher", 1999));
  driver_film.push_back(Film("Il curioso caso di Benjamin Button", "David Fincher", 2008));
  driver_film.push_back(Film("Inception", "Christopher Nolan", 2010));
  driver_film.push_back(Film("The Prestige", "Steven Spielberg", 2006));
	   
  //inserimenti di alcuni dei film dichiarati	   
  vn.InserisciFilm(&driver_film[0]);
  vn.InserisciFilm(&driver_film[1]);
  vn.InserisciFilm(&driver_film[2]);
  vn.InserisciFilm(&driver_film[3]);
  vn.InserisciFilm(&driver_film[4]);
  vn.InserisciFilm(&driver_film[5]);
	   
  //dichiarazione e inserimento di alcuni clienti
  driver_clienti.push_back(Cliente(1000, 50));  
  driver_clienti.push_back(Cliente(1001, 25));
  driver_clienti.push_back(Cliente(1002, 25));
  driver_clienti.push_back(Cliente(1003, 15));  
  driver_clienti.push_back(Cliente(1004, 25));
  driver_clienti.push_back(Cliente(1005, 25));
  		  
  vn.InserisciCliente(&driver_clienti[0]);
  vn.InserisciCliente(&driver_clienti[1]);
  vn.InserisciCliente(&driver_clienti[2]);
  vn.InserisciCliente(&driver_clienti[3]);
  
  //creazione di alcune copie dei film
  vn.CreaCopiaFilm("DVD", &driver_film[0]);
  vn.CreaCopiaFilm("BluRay", &driver_film[0]);
  vn.CreaCopiaFilm("DVD", &driver_film[1]);
  vn.CreaCopiaFilm("VHS", &driver_film[1]);
  vn.CreaCopiaFilm("DVD", &driver_film[2]);
  vn.CreaCopiaFilm("BluRay", &driver_film[2]);
  vn.CreaCopiaFilm("DVD", &driver_film[2]);
  vn.CreaCopiaFilm("VHS", &driver_film[3]);
  vn.CreaCopiaFilm("DVD", &driver_film[3]);
  vn.CreaCopiaFilm("DVD", &driver_film[4]);
  vn.CreaCopiaFilm("DVD", &driver_film[4]);
  vn.CreaCopiaFilm("VHS", &driver_film[5]);  
	
  //creazione di una lista di noleggi e restituzioni
  vn.NoleggioCopiaFilm(1, &driver_film[0], &driver_clienti[0]);
  vn.NoleggioCopiaFilm(1, &driver_film[1], &driver_clienti[0]);
  vn.NoleggioCopiaFilm(2, &driver_film[0], &driver_clienti[1]);
  vn.NoleggioCopiaFilm(1, &driver_film[2], &driver_clienti[1]);
  vn.NoleggioCopiaFilm(1, &driver_film[3], &driver_clienti[1]);
  vn.NoleggioCopiaFilm(2, &driver_film[1], &driver_clienti[2]);
  
  vn.RestituzioneCopiaFilm(1, &driver_film[0], 4);
  vn.RestituzioneCopiaFilm(1, &driver_film[1], 3);
  vn.RestituzioneCopiaFilm(2, &driver_film[0], 5);
  vn.RestituzioneCopiaFilm(2, &driver_film[1], 4);
  
  vn.NoleggioCopiaFilm(1, &driver_film[0], &driver_clienti[3]);
  vn.NoleggioCopiaFilm(1, &driver_film[1], &driver_clienti[3]);
  vn.NoleggioCopiaFilm(1, &driver_film[4], &driver_clienti[3]);
    
  //PARTE DEL DRIVER A MENU' 
  //dichiarazione delle variabili utili all'inserimento
  unsigned scelta, tariffa, ricarica, copia, film, i;
  int cliente;
  std::string regista, supporto, aux;
    
  do
    {
      std::cout << vn << std::endl;
      
      std::cout << "Menu : " << std::endl
	   << "  (1) Inserisci film" << std::endl
	   << "  (2) Inserisci cliente" << std::endl
	   << "  (3) Ricarica il credito a cliente" << std::endl
	   << "  (4) Crea una copia di un film" << std::endl
	   << "  (5) Noleggio di una copia" << std::endl
	   << "  (6) Restituzione di una copia" << std::endl
	   << "  (7) Calcola i giorni di noleggio di un dato regista" << std::endl
	   << "  (0) Esci" << std::endl
	   << " Scelta : ";
      std::cin >> scelta;
      switch (scelta)
	{
	case 1:
          {
            std::cout << std::endl << "Film: " << std::endl;
            
            for (i = 0; i < driver_film.size(); i++)
              std::cout << i << ": " << std::endl << driver_film[i] << std::endl;
            
            std::cout << "Quale si vuole inserire (0-" << driver_film.size()-1 << "): ";
            std::cin >> film;
            vn.InserisciFilm (&driver_film[film]);
            std::cout << "Film inserito" << std::endl;
            break;
          }
          
	case 2:
	  {
	    std::cout << std::endl << "Clienti: " << std::endl;
	    
	    for (i = 0; i < driver_clienti.size(); i++)
	      std::cout << i << ": " << std::endl << driver_clienti[i] << std::endl;
	    
	    std::cout << "Quale si vuole inserire (0-" << driver_clienti.size()-1 << "): ";
	    std::cin >> cliente;
	    vn.InserisciCliente (&driver_clienti[cliente]);
	    std::cout << "Cliente inserito" << std::endl;
	    break;
	  }
	  
	case 3:
	  {
	    std::cout << std::endl << "Clienti: " << std::endl;
	    
	    for (i = 0; i < vn.NumClienti(); i++)
	      std::cout << i << ": " << std::endl << *(vn.VediCliente(i)) << std::endl;
	    
	    std::cout << "Quale si vuole ricaricare (0-" << vn.NumClienti()-1 << "): ";
	    std::cin >> cliente;
	    std::cout << "Inserire l'importo della ricarica: ";
	    std::cin >> ricarica;
	    vn.VediCliente(cliente)->AggiungiCredito(ricarica);
	    std::cout << "Credito aggiunto" << std::endl;
	    break;
	  }
	  
	case 4:
	  {
	    std::cout << std::endl << "Film: " << std::endl;
	    
	    for (i = 0; i < vn.NumFilm(); i++)
	      std::cout << i << ": " << std::endl << *(vn.VediFilm(i)) << std::endl;
	    
	    std::cout << "Quale si vuole copiare (0-" << vn.NumFilm()-1 << "): ";
	    std::cin >> film;
	    std::cout << "Insere il tipo di supporto: " ;
	    std::cin >> supporto;
	    
	    vn.CreaCopiaFilm(supporto, vn.VediFilm(film));
	    std::cout << "Film copiato" << std::endl;
	    break;
	  }
	  
	case 5:
	  {
	    std::cout << std::endl << "Film disponibili: " << std::endl;
	    
	    for (i = 0; i < vn.NumFilm(); i++)
	      std::cout << i << ": " << std::endl << *(vn.VediFilm(i)) << std::endl;
	    
	    std::cout << "Quale si vuole noleggiare (0-" << vn.NumFilm()-1 << "): ";
	    std::cin >> film;
	    std::cout << "Inserire il numero della copia: " ;
	    std::cin >> copia;
	    
	    std::cout << std::endl << "Clienti: " << std::endl;
	    
	    for (i = 0; i < vn.NumClienti(); i++)
	      std::cout << i << ": " << std::endl << *(vn.VediCliente(i)) << std::endl;
	    
	    std::cout << "Inserire il cliente (0-" << vn.NumClienti()-1 << "): ";
	    std::cin >> cliente;
	    
	    vn.NoleggioCopiaFilm(copia, vn.VediFilm(film), vn.VediCliente(cliente));
	    std::cout << "Noleggio effettuato" << std::endl;
	    break;
	  }
	  
	case 6:
	  {
	    std::cout << std::endl << "Film disponibili: " << std::endl;
	    
	    for (i = 0; i < vn.NumFilm(); i++)
	      std::cout << i << ": " << std::endl << *(vn.VediFilm(i)) << std::endl;
	    
	    std::cout << "Quale vuoi restituire (0-" << vn.NumFilm()-1 << "): ";
	    std::cin >> film;
	    std::cout << "Inserisci il numero della copia: " ;
	    std::cin >> copia;
	    std::cout << "Inserisci la tariffa giornaliera per il noleggio: ";
	    std::cin >> tariffa;
	    
	    vn.RestituzioneCopiaFilm(copia, vn.VediFilm(film), tariffa);
	    std::cout << "Restituzione avvenuta" << std::endl;
	    break;
	  }
	  
	case 7:
	  {
	    std::vector <int> tessere_clienti;
	    
	    //acquisizione del regista
	    std::cout << std::endl << "Digita il regista (nome e cognome) e premi invio: ";
	    std::cin >> regista;
	    
	    while (std::cin.peek() != '\n')
	      {
		regista += " ";
		std::cin >> aux;
		regista += aux;
	      }
	    
	    std::cout << std::endl << "Creazione della lista di clienti..." << std::endl;
	    
	    do
	      {
		std::cout << std::endl << "Clienti: " << std::endl;
		
		for (int i = 0; i < (int) vn.NumClienti(); i++)
		  std::cout << i << ": " << std::endl << *(vn.VediCliente(i)) << std::endl;
		
		std::cout << "Quale vuoi inserire (0-" << vn.NumClienti()-1 << ") (-1 per uscire): ";
		std::cin >> cliente;
		
		if (cliente != -1)
		  tessere_clienti.push_back(vn.VediCliente(cliente)->NTessera() );
		
	      } while (cliente != -1);
	    
	    std::cout << std::endl << std::endl << "Il risultato e': " 
		 << GiorniNoleggioRegista (vn, regista, tessere_clienti) << " ore." << std::endl;
	    break;
	  }
	}
      
    } while (scelta != 0);	
  
  return 0;
}

//Funzione esterna richiesta per il progetto
int GiorniNoleggioRegista(const VideoNoleggio& vn, std::string r, 
			   std::vector <int> t)
{
  unsigned conta_giorni = 0, i, j;
  Data oggi;
  for (j = 0; j < vn.NumNoleggi(); j++)
    {
      if (vn.VediNoleggio(j).VediCopia()->VediFilm()->Regista() == r)
	for (i = 0; i < t.size(); i++)
	  {
	    if (vn.VediNoleggio(j).VediCliente()->NTessera() == t[i] )
	      {
		//se il noleggio è concluso
		if (vn.VediNoleggio(j).Restituito())
		  conta_giorni += vn.VediNoleggio(j).Restituzione() 
		    - vn.VediNoleggio(j).Inizio() + 1;
		else
		  conta_giorni += oggi - vn.VediNoleggio(j).Inizio() + 1;
	      }
	  }
    }
  return conta_giorni;
}
