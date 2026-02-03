#ifndef PALESTRA_HPP
#define PALESTRA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "persona.hpp"

enum class Iscrizione{Regolare, InProva};

class Corso 
{  
   friend std::ostream& operator<<(std::ostream& os, const Corso& c);
   public:
      Corso(std::string t, int max, int g, int o);
      
      // Selettori
      std::string TitoloCorso() const { return titolo; }
      int MaxIscritti() const { return maxIscritti; }
      int Giorno() const { return giorno; }
      int Ora() const { return ora; }
      Persona* Istruttore() const { return istruttore; }
      std::string GiornoStringa() const;

      // Funzioni ausiliarie
      bool IsCoperto() const { return istruttore != nullptr; }
      void AssegnaIstruttore(const Persona& p) { istruttore = const_cast<Persona*>(&p); } 
   private:
      std::string titolo;
      int giorno, ora, maxIscritti; 
      Persona* istruttore;
};

class Cliente 
{  
   public:
      Iscrizione tipoIscrizione;
      std::vector<Corso*> corsiIscritto;
      Persona* persona; 

      Corso GetCorso(unsigned i) const { return *corsiIscritto[i]; }
};

class Istruttore 
{  
   public:
      std::vector<Corso*> corsiInsegnati;
      Persona* persona;
      
      Corso GetCorso(unsigned i) const { return *corsiInsegnati[i]; }
};

class Palestra 
{  
   friend std::ostream& operator<<(std::ostream& os, const Palestra& p);
   public:
      Palestra(std::string nome = "");

      // Selettori
      std::string NomePalestra() const { return nome; }
      Corso GetCorso(unsigned i) { return corsi[i]; }
      unsigned NumCorsi() const { return corsi.size(); }
      Cliente GetCliente(unsigned i) { return clienti[i]; }
      unsigned NumClienti() const { return clienti.size(); }
      Istruttore GetIstruttore(unsigned i) { return istruttori[i]; }
      unsigned NumIstruttori() const { return istruttori.size(); }

      // Modificatori
      void IscriviCliente(const Persona& p, bool b);
      void PerfezionaIscrizione(const Persona& p);
      void AssumiIstruttore(const Persona& p);
      void AttivaCorso(const Corso& c, int g, int o);
      void AssegnaIstruttore(const Corso& c, const Persona& p);
      void IscriviAlCorso(const Persona& p, const Corso& c);

      // Metodi ausiliari 
      int IscrittiCorso(const Corso& c) const;

   private:
      std::string nome;
      std::vector<Corso> corsi;
      std::vector<Cliente> clienti;
      std::vector<Istruttore> istruttori;
};

#endif 
