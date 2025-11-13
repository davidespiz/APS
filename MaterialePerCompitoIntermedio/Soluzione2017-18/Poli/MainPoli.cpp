// File Poli.cpp
#include "Poli.hpp"
#include <vector>
#include <fstream>
#include <cmath>

bool ControllaValore(string nome_file, double p, double eps);

int main(int argc, char* argv[])
{
  const double eps = 0.00001;
  double x; 
  if (argc == 2)
    {
      cout << "Inserisci punto: ";
      cin >> x;
    }
  else if (argc == 3)
    {
      x = atof(argv[2]);
    }
  else
    {
      cerr << "Numero di parametri errato:" << endl
	       << "Uso corretto: " << argv[0] 
		   << " <nome_file> [punto]" << endl;
      return 1;
    }
  
  if (ControllaValore(argv[1], x, eps))
    cout << "SI";
  else
    cout << "NO";
  return 0;
}

bool ControllaValore1(string nome_file, double p, double eps)
{ // versione 1, con vettore di Polinomi
  vector<Polinomio> v;
  Polinomio pol;
  ifstream is(nome_file);
  unsigned i, j;
  
  while (is >> pol)
     v.push_back(pol);
  is.close();
	
  for (i = 0; i < v.size()-1; i++)
    for (j = i+1; j < v.size(); j++)
	  if (abs(v[i](p) - v[j](p)) <= eps)
	    return true;
  return false;
}

bool ControllaValore(string nome_file, double p, double eps)
{ // versione 2, con vettore di valori (double) e lettura/controllo unificati
  vector<double> v;
  Polinomio pol;
  ifstream is(nome_file);
  unsigned i;
  double val;
  
  while (is >> pol)
  {
	 val = pol(p);
     for (i = 0; i < v.size(); i++)
       if (abs(val - v[i]) < eps)
         return true;
     v.push_back(val);	 
  }
  return false;
}
