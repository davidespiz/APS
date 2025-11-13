#include <fstream>
#include "Coda.hpp"

bool VerificaLunghezza(Coda c, unsigned n);

int main(int argc, char* argv[])
{
  Coda c;
  unsigned scelta;
  string nome_file;
  ifstream is;
  ofstream os;

  if (argc == 1)
    {
      cout << "Nome del file contenete lo stato attuale della coda : ";
      cin >> nome_file;
    }
  else
    nome_file = argv[1];

  is.open(nome_file);
  is >> c;
  is.close();
  do 
    {
      cout << "Coda : " << c << endl;
      cout << "Stato interno dell'oggetto: ";
      c.Stampa(cout);
      cout << "Operazione: " << endl
           << "  1. Push" << endl
           << "  2. Pop" << endl
           << "  3. Top" << endl
           << "  4. Verifica lunghezza" << endl
           << "  5. Verifica copie" << endl
           << "  0. Esci" << endl
           << "Scelta : ";
      cin >> scelta;

      switch(scelta)
        {
        case 1:
          {
            int elem;
            cout << "Elemento : ";
            cin >> elem;            
            c.Push(elem);
            break;
          }
        case 2:
          c.Pop();
          break;
        case 3:
          cout << "Elemento affiorante: " << c.Top() << endl;
          break;
        case 4:
          {
            int l;
            cout << "Lunghezza presunta: ";
            cin >> l;
            if (VerificaLunghezza(c,l))
              cout << "Lunghezza verificata" << endl;
            else
              cout << "Lunghezza minore" << endl;
            break;
          }       
        case 5:
          { // verifica il funzionamento delle funzioni speciali
            Coda c1 = c, c2;
            c1.Stampa(cout);
            c2.Stampa(cout);              
            c2 = c;
            c2.Stampa(cout);              
            break;
          }

        case 0:
          break;
        default:
          cout << "Scelta non valida" << endl;          
        }
    }
  while (scelta != 0);
  os.open(nome_file);
  os << c;    
}

bool VerificaLunghezza(Coda c, unsigned n)
{
  unsigned l = 0;
  while (!c.EstVuota())
    {
      c.Pop();
      l++;
    }
  return l >= n;
}
