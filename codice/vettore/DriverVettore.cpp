// file DriverVettore.cpp
#include "VettoreCompatto.hpp"

VettoreCompatto Inverso(const VettoreCompatto& v);

int main(int argc, char* argv[])
{
  unsigned i, n;
  VettoreCompatto v;  
  
  if (argc > 2)
    {
      std::cerr << "Uso corretto: " << argv[0] << " [<Dimensione>]" << std::endl;
      exit(1);
    }
  else if (argc == 2)
    n = atoi(argv[1]);
  else
    {
      std::cout << "Dimensione del vettore: ";
      std::cin >> n;
    }
  // Inserisco degli elementi (con ripetizioni, per avere compattamento) 
  for (i = 0; i < n; i++)
    v.Inserisci(i/10);
  // Stampo il vettore per esteso: verifica dell'operatore []
  std::cout << "Vettore esteso: ";
  for (i = 0; i < n; i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;
  // Stampo della rappresentazione compatta
  std::cout << "Rappresentazione compatta: " << v << std::endl;
  // Elimino meta' degli elementi
  for (i = 0; i < n/2; i++)
    v.Elimina();  
  std::cout << "Rappresentazione compatta (dopo l'eliminazione della meta'" 
       <<" degli elementi): " << v << std::endl;
  std::cout << "Vettore inverso: " << Inverso(v) << std::endl;
  return 0;
}

VettoreCompatto Inverso(const VettoreCompatto& v)
{
  VettoreCompatto ris;
  for (int i = v.NumElem() - 1; i >= 0; i--)
    ris.Inserisci(v[i]);
  return ris;       
}
