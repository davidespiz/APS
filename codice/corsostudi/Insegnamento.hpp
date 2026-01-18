#ifndef INSEGNAMENTO_HPP
#define INSEGNAMENTO_HPP
#include <iostream>
#include <string>

class Insegnamento
{
  friend std::ostream& operator<<(std::ostream& os, const Insegnamento& in);
public:
  Insegnamento(std::string t, unsigned c, std::string ssd, unsigned sem);
  std::string Titolo() const { return titolo; }
  unsigned Crediti() const { return crediti; }
  std::string Settore() const { return settore; }
  unsigned Semestre() const { return semestre; }
private:
  std::string titolo;
  unsigned crediti;
  std::string settore;
  unsigned semestre;
};
#endif
