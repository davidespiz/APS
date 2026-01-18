// file Biblioteca.hpp
#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include <string>
#include <vector>
#include <iostream>
#include "libro.hpp"
#include "persona.hpp"

class RecordLibro
{
public:
  Libro* volume;
  Persona* affidatario;
  bool in_prestito;
};

class Biblioteca
{
  friend std::ostream& operator<<(std::ostream&, const Biblioteca& b);
public:
  Biblioteca() {}
  void Acquisisce(Libro* l);
  void Prestito(Libro* l, Persona* p);
  void Restituzione(Libro* l);
  bool InPrestito(Libro* l) const;
  bool Disponibile(Libro* l) const;
  std::vector<Libro*> Prestiti(Persona* p) const;
private:
  int CercaLibro(Libro* l) const;
  std::vector<RecordLibro> bib;
};
#endif
