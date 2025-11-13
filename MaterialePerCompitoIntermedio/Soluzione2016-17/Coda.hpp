// File Coda.hpp
#ifndef CODA_HPP
#define CODA_HPP
#include <iostream>

using namespace std;

class Coda
{
  friend ostream& operator<<(ostream&, const Coda&); 
  friend istream& operator>>(istream&, Coda&); 
  friend bool operator==(const Coda&, const Coda&);
public:
  Coda();
  Coda(const Coda&);
  ~Coda();
  Coda& operator=(const Coda&);  
  void Push(int);
  void Pop();
  int Top() const; // non dimenticare "const"
  bool EstVuota() const { return head == tail + 1; }
  void Stampa(ostream&) const; // per debugging
  // nessun selettore per head e tail (non e' parte del tipo astratto Coda)
private:
  int* vet;     // vettore di interi
  int dim;      // dimensione del vettore
  int head;     // elemento affiorante
  int tail;     // elemento in coda
  // funzione ausiliaria (privata!)
  int Length() const { return tail - head + 1; }
};
#endif
