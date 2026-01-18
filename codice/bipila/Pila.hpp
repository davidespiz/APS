// File Pila.hpp
#ifndef PILA_HPP
#define PILA_HPP
#include <iostream>

class Pila
{
  friend std::ostream& operator<<(std::ostream&, const Pila&); 
  friend std::istream& operator>>(std::istream&, Pila&); 
  friend bool operator==(const Pila&, const Pila&);
public:
  Pila();
  Pila(const Pila&);
  ~Pila();
  Pila& operator=(const Pila&);  
  void Push(int);
  void Pop();
  int Top() const { return vet[top]; }
  bool EstVuota() const { return top == - 1; }
 private:
  int* vet;     // vettore di interi
  int dim;      // dimensione del vettore
  int top;      // elemento affiorante
};
#endif
