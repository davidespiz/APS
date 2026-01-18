// file persona.hpp
#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <string>

class Persona
{
public:
  Persona(std::string n) { nome = n; }
  std::string Nome() const { return nome; }
private:
  std::string nome;
};
#endif
