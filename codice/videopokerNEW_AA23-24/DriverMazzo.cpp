// File DriverMazzo.cpp
#include "Mazzo.hpp"

int main()
{ 
  unsigned carte, pacchetti, i;

  cout << "Quante pacchetti compongono il mazzo : ";
  cin >> pacchetti;
  Mazzo m(pacchetti);
  cout << "Quante carte vuoi pescare : ";
  cin >> carte;
  for (i = 0; i < carte; i++)
    cout << "Pesco la carta: " << m.PescaCarta() << endl;
  cout << "Mazzo residuo: " << endl << m << endl;
  m.Rimescola();
  cout << "Mazzo completo: " << endl << m << endl;
  return 0;
}
