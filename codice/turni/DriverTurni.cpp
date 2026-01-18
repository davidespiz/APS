// File DriverTurni.cpp
#include <iostream>
#include "azienda.hpp"

bool PresenzaTurno(const Azienda& az, unsigned start, unsigned stop);
unsigned TotaleOreLavoro(const Azienda& az);

int main()
{
  unsigned dip, scelta, start, stop, indice_impiegato, indice_turno;
  std::string nome;
  Impiegato* p;
  Turno *t;

  std::cout << "Gestione turni aziendali" << std::endl;
  std::cout << "Numero massimo dipendenti : ";
  std::cin >> dip;
  
  Azienda az(dip);
  do 
    {
      std::cout << az;
      std::cout << "Quale operazione vuoi effettuare?\n"
           << "1: Inserimento impiegato\n"
           << "2: Inserimento turno\n"
           << "3: Inserimento assegnazione\n"
           << "4: Verifica presenza turno\n"
           << "5: Conta ore lavorate\n"
           << "0: Esci\n\n"
           << "Scelta:  ";
      std::cin >> scelta;
      std::cout << std::endl;
      switch (scelta)
        {
        case 1:          
          std::cout << "Nome : ";
          std::cin >> nome;
          p = new Impiegato(nome);
          az.Assumi(p);
          break;    
        case 2:
          std::cout << "Inizio turno : ";
          std::cin >> start;
          std::cout << "Fine turno : ";
          std::cin >> stop;          
          t = new Turno(start,stop);
          az.CreaTurno(t);
          break;
        case 3:
                  std::cout << "Quale impiegato (1 - " << az.Impiegati() << "): ";
                  std::cin >> indice_impiegato;
                  std::cout << "Quale turno (1 - " << az.Turni() << "): ";
                  std::cin >> indice_turno;
                  az.AssegnaTurno(az.VediImpiegato(indice_impiegato-1),az.VediTurno(indice_turno-1));
           break;
        case 4:
          std::cout << "Inizio turno : ";
          std::cin >> start;
          std::cout << "Fine turno : ";
          std::cin >> stop;          
          if (PresenzaTurno(az,start,stop))
            std::cout << "Il turno esiste" << std::endl;
          else
            std::cout << "Il turno non esiste" << std::endl;
          break;
        case 5:
          std::cout << "Ore totali lavorate : " << TotaleOreLavoro(az) << std::endl;
          break;
        }
    }
  while (scelta != 0);
}

bool PresenzaTurno(const Azienda& az, unsigned start, unsigned stop)
{
  for (unsigned i = 0; i < az.Turni(); i++)
    {
      if (az.VediTurno(i)->Start() == start 
          && az.VediTurno(i)->Stop() == stop)
        return true;
    }
  return false;
}

unsigned TotaleOreLavoro(const Azienda& az)
{
  unsigned conta = 0;
  for (unsigned i = 0; i < az.Assegnazioni(); i++)
    conta += az.VediAssegnazione(i).second->NumOre();
  return conta;
}
