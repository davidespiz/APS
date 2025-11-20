#include "persona.hpp"
#include <algorithm>
#include <cstdlib>

Persona::Persona(string n, string c, Data d, string cn)
   : nome(n), cognome(c), data_nascita(d), citta_nascita(cn)
{}


istream& operator>>(istream& is, Persona& p)
{
   is.ignore(256, '-');    //ignora fino a -
   getline(is, p.nome, ',');
   is.get();
   getline(is, p.cognome);
   is >> p.data_nascita >> p.citta_nascita;

   return is;
}

ostream& operator<<(ostream& os, const Persona& p)
{
   os << "-" << p.nome << ", " << p.cognome << endl << p.data_nascita << ' ' << p.citta_nascita;
   return os;
}

void LeggiPersone(vector<Persona>& v, const string& nome_file)
{
   ifstream is(nome_file);
   Persona pers;
      
   while(is >> pers)
      v.push_back(pers);
   is.close();
}

void OrdinaFile(const string& nome_file)
{
   ifstream is(nome_file);
   vector<Persona> v;
   Persona pers;
      
   while(is >> pers)
      v.push_back(pers);
   is.close();                //devo chiuderlo priima di scrivere
   sort(v.begin(),v.end());
   
   ofstream os(nome_file);
   for (unsigned i = 0; i < v.size(); i++)
   {
      os << v[i] << endl;
      if(i != v.size())
         os << endl;
   }
   os.close();
}

pair<string, unsigned> NomeFrequente(const vector<Persona>& v)
{
   vector<pair<string, unsigned>> occ;
   unsigned max = 0, i, k;
   for(i = 0; i < v.size(); i++)
   {
      for(k = 0; k < occ.size(); k++)
         if(v[i].Nome() == occ[k].first)
         {
            occ[k].second++;
            break;
         }
      if(k == occ.size())
         occ.push_back(make_pair(v[i].Nome(), 1));
   }
   for(i = 0; i < occ.size(); i++)
      if(occ[i].second > occ[max].second)
         max = i;
   return occ[max];
}

bool operator<(const Persona& p1, const Persona& p2)
{
   return (p1.data_nascita < p2.data_nascita) || (p1.data_nascita == p2.data_nascita && p1.cognome < p2.cognome); 
}