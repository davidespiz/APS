// File DriverMazzo.cpp
#include <cstdlib>
#include "Mazzo.hpp"
#include "Mano.hpp"

int main(int argc, char* argv[])
{ 
  Mazzo d;
  Mano m(&d);
  vector<unsigned> frequenze(11,0);
  unsigned i, n;

  if (argc == 1)
    {
      cout << "Numero di tentativi: ";
      cin >> n;
    }
  else if (argc == 2)
    n = atoi(argv[1]);
  else
    {
      cout << "Utilizzo: " << argv[0] << " [numero tentativi]" << endl;
      exit(1);
    }

  for (i = 0; i < n; i++)
    {
      m.Distribuisci();
      frequenze[static_cast<unsigned>(m.Valuta())]++;
      d.Rimescola();
    }

  for (i = 0; i < 11; i++)
    cout << m.NomePunto(static_cast<Punto>(i)) << ": " << frequenze[i] << " volte (" 
         << (frequenze[i] * 100.0)/n << "%)" << endl;
}




