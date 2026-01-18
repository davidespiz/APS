//File Cliente.hpp
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <iostream>

class Cliente
{
  friend std::ostream& operator<<(std::ostream& os, const Cliente& c);
public:
  Cliente(std::string n, std::string e)  
    : nome(n), email(e) {}
  std::string Nome() const { return nome; }
  std::string Email() const { return email; }
private:
  std::string nome, email;
};
#endif
