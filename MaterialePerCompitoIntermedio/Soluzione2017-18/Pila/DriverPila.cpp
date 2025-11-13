#include <fstream>
#include "Pila.hpp"

int main(int argc, char* argv[])
{
  try
  {
  Pila p;
  unsigned scelta;
  string nome_file;
  ifstream is;
  ofstream os;
  int elem;

  if (argc == 1)
    {
      cout << "Nome del file contenente lo stato attuale della pila : ";
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
  is >> p;
  is.close();
  do 
    {
      cout << "Pila : " << p << endl;
      cout << "Operazione: " << endl
           << "  1. Push" << endl
           << "  2. Pop" << endl
           << "  3. Top" << endl
           << "  4. -=" << endl
           << "  0. Esci" << endl
           << "Scelta : ";
      cin >> scelta;

      switch(scelta)
        {
        case 1:
          {
            cout << "Elemento : ";
            cin >> elem;            
            p.Push(elem);
            break;
          }
        case 2:
          p.Pop();
          break;
        case 3:
          cout << "Elemento affiorante: " << p.Top() << endl;
		  break;
        case 4:
          {
            int elem;
            cout << "Elemento da eliminare: ";
            cin >> elem;
            p -= elem;
          }
        case 0:
          break;
        default:
          cout << "Scelta non valida" << endl;          
        }
    }
  while (scelta != 0);
  os.open(nome_file);
  os << p; 
  }
  catch (exception& e)
  {
	  cerr << e.what() << endl;
	  return 1;
  }
  return 0;  
}
