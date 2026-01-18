// File DriverMazzo.cpp
#include "Mazzo.hpp"
#include "Mano.hpp"

int main()
{ 
  unsigned num_carte, i, carta;
  Mazzo d;
  Mano m(&d);

  m.Distribuisci();
  cout << "Mano: " << m << endl;
  cout << "Quante carte vuoi cambiare: ";
  cin >> num_carte;
  for (i = 0; i < num_carte; i++)
    {
      cout << "Quale carta cambi (1-5): ";
      cin >> carta;
      m.CambiaCarta(carta-1);
    }  
  cout << "Mano " << m << endl;
  return 0;
}
