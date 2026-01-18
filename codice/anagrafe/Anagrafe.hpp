// File Anagrafe.hpp
#ifndef ANAGRAFE_HPP
#define ANAGRAFE_HPP
#include <string>
#include <vector>
#include "Persona.hpp"
#include "Comune.hpp"

class Anagrafe
{
  friend std::ostream& operator<<(std::ostream&, const Anagrafe&);
public:
  Anagrafe(std::string n) : nome(n) {}
  Persona* VediPersona(unsigned i) const { return persone[i]; }
  Comune* VediComune(unsigned i) const { return comuni[i]; }
  unsigned NumComuni() const { return comuni.size(); }
  unsigned NumPersone() const { return persone.size(); }
  std::string Nome() const { return nome; }

  void InserisciPersona(Persona* p);
  void InserisciNuovoNato(Persona* p, Persona* pm, Persona* pp);
  void EliminaPersona(Persona* p);
  void InserisciComune(Comune* c);
  void EliminaComune(Comune* c);
  void EliminaComuneESuoiResidenti(Comune* c);
  void InserisciConiugio(Persona* pmo, Persona* pma);
  void InserisciDivorzio(Persona* pmo, Persona* pma);
  void InserisciGenitoreFiglio(Persona* pg,Persona* pf);
  void StampaCertificato(Persona* p) const;
  void StampaVotanti(Data elezioni) const;
private:
  std::string nome;
  std::vector<Comune*> comuni;
  std::vector<Persona*> persone;
  void RimuoviLegamiPersona(Persona* p);
  int CercaPersona(Persona *) const;
  int CercaComune(Comune *) const;
};
#endif
