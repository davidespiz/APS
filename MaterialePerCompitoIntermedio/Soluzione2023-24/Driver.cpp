#include <string>
#include <fstream>
#include "Vettore.hpp"

int main(int argc, char* argv[])
{
  Vettore v;
  string nome_file;
  ifstream is;
  ofstream os;

  if (argc == 1)
    {
      cout << "Nome del file contenente lo stato attuale del vettore : ";
      cin >> nome_file;
    }
  else if (argc == 2)
    nome_file = argv[1];
  else
    {
      cerr << "Numero sbagliato di parametri" << endl
	       << "Utilizzo:" << endl
	       << argv[0] << endl
	       << argv[0] << " <NomeFile>" << endl;
      return 1;
    }
  is.open(nome_file);
  if (!is)
  {
	 throw runtime_error ("Non riesco ad aprire il file " + nome_file); 
  }
  is >> v;
  is.close();
  cout << v << endl;  
  
  v.Set(3,-14.2); 
  v.Set(6,9.43); 
  v.Set(10,-1.01); 
  
  cout << v[3] << " " << v[6] << " " << v[12] << endl;
  cout << v << endl;  

  v.Set(6,0.33); 
  v.Set(10,-21.8); 
  v.Set(13,1.66); 

  cout << v[3] << " " << v[6] << " " << v[12] << endl;
  cout << v << endl;  
 
  return 0;  
}
  