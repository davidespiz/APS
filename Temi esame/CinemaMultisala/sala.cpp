#include "sala.hpp"
using namespace std;

Sala::Sala(string n, int p)
{
   nome = n;
   posti = p;
}

ostream& operator<<(ostream& os, const Sala& s)
{
   os << s.nome << " (" << s.posti << " posti)";
   return os;
}