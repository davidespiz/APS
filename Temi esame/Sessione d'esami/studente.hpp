// File Studente.hpp
#ifndef STUDENTE_HPP
#define STUDENTE_HPP
#include <string>
#include <vector>

using namespace std;

class Studente
{
public:
  Studente(string n) : nome(n) {}
  string Nome() const { return nome; }
private:
  string nome;
};

inline ostream& operator<<(ostream& os, const Studente& s)
{ return os << s.Nome(); }

#endif
