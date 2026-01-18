#include "film.hpp"
using namespace std;

Film::Film(string t, int d)
{
   titolo = t;
   durata = d;
}

ostream& operator<<(ostream& os, const Film& f)
{
   os << f.titolo << " (" << f.durata << " minuti)";
   return os;
}