#ifndef STANZA_HPP
#define STANZA_HPP
#include <vector>
#include <string>
#include <iostream>
#include "paziente.hpp"
#include "data.hpp"

enum class TipoStanza {SOLO_DONNE, SOLO_UOMINI, SINGOLO_GENERE, MISTA};

class Ricovero
{
   public:
      Ricovero(Paziente* p, const Data& dd) : paziente(p), dimissione(dd) {};
      Paziente* paziente;
      Data dimissione;
};

class Stanza
{
   public:
      Stanza(unsigned n, TipoStanza ts) : numLetti(n), tipoStanza(ts) {};
      unsigned NumLetti() const { return numLetti; }
      TipoStanza GetTipoStanza() const { return tipoStanza; }
      unsigned NumRicoverati() const { return ricoverati.size(); }
      Paziente* GetPaziente(unsigned i) const { return ricoverati[i].paziente; }
      Data GetDimissione(unsigned i) const { return ricoverati[i].dimissione; }
      Ricovero GetRicoverato(unsigned i) const { return ricoverati[i]; }

      void AmmettiPaziente(Paziente* p, const Data& d);
      void DimettiPaziente(int index);
      void IncrementaDimissione(int index, int k);

   private:
      unsigned numLetti;
      TipoStanza tipoStanza;
      std::vector<Ricovero> ricoverati;

};

#endif // STANZA_HPP
