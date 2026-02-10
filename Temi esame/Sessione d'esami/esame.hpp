#ifndef ESAME_HPP
#define ESAME_HPP
#include "corso.hpp"
#include "studente.hpp"
#include "Data.hpp"
#include <vector>

class Esame 
{
   public:
      Esame(Corso* c, const Data& d) : corso(c), data(d) {}
      Corso* GetCorso() const { return corso; }
      Data GetData() const { return data; }
      Studente* GetStudente(unsigned i) const { return iscritti[i]; }
      unsigned NumIscritti() const { return iscritti.size(); }

      void PrenotaEsame(Studente* s);
      void PosticipaEsame(const Data& d);
   private:
      Corso* corso;
      Data data;
      std::vector<Studente*> iscritti;
};



#endif
