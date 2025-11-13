// File Poli.cpp
#include "Poli.hpp"

int main()
{
  Polinomio p1(2.3,5), p2(1.22), p3;

  cout << "Test costruttori e operatore <<" << endl;
  cout << "p1 : " << p1 << endl;
  cout << "p2 : " << p2 << endl;
  cout << "p3 : " << p3 << endl;
  cout << endl << endl;
 
  cout << "Test funzione Coefficiente" << endl;
  for (int i = 0; i < 10; i++)
    cout << p1.Coefficiente(i) << ' ';
  cout << endl << endl;

  cout << "Test operatore +" << endl;
  p3 = Polinomio(1.3,5) + Polinomio(4.5,7) + Polinomio(2.43,1);
  cout << "P1 = " << p1 << endl;
  cout << "P2 = " << p2 << endl;
  cout << "P3 = " << p3 << endl;
  cout << "P2 + P3 = " << p2 + p3 << endl;
  cout << "P3 + P1 + P2 = " << p3 + p1 + p2 << endl;
  cout << "P3 + 5 = " << p3 + 5 << endl;
  cout << "6 + P2 = " << 6 + p2 << endl;

  cout << "Inserisci un polinomio: ";
  cin >> p1;
  cout << p1 << endl;
  for (unsigned i = 0; i < 10; i++)
	  cout << p1(i) << " ";
  cout << endl;
  

  return 0;
}
