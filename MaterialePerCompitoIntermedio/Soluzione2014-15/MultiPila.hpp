// File MultiPila.hpp
#ifndef MULTIPILA_HPP
#define MULTIPILA_HPP
#include <iostream>
#include <cassert>

using namespace std;

class MultiPila
{
  friend ostream& operator<<(ostream&, const MultiPila&); 
//   friend bool operator==(const MultiPila&, const MultiPila&);
public:
  MultiPila(unsigned i);
  MultiPila(const MultiPila&);
  ~MultiPila();
  MultiPila& operator=(const MultiPila&);  
  void Push(int elem, unsigned i);
  void Pop(unsigned i);
  int Top(unsigned i) const;
  bool IsEmpty(unsigned i) const { return top[i] == dim * int(i) - 1; }
  unsigned NumPile() const { return n; }
 private:
  int* vet;      // vettore di interi
  int dim;       // dimensione per pila
  int n;         // numero di pile
  int total_dim; // dimensione del vettore 
  int* top;      // vettore elementi affiorante
}
;
#endif
