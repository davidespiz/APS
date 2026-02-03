#include "persona.hpp"
using namespace std;

Persona::Persona(std::string n, int e) 
   : nome(n), eta(e) 
{
         disponibilita.resize(7);  // 7 giorni della settimana
         for (int i = 0; i < 7; i++) 
            disponibilita[i].resize(22, 0);  // ore da 0 a 21, inizializzate a 0 (libere)
}

bool operator==(const Persona& p1, const Persona& p2) 
{
   return p1.nome == p2.nome && p1.eta == p2.eta && p1.disponibilita == p2.disponibilita;
}

bool Persona::Libero(int giorno, int ora) const
{
   giorno--; // adeguo giorno da 1-7 a 0-6
   if (disponibilita[giorno][ora] == 0)
         return true;
   return false;
}