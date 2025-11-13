#include <iostream>
#include <vector>
#include "Data.hpp"

using namespace std;

vector<Data> TraduciVettore(vector<unsigned>& v);

int main()
{
  vector<unsigned> v1{2,3,2021,4,5,2022,30,2,2021,31,11,2021,3,3,2020,4,5,2019,7,10};
  vector<Data> v2;
  unsigned i;
  
  v2 = TraduciVettore(v1);
  
  for (i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";
  cout << endl;
  
  return 0;
}

// Nota: il costruttore senza argomenti di Data restituisce una data convenzionale, che però non conosciamo 

vector<Data> TraduciVettore(vector<unsigned>& v)
{
  unsigned i;
  vector<Data> ris;
  Data rif;
  for (i = 0; i < v.size()-2; i+=3)
    {
      Data d(v[i],v[i+1],v[i+2]);
      if (d != rif)
        ris.push_back(d);
    }
  return ris;
}
