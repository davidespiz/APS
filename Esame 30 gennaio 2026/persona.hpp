#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <string>
#include <vector>

class Persona 
{
   friend bool operator==(const Persona& p1, const Persona& p2);
   public:
      Persona(std::string n, int e);

      // Selettori
      std::string Nome() const { return nome; }
      int Eta() const { return eta; }

      // Metodi
      bool Libero(int giorno, int ora) const;
      void AggiungiImpegno(int giorno, int ora) { disponibilita[giorno-1][ora] = 1; }
      void RimuoviImpegno(int giorno, int ora) { disponibilita[giorno-1][ora] = 0; } // giorno da 1 a 7
   private:
      std::string nome;
      int eta;
      std::vector<std::vector<int>> disponibilita;  // vettore di giorni (1-7) contenenti vettori di ore (8-21) libere
};
#endif
