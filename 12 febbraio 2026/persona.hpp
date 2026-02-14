#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>
#include <iostream>

class Persona
{
   friend std::ostream& operator<<(std::ostream& os, const Persona& p) {
      os << p.nome << " (" << p.età << " anni)";
      return os;
   }
   public:
      Persona(std::string n, unsigned e) : nome(n), età(e) {}
      std::string Nome() const { return nome; }
      unsigned Età() const { return età; }
   private:
      std::string nome;
      unsigned età;
};
#endif
