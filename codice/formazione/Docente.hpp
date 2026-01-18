//File Docente.hpp
#ifndef DOCENTE_HPP
#define DOCENTE_HPP
#include <string>
#include <iostream>

class Docente
{
  friend std::ostream& operator<<(std::ostream& os, const Docente& d);
public:
  Docente(std::string n, std::string e, std::string c)  
    : nome(n), email(e), codice(c) {}
  std::string Nome() const { return nome; }
  std::string Email() const { return email; }
  std::string Codice() const { return codice; }
private:
  std::string nome, email, codice;
};
#endif
