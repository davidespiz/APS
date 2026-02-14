// File Azienda.hpp
#ifndef AZIENDA_HPP
#define AZIENDA_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "Magazzino.hpp"
#include "Negozio.hpp"

using namespace std;

class Fornitura
{
   public:
      Fornitura(Magazzino* m, Negozio* n, int q) { magazzino = m; negozio = n; qta = q; }
      int qta;
      Magazzino* magazzino;
      Negozio* negozio;
};

class Azienda
{
   public:
      Azienda(std::string n) : nome(n) {}
      std::string NomeAzienda() const { return nome; }
      unsigned NumMagazzini() const { return magazzini.size(); }
      Magazzino* GetMagazzino(unsigned i) const { return magazzini[i]; }
      unsigned NumNegozi() const { return negozi.size(); }
      Negozio* GetNegozio(unsigned i) { return negozi[i]; }
      unsigned NumForniture() const { return fornitura.size(); }
      const Fornitura& GetFornitura(unsigned i) const { return fornitura[i]; }

      void InserisciMagazzino(Magazzino* m);
      void InserisiNegozio(Negozio* n);
      void ChiudiMagazzino(Magazzino* m);
   private:
      std::string nome;
      vector<Magazzino*> magazzini;
      vector<Negozio*> negozi; 
      vector<Fornitura> fornitura;
      
      int CercaMagazzino(Magazzino* m);
      int CercaNegozio(Negozio* n);
};
#endif
