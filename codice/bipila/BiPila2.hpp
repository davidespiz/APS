#ifndef BIPILA_HPP
#define BIPILA_HPP
#include <iostream>

class BiPila
{
  friend std::ostream& operator<<(std::ostream& os, const BiPila& p);
public:
  BiPila();
  BiPila(const BiPila& p);
  ~BiPila();
  BiPila& operator=(const BiPila& p);
  void Pop(int lato); 
  void Push(int elem, int lato); 
  int Top(int lato) const; 
  bool EstVuota(int lato) const;
 private:
  int* vet; // include entrambe le pile: p1 dal basso e p2 dall'alto
  int dim;  
  int top1, top2;  
};
#endif
