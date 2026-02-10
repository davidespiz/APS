#include "sessione.hpp"
using namespace std;
#include "sessione.hpp"
#include <string>
#include <vector>
#include "Data.hpp"
#include <stdexcept>

Sessione::Sessione(string n, Data i, Data f)
   : nome(n), inizio(i), fine(f){}

void Sessione::InserisciCorso(Corso* c)
{
   for (unsigned i = 0; i < corsi.size(); i++)
      if (corsi[i] == c)
         throw invalid_argument("Corso già presente");
   corsi.push_back(c);
}

void Sessione::InserisciStudente(Studente* s)
{
   for (unsigned i = 0; i < studenti.size(); i++)
      if (studenti[i] == s)
         throw invalid_argument("Studente già iscritto");
   studenti.push_back(s);
}

void Sessione::CreaEsame(Corso* c, Data d)
{
   if (d < inizio || d > fine)
      throw invalid_argument("Data fuori dalla sessione");
   for (unsigned i = 0; i < esami.size(); i++)
      if (esami[i].GetCorso() == c)
         throw invalid_argument("Esame già presente");
   
   esami.push_back(Esame(c, d));
}

void Sessione::PrenotaEsame(Studente* s, Corso* c, const Data& d)
{
   int indexStudente = -1, indexEsame;
   for (unsigned i = 0; i < studenti.size(); i++)
      if (studenti[i] == s)   
      {
         indexStudente = i;
         break;
      }
   if (indexStudente == -1)   
      throw invalid_argument("Studente non trovato");
   for (unsigned i = 0; i < esami.size(); i++)
      if (esami[i].GetCorso() == c && esami[i].GetData() == d)
      {
         indexEsame = i;
         break;
      }
   if (indexEsame == -1)
      throw invalid_argument("Esame non trovato");
   esami[indexEsame].PrenotaEsame(s);
}

Data Sessione::PosticipaEsame(Corso* c, const Data& d)
{
   bool trovato = 0;
   int indexEsame = -1;
   Data newData(d);
   for (unsigned i = 0; i < esami.size(); i++)
      if (esami[i].GetCorso() == c && esami[i].GetData() == d)
      {
         indexEsame = i;
         break;
      }
   if (indexEsame == -1)
      throw ("Esame non trovato");
   
   do
   {
      ++newData;
      trovato = 0;
      for (unsigned i = 0; i < esami.size(); i++)
         if ((esami[i].GetData() == d && esami[i].NumIscritti() != 0) || 
             (esami[i].GetCorso() == c && esami[i].GetData() == d))
            indexEsame = i;
   } while (trovato != 1);
   esami[indexEsame].PosticipaEsame(newData);

   return newData;
}

ostream& operator<<(ostream& os, const Sessione& s)
{
   os << "Nome della sessione: " << nome << endl << "Inizio: " << inizio << " Fine: " << fine << endl;
   
   return os;
}