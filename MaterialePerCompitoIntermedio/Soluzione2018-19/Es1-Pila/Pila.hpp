// File Pila.hpp
#ifndef PILA_HPP
#define PILA_HPP
#include <iostream>

using namespace std;

class Pila
{
  friend ostream& operator<<(ostream&, const Pila&); 
  friend istream& operator>>(istream&, Pila&); 
  friend bool operator==(const Pila&, const Pila&);
public:
  Pila();
  Pila(const Pila&);
  ~Pila();
  Pila& operator=(const Pila&);  
  Pila& operator+=(int);
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
