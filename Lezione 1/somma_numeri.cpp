#include <iostream>
using namespace std;
const int NUMERI = 10;

int main()
{
    int numero, somma = 0;
  unsigned i;
  
  cout << "Inserisci " << NUMERI << " numeri interi: ";
  for (i = 0; i < NUMERI; i++)
  {
    cin >> numero;   // scanf("%d",&numero)
	somma += numero;
  }
  cout << "La somma vale " << somma << endl;
  return 0;
}