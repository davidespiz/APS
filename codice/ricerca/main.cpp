//Driver Algoritmi di ricerca (RicercaEsaustiva, RicercaBinaria)
#include <cstdlib>
#include <ctime>
#include <iostream>

void InsertionSort(int v[], int length)
 {
  int k, j, x;
 
  for(k=1; k<length; k++)
   {
     x = v[k];
     j = k - 1;
     while(j >= 0 && v[j] > x)
      {
        v[j+1] = v[j];
        j--;
      }
     v[j+1] = x;
   }
 }

int RicercaEsaustiva(int sequenza[], unsigned dimensione, int chiave)
{
  unsigned i;
  for (i = 0; i < dimensione; i++)
    if (sequenza[i] == chiave)
     return i;
  return -1;
}

int RicercaBinaria(int sequenza[], int dimensione, int chiave)
{
 int ultimo = 0, primo = dimensione-1, mediana = dimensione;
 
 while(ultimo <= primo)
  {
   mediana = (primo + ultimo)/2;
     if(sequenza[mediana] == chiave)
        return mediana;
      else
      {
        if(sequenza[mediana] < chiave)
          ultimo = mediana+1;
        else
          primo = mediana-1;  
      }
  }        
  return -1;
}

int main(int argc, char* argv[])
{
  int i, chiave, dim = 1000;
  int* vet = new int[dim];

  for(i = 0; i < dim; i++)
    vet[i] = rand() % 1000;

  cout << "Vettore: " << std::endl;
  for(i = 0; i < dim; i++)
    cout << i << "-" << vet[i] << " ";
  cout << std::endl;

  chiave = rand() % 1000;
  cout << "Chiave: " << chiave << std::endl;

  cout << "Ricerca Esaustiva " << RicercaEsaustiva(vet, dim, chiave) << std::endl;
  // E' necessario prima ordinare la sequenza in modo crescente: 
  // usiamo l'algoritmo InsertionSort
  InsertionSort(vet, dim);

  cout << "Vettore ordinato: " << std::endl;
  for(i = 0; i < dim; i++)
    cout << vet[i] << " ";
  cout << std::endl;
  cout << "Ricerca Binaria " << RicercaBinaria(vet, dim, chiave) << std::endl;

  return 0;
}
