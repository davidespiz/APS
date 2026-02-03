#include "palestra.hpp"
#include "persona.hpp"
#include <iostream>
using namespace std;

int main()
{
   Palestra p("Palestra APS");
   // Creazione corsi
   Corso c1("Yoga", 20, 2, 18);  // titolo, max iscritti, giorno, ora
   Corso c2("Pilates", 15, 4, 19);
   Corso c3("Zumba", 25, 6, 17);
   Corso c4("Crossfit", 10, 4, 18);

   // Creazione istruttori
   Persona ist1("Alice", 30);
   Persona ist2("Bob", 25);
   Persona ist3("Carlo", 35);

   // Creazione clienti
   Persona cli1("Davide", 23);
   Persona cli2("Eva", 52);
   Persona cli3("Francesco", 40);
   Persona cli4("Giovanni", 33);
   Persona cli5("Anna", 27);
   Persona cli6("Maria", 29);
   Persona cli7("Silvia", 22);

   // Iscrizione clienti
   p.IscriviCliente(cli1, true);  // regolare
   p.IscriviCliente(cli2, false); // in prova
   p.IscriviCliente(cli3, false);  // in prova
   p.IscriviCliente(cli4, true); // in prova
   p.IscriviCliente(cli5, true);  // regolare
   p.IscriviCliente(cli6, false); // in prova
   p.IscriviCliente(cli7, true);  // regolare
   // p.IscriviCliente(cli1, true);  // già iscritto, genera eccezione

   // Assunzione istruttori
   p.AssumiIstruttore(ist1);
   p.AssumiIstruttore(ist2);
   p.AssumiIstruttore(ist3);
   p.AssumiIstruttore(ist2); // già assunto, non fa nulla

   // Attivazione corsi
   p.AttivaCorso(c1, c1.Giorno(), c1.Ora());
   p.AttivaCorso(c2, c2.Giorno(), c2.Ora());
   p.AttivaCorso(c3, c3.Giorno(), c3.Ora());
   p.AttivaCorso(c4, c4.Giorno(), c4.Ora());

   // Assegnazione istruttori ai corsi
   p.AssegnaIstruttore(c1, ist1);
   p.AssegnaIstruttore(c2, ist2);
   p.AssegnaIstruttore(c3, ist2);
   p.AssegnaIstruttore(c4, ist3); 

   // stesso giorno e ora di Pilates
   // Corso c4("Crossfit", 10, 4, 19);  
   // p.AttivaCorso(c4, c4.Giorno(), c4.Ora());

   // Iscrizione clienti ai corsi
   p.IscriviAlCorso(cli1, c1);   // Davide si iscrive a Yoga
   p.IscriviAlCorso(cli1, c2);   // Davide si iscrive a Pilates
   p.IscriviAlCorso(cli2, c1);   // Eva si iscrive a Yoga
   p.IscriviAlCorso(cli2, c3);   // Eva si iscrive a Zumba
   p.IscriviAlCorso(cli3, c2);   // Franceso si iscrive a Pilates
   p.IscriviAlCorso(cli4, c3);   // Giovanni si iscrive a Zumba
   p.IscriviAlCorso(cli4, c1);   // Giovanni si iscrive a Yoga
   p.IscriviAlCorso(cli4, c4);   // Giovanni si iscrive a Crossfit
   p.IscriviAlCorso(cli5, c2);   // Anna si iscrive a Pilates
   p.IscriviAlCorso(cli6, c1);   // Maria si iscrive a Yoga
   p.IscriviAlCorso(cli7, c3);   // Silvia si iscrive a Zumba
   

   cout << p;

   // Prova numero iscritti a corso
   // cout << "Numero iscritti a " << p.GetCorso(0) << ": " << p.IscrittiCorso(p.GetCorso(0)) << endl << endl;

   // p.PerfezionaIscrizione(cli1); // Già regolare, genera eccezione
   Persona ist4("Luca", 17); 
   Persona ist5("Marco", 19);
   //p.AssumiIstruttore(ist4); // non maggiorenne, genera eccezione
   //p.AssegnaIstruttore(c1, ist5); // non è assunto dalla palestra, genera eccezione
   
   // Modifiche di prova
   p.IscriviAlCorso(cli2, c2);   // Eva era in prova, ora si iscrive a Pilates
   p.AssegnaIstruttore(c1, ist3); // cambio istruttore di Yoga
   p.PerfezionaIscrizione(cli3); // Francesco da in prova a regolare
   p.IscriviAlCorso(cli3, c3);   // Francesco ora si iscrive a Zumba
   cout << endl << endl << "Modifiche: " << endl << p;
   return 0;
}