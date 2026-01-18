// file VettoreCompatto.hpp
#ifndef VETTORE_COMPATTO_HPP
#define VETTORE_COMPATTO_HPP
#include <iostream>

class Elemento
{
 public:
  Elemento(int v = 0, unsigned r = 1) { valore = v; ripetizioni = r; }
  int valore;
  unsigned ripetizioni;
};

class VettoreCompatto
{
  friend std::ostream& operator<<(std::ostream& os, const VettoreCompatto& vc);
 public:
  VettoreCompatto();
  VettoreCompatto(const VettoreCompatto&);
  ~VettoreCompatto();
  VettoreCompatto& operator=(const VettoreCompatto&);
  void Inserisci(int e);
  void Elimina();
  int operator[](unsigned i) const;
  unsigned NumElem() const { return num_elem; }
 private:
  Elemento* vet;
  unsigned num_elem; // numero totale di elementi nel VettoreCompatto
  unsigned dim; // dimensione di vet
};
#endif
