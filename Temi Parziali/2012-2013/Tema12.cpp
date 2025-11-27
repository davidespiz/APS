#include <iostream>
using namespace std;

bool PilaOrdinata(const Pilia& p)
{
   if(p.Top() == -1 || p.Top() == 0)
      return 0;
   for(int i = 0; i < p.Top() - 1; i++)
      if(p.vet[i] > p.vet[i + 1])
         return 0;
   return 1;
}

unsigned ModificaAppuntamenti(const string& nome_file)
{
   unsigned max = 0;
   ifopen is(nome_file);
   ofstream os;
   string nome;
   Data data, oggi;
   vector<pair<string,Data>> v;

   while(is >> nome >> data)
      if(data >= oggi)
      {
         v.push_back(make_pair(nome, data));
         if(max < data - oggi)
            max = data - oggi;
      }
   is.close();
   os.open(nome_file);
   for(unsigned i = 0; i < v.size(); i++)
   {
      os << v.first << ' ' << v.second;
      if(i != v.size())
         os << endl;
   }
   os.close();
   return max;
}