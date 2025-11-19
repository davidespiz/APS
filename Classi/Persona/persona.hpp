#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "data.hpp"
using namespace std;

#ifndef PERSONA
#define PERSONA

class Persona
{
   friend istream& operator>>(istream& is, Persona& p);
   friend ostream& operator<<(ostream& os, const Persona& p);
   public:
      Persona(){}
      Persona(string n, string c, Data d, string city); 
      string Nome() const { return nome; }
      string Cognome() const { return cognome; }
      Data DataNascita() const { return data_nascita; }
      string CittaNascita() const { return citta_nascita; }
   private:
      string nome;
      string cognome;
      Data data_nascita;
      string citta_nascita;

};

void LeggiPersone(vector<Persona>& v, const string& nome_file);
pair<string, unsigned> NomeFrequente(const vector<Persona>& v);
void OrdinaFile(const string& nome_file);

#endif