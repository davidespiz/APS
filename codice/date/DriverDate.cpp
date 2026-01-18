// File ManipolaDate.cpp
#include <iostream>
#include <stdexcept>
#include "ManipolaDate.hpp"

int main()
{
  unsigned g1, m1, a1, g2, m2, a2;

  cout << "Inserisci la prima data (giorno, mese ed anno): ";
  cin >> g1 >> m1 >> a1;

  DataSuccessiva(g1, m1, a1);
  // DataSuccessiva2(g1, m1, a1);
  // DataSuccessiva3(g1, m1, a1);

  cout << "Data successiva: "; 
  StampaData(g1,m1,a1); 
  cout << std::endl;

  do
    {
      cout << "Inserisci la prima data (giorno, mese ed anno): ";
      cin >> g1 >> m1 >> a1;
    }
  while (!DataValida(g1,m1,a1));

  do
    {
      cout << "Inserisci la seconda data (giorno, mese ed anno): ";
      cin >> g2 >> m2 >> a2;
    }
  while (!DataValida(g2,m2,a2));

  cout << "La distanza tra il ";
  StampaData(g1,m1,a1);
  cout << " e il ";
  StampaData(g2,m2,a2);
  cout << " e' di " << DistanzaTraDateBidirezionale(g1, m1, a1, g2, m2, a2) 
       << " giorni" << std::endl;
}
