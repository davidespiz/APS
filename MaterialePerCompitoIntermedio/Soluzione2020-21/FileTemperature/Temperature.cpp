#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Data.hpp"

using namespace std;

double Estremo(const vector<double>& v, bool max)
{  // max_element e min_element sono di libreria
   // restituiscono un iteratore al massimo/minimo
   // con l'operatore * si ottiene il valore corrispondente
  if (max)
    return *max_element(v.begin(), v.end());
  else
    return *min_element(v.begin(), v.end());
}

pair<Data,vector<double>> MassimaEscursioneTermica(string nome_file)
{
  ifstream is(nome_file);
  Data d;
  vector<double> v;
  pair<Data,vector<double>> ris;
  double escursione, escursione_max = 0, temp;
  unsigned num, i;
  
  while(is >> d >> num)
    {
      for (i = 0; i < num; i++)
        {
          is >> temp;
          is.get();
          v.push_back(temp);
        }
      escursione = Estremo(v,true) - Estremo(v,false);
      if (escursione > escursione_max)
        {
          escursione_max = escursione;
          ris = make_pair(d,v);
        } 
      v.clear();  // equivalente a v.resize(0)
    }
  return ris; 
}

int main(int argc, char* argv[])
{
  pair<Data,vector<double>> temperature;
 
  if (argc < 2)
    {
      cerr << "Inserire il nome del file in input" << endl;
      return 1;
    }
  temperature =  MassimaEscursioneTermica(argv[1]);
  cout << "La data della massima esursione e' " << temperature.first << endl;

  return 0;
}
