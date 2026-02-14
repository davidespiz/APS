#include <iostream>
using namespace std;
#include "teatro.hpp"
#include "persona.hpp"
#include "data.hpp"

int IncassoGiornoMax(const Teatro& t, const Data& d);

int main()
{
   Teatro t("Teatro Nuovo Giovanni da Udine", 1230, Data(16, 2, 2026), Data(28, 2, 2026));
   Persona p1("Giulia", 18);
   Persona p2("Marco", 35);
   Persona p3("Francesca", 28);
   Persona p4("Luca", 41);
   Persona p5("Sofia", 19);
   Persona p6("Alessandro", 33);
   Persona p7("Chiara", 26);
   Persona p8("Matteo", 30);
   Persona p9("Elena", 45);
   Persona p10("Davide", 23);
   Persona p11("Martina", 27);
   Persona p12("Andrea", 52);
   Persona p13("Federica", 38);
   Persona p14("Giorgio", 61);
   Persona p15("Valentina", 29);

   t.RegistraSpettatore(&p1);
   t.RegistraSpettatore(&p2);
   t.RegistraSpettatore(&p3);
   t.RegistraSpettatore(&p4);
   t.RegistraSpettatore(&p5);
   t.RegistraSpettatore(&p6);
   t.RegistraSpettatore(&p7);
   t.RegistraSpettatore(&p8);
   t.RegistraSpettatore(&p9);
   t.RegistraSpettatore(&p10);
   t.RegistraSpettatore(&p11);
   t.RegistraSpettatore(&p12);
   t.RegistraSpettatore(&p13);
   t.RegistraSpettatore(&p14);
   t.RegistraSpettatore(&p15);

   // nome e costo
   Spettacolo s1("La Traviata", 45);
   Spettacolo s2("Il Barbiere di Siviglia", 38);
   Spettacolo s3("Aida", 50);
   Spettacolo s4("Rigoletto", 42);
   Spettacolo s5("La Bohème", 40);

   t.ProgrammaSpettacolo(&s1, Data(17, 2, 2026));
   t.ProgrammaSpettacolo(&s2, Data(19, 2, 2026));
   t.ProgrammaSpettacolo(&s3, Data(22, 2, 2026));
   t.ProgrammaSpettacolo(&s4, Data(25, 2, 2026));
   t.ProgrammaSpettacolo(&s5, Data(27, 2, 2026));

   // Repliche (Giorni liberi: 16, 20, 23, 26)
   t.ProgrammaSpettacolo(&s1, Data(18, 2, 2026));
   t.ProgrammaSpettacolo(&s2, Data(21, 2, 2026));
   t.ProgrammaSpettacolo(&s3, Data(24, 2, 2026));
   t.ProgrammaSpettacolo(&s5, Data(28, 2, 2026));

   // Acquisto biglietti
   // Giulia: 2 biglietti
   t.AcquistaBiglietto(&p1, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p1, Data(22, 2, 2026));

   // Marco: 6 biglietti
   t.AcquistaBiglietto(&p2, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p2, Data(18, 2, 2026));
   t.AcquistaBiglietto(&p2, Data(19, 2, 2026));
   t.AcquistaBiglietto(&p2, Data(22, 2, 2026));
   t.AcquistaBiglietto(&p2, Data(25, 2, 2026));
   t.AcquistaBiglietto(&p2, Data(28, 2, 2026));

   // Francesca: 4 biglietti
   t.AcquistaBiglietto(&p3, Data(18, 2, 2026));
   t.AcquistaBiglietto(&p3, Data(21, 2, 2026));
   t.AcquistaBiglietto(&p3, Data(24, 2, 2026));
   t.AcquistaBiglietto(&p3, Data(27, 2, 2026));

   // Luca: 3 biglietti
   t.AcquistaBiglietto(&p4, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p4, Data(22, 2, 2026));
   t.AcquistaBiglietto(&p4, Data(28, 2, 2026));

   // Sofia: 5 biglietti
   t.AcquistaBiglietto(&p5, Data(19, 2, 2026));
   t.AcquistaBiglietto(&p5, Data(21, 2, 2026));
   t.AcquistaBiglietto(&p5, Data(24, 2, 2026));
   t.AcquistaBiglietto(&p5, Data(27, 2, 2026));
   t.AcquistaBiglietto(&p5, Data(28, 2, 2026));

   // Alessandro: 2 biglietti
   t.AcquistaBiglietto(&p6, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p6, Data(25, 2, 2026));

   // Chiara: 6 biglietti
   t.AcquistaBiglietto(&p7, Data(18, 2, 2026));
   t.AcquistaBiglietto(&p7, Data(19, 2, 2026));
   t.AcquistaBiglietto(&p7, Data(22, 2, 2026));
   t.AcquistaBiglietto(&p7, Data(24, 2, 2026));
   t.AcquistaBiglietto(&p7, Data(27, 2, 2026));
   t.AcquistaBiglietto(&p7, Data(28, 2, 2026));

   // Matteo: 4 biglietti
   t.AcquistaBiglietto(&p8, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p8, Data(19, 2, 2026));
   t.AcquistaBiglietto(&p8, Data(24, 2, 2026));
   t.AcquistaBiglietto(&p8, Data(27, 2, 2026));

   // Elena: 3 biglietti
   t.AcquistaBiglietto(&p9, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p9, Data(22, 2, 2026));
   t.AcquistaBiglietto(&p9, Data(25, 2, 2026));

   // Davide: 5 biglietti
   t.AcquistaBiglietto(&p10, Data(18, 2, 2026));
   t.AcquistaBiglietto(&p10, Data(21, 2, 2026));
   t.AcquistaBiglietto(&p10, Data(22, 2, 2026));
   t.AcquistaBiglietto(&p10, Data(25, 2, 2026));
   t.AcquistaBiglietto(&p10, Data(28, 2, 2026));

   // Martina: 2 biglietti
   t.AcquistaBiglietto(&p11, Data(19, 2, 2026));
   t.AcquistaBiglietto(&p11, Data(27, 2, 2026));

   // Andrea: 6 biglietti
   t.AcquistaBiglietto(&p12, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p12, Data(18, 2, 2026));
   t.AcquistaBiglietto(&p12, Data(21, 2, 2026));
   t.AcquistaBiglietto(&p12, Data(24, 2, 2026));
   t.AcquistaBiglietto(&p12, Data(25, 2, 2026));
   t.AcquistaBiglietto(&p12, Data(28, 2, 2026));

   // Federica: 4 biglietti
   t.AcquistaBiglietto(&p13, Data(18, 2, 2026));
   t.AcquistaBiglietto(&p13, Data(21, 2, 2026));
   t.AcquistaBiglietto(&p13, Data(22, 2, 2026));
   t.AcquistaBiglietto(&p13, Data(27, 2, 2026));

   // Giorgio: 3 biglietti
   t.AcquistaBiglietto(&p14, Data(19, 2, 2026));
   t.AcquistaBiglietto(&p14, Data(22, 2, 2026));
   t.AcquistaBiglietto(&p14, Data(28, 2, 2026));

   // Valentina: 5 biglietti
   t.AcquistaBiglietto(&p15, Data(17, 2, 2026));
   t.AcquistaBiglietto(&p15, Data(21, 2, 2026));
   t.AcquistaBiglietto(&p15, Data(24, 2, 2026));
   t.AcquistaBiglietto(&p15, Data(25, 2, 2026));
   t.AcquistaBiglietto(&p15, Data(27, 2, 2026));

   // Cancellazione biglietti
   t.CancellaBiglietto(&p1, Data(17, 2, 2026));
   t.CancellaBiglietto(&p2, Data(18, 2, 2026));
   t.CancellaBiglietto(&p5, Data(28, 2, 2026));
   t.CancellaBiglietto(&p7, Data(19, 2, 2026));
   t.CancellaBiglietto(&p12, Data(21, 2, 2026));

   // Test eccezioni
   Persona minorenne("Luigi", 16);
   Persona nonRegistrata("Paolo", 30);

   // RegistraSpettatore: "Persona già registrata!"
   try { t.RegistraSpettatore(&p1); } catch (const invalid_argument& e) {}

   // RegistraSpettatore: "La persona è minorenne!"
   try { t.RegistraSpettatore(&minorenne); } catch (const invalid_argument& e) {}

   // ProgrammaSpettacolo: "Data fuori stagione!"
   try { t.ProgrammaSpettacolo(&s1, Data(1, 1, 2026)); } catch (const invalid_argument& e) {}

   // ProgrammaSpettacolo: "Giorno già occupato!"
   try { t.ProgrammaSpettacolo(&s2, Data(17, 2, 2026)); } catch (const invalid_argument& e) {}

   // AcquistaBiglietto: "Persona non registrata!"
   try { t.AcquistaBiglietto(&nonRegistrata, Data(17, 2, 2026)); } catch (const invalid_argument& e) {}

   // AcquistaBiglietto: "Giorno senza spettacolo!"
   try { t.AcquistaBiglietto(&p1, Data(16, 2, 2026)); } catch (const invalid_argument& e) {}

   // AcquistaBiglietto: "La persona ha già un biglietto per questo giorno!"
   try { t.AcquistaBiglietto(&p1, Data(22, 2, 2026)); } catch (const invalid_argument& e) {}

   // CancellaBiglietto: "Persona non registrata!"
   try { t.CancellaBiglietto(&nonRegistrata, Data(17, 2, 2026)); } catch (const invalid_argument& e) {}

   cout << t;

   // Incasso massimo il 22 febbraio 2026: 50 euro * 8 biglietti = 400 euro
   cout << "Incasso massimo per giorno: " << IncassoGiornoMax(t, Data(16, 2, 2026)) << " euro" << endl;
}

int IncassoGiornoMax(const Teatro& t, const Data& d)
{
   unsigned max = 0, prezzo;
   int indexReplica;
   for (Data g = d; g < t.Fine(); ++g)
   {
      indexReplica = t.GiornoLibero(g);
      if (indexReplica != -1)
      {
         prezzo = t.GetSpettacolo(indexReplica)->Costo();
         max = max > prezzo * t.BigliettiVenduti(g) ? max : prezzo * t.BigliettiVenduti(g);
      }
   }
   return max;
}