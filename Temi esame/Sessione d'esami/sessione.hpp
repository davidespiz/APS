#ifndef SESSIONE_HPP
#define SESSIONE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Data.hpp"
#include "corso.hpp"
#include "studente.hpp"
#include "esame.hpp"

class Sessione 
{
   friend ostream& operator<<(ostream& os, const Sessione& s);
   public:
      Sessione(std::string n, Data i, Data f);
      std::string NomeSessione() const { return nome; }
      Data InizioSessione() const { return inizio; }
      Data FineSessione() const { return fine; }
      Corso* GetCorso(unsigned i) const { return corsi[i]; }
      unsigned NumCorsi() const { return corsi.size(); }

      void InserisciCorso(Corso* c);
      void InserisciStudente(Studente* s);
      void CreaEsame(Corso* c, Data d);
      void PrenotaEsame(Studente* s, Corso* c, const Data& d);
      Data PosticipaEsame(Corso* c, const Data& d);
   private:
      std::string nome;
      Data inizio;
      Data fine;

      std::vector<Corso*> corsi;
      std::vector<Studente*> studenti;
      std::vector<Esame> esami;
};


#endif


