// File Persona.hpp
#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <string>
#include <vector>
#include "../utils/Data.hpp"
#include "Comune.hpp"

class Persona
{
  friend std::istream& operator>>(std::istream&, Persona&);
  friend std::ostream& operator<<(std::ostream&, const Persona&);
public:
  Persona(std::string, std::string, char, Data, std::string, Comune* = nullptr);
  Persona(); 
  std::string Nome() const { return nome; }
  std::string Cognome() const { return cognome; }
  char Sesso() const { return sesso; }
  Data DataNascita() const { return data_nascita; }
  std::string CittaNascita() const { return citta_nascita; }
  Comune* ComuneResidenza() const { return comune_residenza; }
  Persona* Coniuge() const { return coniuge; }
  Persona* Padre() const { return padre; }
  Persona* Madre() const { return madre; }
  Persona* Figlio(unsigned i) const { return figli[i]; }
  unsigned NumFigli() const { return figli.size(); }

  void CambiaComune(Comune*);
  void AggiungiConiuge(Persona*);
  void RimuoviConiuge();
  void AggiungiGenitore(Persona*);
  void RimuoviPadre();
  void RimuoviMadre();
  void AggiungiFiglio(Persona*);
  void RimuoviFiglio(Persona*);

  void StatoDiFamiglia(std::ostream& os = std::cout) const;
private:
  std::string nome;
  std::string cognome;
  char sesso;
  Data data_nascita;
  std::string citta_nascita;
  Comune* comune_residenza;
  Persona* coniuge; // rappresenta la relazione coniugio 
                    // in entrambi i versi
  std::vector<Persona*> figli;
  Persona* padre; 
  Persona* madre; 
  void EliminaCollegamentoFiglio(Persona*);
};
#endif
