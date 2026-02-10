#include "reparto.hpp"
using namespace std;

void Reparto::AggiungiStanza(int cap, TipoStanza ts)
{
   stanze.push_back(Stanza(cap, ts));
}

bool Reparto::AmmettiPaziente(Paziente* p, const Data& d)
{
   if (TrovaPaziente(p).first != -1)
      throw invalid_argument("Paziente già ricoverato");
   for (unsigned i = 0; i < NumStanze(); i++)
      if (GenereStanza(p->GenerePaziente(), stanze[i]) && stanze[i].NumRicoverati() < stanze[i].NumLetti())
      {
         stanze[i].AmmettiPaziente(p, d);
         return true;
      }
   return false;
}

void Reparto::DimettiPaziente(Paziente* p)
{
   pair<int, int> index = TrovaPaziente(p);
   if (index.first == -1)
      throw invalid_argument("Paziente non trovato");
   stanze[index.first].DimettiPaziente(index.second);
}

bool Reparto::GenereStanza(Genere g, Stanza s)
{
   if (g == Genere::MASCHIO && 
      (s.GetTipoStanza() == TipoStanza::SOLO_UOMINI || s.GetTipoStanza() == TipoStanza::MISTA))
      return 1;
   if (g == Genere::FEMMINA &&
      (s.GetTipoStanza() == TipoStanza::SOLO_DONNE || s.GetTipoStanza() == TipoStanza::MISTA))
      return 1;
   if (s.NumRicoverati() != 0 && (g == s.GetPaziente(0)->GenerePaziente()))
      return 1;
   return 0;
}

pair<int, int> Reparto::TrovaPaziente(Paziente* p)
{
   for (unsigned i = 0; i < NumStanze(); i++)
      for (unsigned k = 0; k < stanze[i].NumRicoverati(); k++)
         if (stanze[i].GetPaziente(k) == p)
            return make_pair(i, k);
   return make_pair(-1, -1);
}

bool Reparto::IsolaPaziente(Paziente* p, int k)
{
   pair<int, int> index = TrovaPaziente(p);
   if (index.first == -1)
      throw invalid_argument("Paziente non trovato!");
   
   stanze[index.first].IncrementaDimissione(index.second, k);
   // se è già da solo
   if (stanze[index.first].NumRicoverati() == 1)  
      return false;
   // se non ho una stanza libera
   for (unsigned i = 0; i < NumStanze(); i++)
      if (stanze[i].NumRicoverati() == 0)
         {
            //aggingo il paziente alla stanza vuota
            stanze[i].AmmettiPaziente(p, stanze[index.first].GetDimissione(index.second) + k);
            stanze[index.first].DimettiPaziente(index.second);
            return true;
         }
   return false;
}