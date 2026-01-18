#include "prenotazione.hpp"
using namespace std;

Prenotazione::Prenotazione(string nome_p, int num_p)
{
   nome_prenotante = nome_p;
   numero_posti = num_p;
}

ostream& operator<<(ostream& os, const Prenotazione& p)
{
   os << p.nome_prenotante << " " << p.numero_posti;
   return os;
}