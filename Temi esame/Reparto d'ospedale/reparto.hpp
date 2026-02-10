#ifndef REPARTO_HPP
#define REPARTO_HPP

#include "stanza.hpp"
#include "paziente.hpp"
#include "data.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Reparto 
{
   public:
      Reparto(std::string n) : nome (n) {};
      Stanza GetStanza(unsigned i) const { return stanze[i]; }
      unsigned NumStanze() const { return stanze.size(); }

      void AggiungiStanza(int cap, TipoStanza ts);
      bool AmmettiPaziente(Paziente* p, const Data& d);
      void DimettiPaziente(Paziente* p);
      bool IsolaPaziente(Paziente* p, int k);
   private:
      std::string nome;
      std::vector<Stanza> stanze;
      bool GenereStanza(Genere  g, Stanza s);
      std::pair<int, int> TrovaPaziente(Paziente* p);
};

#endif // REPARTO_HPP
