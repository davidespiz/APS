#include "teatro.hpp"
#include <stdexcept>
using namespace std;

void Teatro::RegistraSpettatore(Persona* p)
{
   if (CercaPersona(p) != -1)
      throw invalid_argument("Persona già registrata!");
   if (p->Età() < 18)
      throw invalid_argument("La persona è minorenne!");
   spettatori.push_back(p);
}

int Teatro::CercaPersona(Persona* p) const
{
   for (unsigned i = 0; i < spettatori.size(); i++)
      if (spettatori[i] == p)
         return i;
   return -1;
}

void Teatro::ProgrammaSpettacolo(Spettacolo* s, const Data& g)
{
   if (g < inizio || fine < g)
      throw invalid_argument("Data fuori stagione!");
   if (GiornoLibero(g) != -1)
      throw invalid_argument("Giorno già occupato!");
   repliche.push_back(Replica(s, g));
}

int Teatro::GiornoLibero(const Data& g) const
{
   for (unsigned i = 0; i < repliche.size(); i++)
      if (repliche[i].giorno == g)
         return i;
   return -1;
}

void Teatro::AcquistaBiglietto(Persona* p, const Data& g)
{
   if (CercaPersona(p) == -1)
      throw invalid_argument("Persona non registrata!");
   if (GiornoLibero(g) == -1)
      throw invalid_argument("Giorno senza spettacolo!");
   if (BigliettiVenduti(g) >= capienza)
      throw invalid_argument("Teatro al completo!");
   if (CercaBigliettoSpettatore(p, g) != -1)
      throw invalid_argument("La persona ha già un biglietto per questo giorno!");
   biglietti.push_back(Biglietto(p, g));
}

unsigned Teatro::BigliettiVenduti(const Data& g) const
{
   int numBiglietti = 0;
   for (unsigned i = 0; i < biglietti.size(); i++)
      if (biglietti[i].giorno == g)
         numBiglietti++;
   return numBiglietti;
}

int Teatro::CercaBigliettoSpettatore(Persona* p, const Data& g) const
{
   for (unsigned i = 0; i < biglietti.size(); i++)
      if (biglietti[i].giorno == g && biglietti[i].persona == p)
         return i;
   return -1;
}

bool Teatro::CancellaBiglietto(Persona* p, const Data& g)
{
   if (CercaPersona(p) == -1)
      throw invalid_argument("Persona non registrata!");
   int i = CercaBigliettoSpettatore(p, g);
   if (i == -1)
      return false;
   biglietti.erase(biglietti.begin() + i);
   return true;
}

ostream& operator<<(ostream& os, const Teatro& t)
{
   os << t.Nome() << ": (Capienza: " << t.Capacità() << ", Stagione: " << t.Inizio() << " - " << t.Fine() << ")" << endl;
   os << "Spettatori registrati: " << t.NumSpettatori() << endl;
   for (unsigned i = 0; i < t.NumSpettatori(); i++)
      os << "  - " << *t.spettatori[i] << endl;
   os << "Spettacoli programmati: " << t.NumRepliche() << endl;
   int indexReplica;
   for (Data d = t.Inizio(); d < t.Fine(); ++d)
      if ((indexReplica = t.GiornoLibero(d)) != -1)
         os << "  - " << *t.GetSpettacolo(indexReplica) << " (" << d << ")" << endl;
   os << "Biglietti venduti: " << t.NumBiglietti() << endl;
   for (unsigned i = 0; i < t.NumBiglietti(); i++)
      os << "  - " << *t.GetBigliettoSpettatore(i) << " per il giorno " << t.GetBigliettoGiorno(i) << endl;
   return os;
}