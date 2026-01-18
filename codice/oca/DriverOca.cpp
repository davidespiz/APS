// File DriverOca.cpp
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "GiocoOca.hpp" 
#include "../utils/Random.hpp"

int PartitaGiocoOca(const std::vector<int>& tab, unsigned gioc, const std::vector<unsigned> &lanci);
void ProvaPartita();
void ProvaLancio();

int main()
{
  ProvaPartita();
  ProvaLancio();
  return 0;
}

void ProvaPartita()
{
  unsigned num_caselle, num_giocatori, i;
  int vincitore;
  std::cout << "Eseguo una partita del gioco dell'oca" << std::endl
       << "Numero di caselle del tabellone : ";
  std::cin >> num_caselle;
  std::vector<int> tabellone(num_caselle);
  std::cout << "Tabellone : ";
  for (i = 0; i < num_caselle; i++)
    std::cin >> tabellone[i];
  std::cout << "Numero giocatori: ";
  std::cin >> num_giocatori;
  
  std::cout << "Prova Funzione PartitaGiocoOca: Creo una sequenza di 1000 lanci\n";
  std::vector<unsigned> lanci(1000);
  for (i = 0; i < lanci.size(); i++)
    lanci[i] = Random(1,6);
  
  vincitore = PartitaGiocoOca(tabellone, num_giocatori, lanci);
  if (vincitore == -1)
    std::cout << "La partita non e' finita" << std::endl;
  else
    std::cout << "Il vincitore delle partita e' il giocatore numero " 
         << PartitaGiocoOca(tabellone, num_giocatori, lanci) << std::endl;
}

void ProvaLancio()
{
  std::cout << "Eseguo un lancio del gioco dell'oca partendo da una situazione letta da file" << std::endl;
  GiocoOca g;
  std::string nome_file;
  unsigned lancio;
  std::cout << "Nome file contenente una partita in corso : ";
  std::cin >> nome_file;
  std::ifstream is(nome_file.c_str());
  is >> g;
  is.close();
  std::cout << "Situazione corrente:" << std::endl;
  std::cout << g << std::endl;
  std::cout << "Lancio : ";
  std::cin >> lancio;
  g.EseguiMossa(lancio);
  std::cout << "Nuova situazione:" << std::endl;
  std::cout << g << std::endl;
}

int PartitaGiocoOca(const std::vector<int>& tab, unsigned gioc, 
		    const std::vector<unsigned> &lanci)
{
  GiocoOca gioco_oca(tab, gioc);
  for (unsigned i = 0; i < lanci.size(); i++)
  {
    std::cout << "E' uscito " << lanci[i] << std::endl;
    gioco_oca.EseguiMossa(lanci[i]);
    std::cout << "La situazione e' " << std::endl << gioco_oca << std::endl;
    if (gioco_oca.Vincitore() != -1)
      return gioco_oca.Vincitore();
  }
  std::cout << "Numero di lanci insufficiente a finire la partita";
  return -1;
}
  
 
