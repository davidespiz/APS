#ifndef CORSO_HPP
#define CORSO_HPP
#include <iostream>
#include <string>
#include <vector>

class Corso
{
public:
  Corso(std::string n) : nome(n) {}
  std::string Nome() const { return nome; }
  private:
  std::string nome;
};

#endif
