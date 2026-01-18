// File persona.hpp
#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <string>
#include <vector>

class Persona
{
public:
  Persona(std::string n) : nome(n) {}
  std::string Nome() const { return nome; }
private:
  std::string nome;
};

class Gruppo 
{
 public:                  
  unsigned QuantePersone() const { return membri.size(); }
  Persona* QualePersona(int i) { return membri[i]; }
  void AggiungiPersona(Persona* p) { membri.push_back(p); }               
private:
  std::vector<Persona*> membri;
};
#endif
