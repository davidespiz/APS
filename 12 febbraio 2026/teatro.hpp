#ifndef TEATRO_HPP
#define TEATRO_HPP

#include "persona.hpp"
#include "data.hpp"
#include <iostream>
#include <vector>

class Spettacolo
{
   friend std::ostream& operator<<(std::ostream& os, const Spettacolo& s) {
      os << s.titolo << " (" << s.costo << " euro)";
      return os;
   }
   private:
      std::string titolo;
      int costo;
   public:
      Spettacolo(std::string t, int c) 
      {  
         titolo = t;
         costo = c;
      }
      std::string Titolo() const { return titolo; }
      int Costo() const { return costo; }

};

class Biglietto
{
   public:
      Biglietto(Persona* p, const Data& g) 
      {
         persona = p;
         giorno = g;
      }
      Persona* persona;
      Data giorno;
};

class Replica
{
   public:
      Replica(Spettacolo* s, const Data& g) 
      {  
         spettacolo = s;
         giorno = g;
      }
      Data giorno;
      Spettacolo* spettacolo;
};

class Teatro 
{
   friend std::ostream& operator<<(std::ostream& os, const Teatro& t);
   public:
      Teatro(std::string n, unsigned c, Data i, Data f) : nome(n), capienza(c), inizio(i), fine(f) {}
      // Selettori
      std::string Nome() const { return nome; }
      unsigned Capacità() const { return capienza; }
      Data Inizio() const { return inizio; }
      Data Fine() const { return fine; }
      Persona* GetSpettatore(unsigned i) const { return spettatori[i]; }
      unsigned NumSpettatori() const { return spettatori.size(); }
      unsigned NumRepliche() const { return repliche.size(); }
      Spettacolo* GetSpettacolo(unsigned i) const { return repliche[i].spettacolo; }
      unsigned NumBiglietti() const { return biglietti.size(); }
      Persona* GetBigliettoSpettatore(unsigned i) const { return biglietti[i].persona; }
      Data GetBigliettoGiorno(unsigned i) const { return biglietti[i].giorno; }
      // Metodi
      void RegistraSpettatore(Persona* p); 
      void ProgrammaSpettacolo(Spettacolo* s, const Data& g);
      void AcquistaBiglietto(Persona* p, const Data& g);
      bool CancellaBiglietto(Persona* p, const Data& g);

      int GiornoLibero(const Data& g) const;
      unsigned BigliettiVenduti(const Data& g) const;

   private:
      std::string nome;
      unsigned capienza;
      Data inizio;
      Data fine;

      std::vector<Persona*> spettatori;
      std::vector<Replica> repliche;
      std::vector<Biglietto> biglietti;

      int CercaPersona(Persona* p) const;
      int CercaBigliettoSpettatore(Persona* p, const Data& g) const;
};

#endif
