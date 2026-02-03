#include "palestra.hpp"
#include <stdexcept>
#include <string>
using namespace std;

// Costruttori
Palestra::Palestra(string nome) 
   : nome(nome) {
}

Corso::Corso(std::string t, int max, int g, int o)
{
   titolo = t;
   maxIscritti = max;
   giorno = g;
   ora = o;
   istruttore = nullptr;
}

// Metodi Palestra
void Palestra::IscriviCliente(const Persona& p, bool b) 
{
   for (unsigned i = 0; i < clienti.size(); i++) 
      if (clienti[i].persona == &p)
         throw invalid_argument("Cliente già iscritto");

   Cliente c;
   c.tipoIscrizione = b ? Iscrizione::Regolare : Iscrizione::InProva;   //se b è true allora regolare altrimenti in prova
   c.persona = const_cast<Persona*>(&p);     // devo convertire da const Persona* a Persona*
   clienti.push_back(c);
}

void Palestra::PerfezionaIscrizione(const Persona& p) 
{
   for (unsigned i = 0; i < clienti.size(); i++) 
      if (clienti[i].persona == &p) 
      {
         if (clienti[i].tipoIscrizione == Iscrizione::Regolare)
            throw invalid_argument("Cliente già regolare");
         clienti[i].tipoIscrizione = Iscrizione::Regolare;
         return;
      }
   throw invalid_argument("Cliente non trovato");
}

void Palestra::AssumiIstruttore(const Persona& p) 
{
   for (unsigned i = 0; i < istruttori.size(); i++) 
      if (istruttori[i].persona == &p)
         return;  // Istruttore già assunto

   if (p.Eta() < 18)
      throw invalid_argument("Istruttore deve essere maggiorenne");

   Istruttore i;
   i.persona = const_cast<Persona*>(&p);     // devo convertire da const Persona* a Persona*
   istruttori.push_back(i);
}

void Palestra::AttivaCorso(const Corso& c, int g, int o)
{
   for (unsigned i = 0; i < corsi.size(); i++) 
      if (corsi[i].TitoloCorso() == c.TitoloCorso() || (corsi[i].Giorno() == g && corsi[i].Ora() == o))
         throw invalid_argument("Corso già attivo in quella fascia oraria");

   for (unsigned i = 0; i < istruttori.size(); i++) 
   {
      if (istruttori[i].persona == c.Istruttore()) 
      {
         if (!istruttori[i].persona->Libero(g, o))
            throw invalid_argument("Istruttore non disponibile in quel giorno"); 
         else
            istruttori[i].persona->AggiungiImpegno(g, o);  // segno l'impegno dell'istruttore
      }
      break;
   }
   corsi.push_back(c);
}

void Palestra::AssegnaIstruttore(const Corso& c, const Persona& p) 
{
   int indexCorso = -1;
   for (unsigned i = 0; i < corsi.size(); i++)
      if (corsi[i].TitoloCorso() == c.TitoloCorso())  // corso attivo?
      {
         indexCorso = i;
         break;
      }
   for (unsigned i = 0; i < istruttori.size() && indexCorso != -1; i++)    // se non ho trovato il corso non ha senso cercare l'istruttore
      if (istruttori[i].persona == &p)                // istruttore assunto?
      {
         corsi[indexCorso].AssegnaIstruttore(p);
         istruttori[i].corsiInsegnati.push_back(&corsi[indexCorso]);
         return;  
      }
   throw invalid_argument("Istruttore o corso non trovato");
}

void Palestra::IscriviAlCorso(const Persona& p, const Corso& c) 
{
   int indexCorso = -1;
   for (unsigned i = 0; i < corsi.size(); i++)
      if(corsi[i].TitoloCorso() == c.TitoloCorso() && 
         corsi[i].IsCoperto() && 
         IscrittiCorso(c) < c.MaxIscritti()) // corso attivo, coperto da istruttore e non pieno?
      {
         indexCorso = i;
         break;
      }
   for (unsigned i = 0; i < clienti.size() && indexCorso != -1 ; i++)   // se non ho trovato il corso non ha senso cercare il cliente
      if (clienti[i].persona == &p && p.Libero(c.Giorno(), c.Ora()))    // cliente iscritto e libero in quel giorno e ora?
      {
         if (clienti[i].tipoIscrizione == Iscrizione::InProva && clienti[i].corsiIscritto.size() >= 1)
         {
            clienti[i].persona->RimuoviImpegno(corsi[indexCorso].Giorno(), corsi[indexCorso].Ora());
            clienti[i].corsiIscritto.pop_back();

            clienti[i].corsiIscritto.push_back(const_cast<Corso*>(&corsi[indexCorso]));
            clienti[i].persona->AggiungiImpegno(corsi[indexCorso].Giorno(), corsi[indexCorso].Ora());
         }
         else
            clienti[i].corsiIscritto.push_back(const_cast<Corso*>(&corsi[indexCorso]));
         return;
      }
   throw invalid_argument("Impossibile iscrivere al corso");
}

int Palestra::IscrittiCorso(const Corso& c) const
{
   int count = 0;
   for (unsigned i = 0; i < corsi.size(); i++)
   {
      if (corsi[i].TitoloCorso() == c.TitoloCorso())
         for (unsigned j = 0; j < clienti.size(); j++)
            for (unsigned k = 0; k < clienti[j].corsiIscritto.size(); k++)
               if (clienti[j].corsiIscritto[k]->TitoloCorso() == c.TitoloCorso())
                  count++;
      break;
   }
   return count;
}

string Corso::GiornoStringa() const
{
   switch (giorno) 
   {
      case 1: return "Lunedì";
      case 2: return "Martedì";
      case 3: return "Mercoledì";
      case 4: return "Giovedì";
      case 5: return "Venerdì";
      case 6: return "Sabato";
      case 7: return "Domenica";
      default: throw invalid_argument("Giorno non valido");
   }
   return "";
}

ostream& operator<<(ostream& os, const Palestra& p) 
{
   os << "Nome Palestra: " << p.nome << endl;
   os << "Corsi attivi: " << endl;
   for (unsigned i = 0; i < p.corsi.size(); i++)
      os << "  - " << p.corsi[i] << endl ;
   os << "Istruttori: " << endl;
   for (unsigned i = 0; i < p.istruttori.size(); i++)
   {
      os << "  - " << p.istruttori[i].persona->Nome() << " (Età: " << p.istruttori[i].persona->Eta() << ")" << " - Corsi tenuti: " << endl;
      for (unsigned j = 0; j < p.istruttori[i].corsiInsegnati.size(); j++)
         os << "    * " << p.istruttori[i].GetCorso(j) << endl;
   }
   os << "Clienti: " << endl;
   for (unsigned i = 0; i < p.clienti.size(); i++)
   {
      os << "  - " << p.clienti[i].persona->Nome() << " (Età: " << p.clienti[i].persona->Eta() << ", Tipo Iscrizione: " << (p.clienti[i].tipoIscrizione == Iscrizione::Regolare ? "Regolare" : "In Prova") << ")" << " - Corsi iscritti: " << endl;
      for (unsigned j = 0; j < p.clienti[i].corsiIscritto.size(); j++)
         os << "    * " << p.clienti[i].GetCorso(j) << endl;
   }

   return os;
}

ostream& operator<<(std::ostream& os, const Corso& c)
{
   os << c.TitoloCorso() << " (Giorno: " << c.GiornoStringa() << ", Ora: " << c.Ora() << ", Max Iscritti: " << c.MaxIscritti() << ", Istruttore: " << (c.IsCoperto() ? c.Istruttore()->Nome() : "Nessuno") << ")";
   return os;
}