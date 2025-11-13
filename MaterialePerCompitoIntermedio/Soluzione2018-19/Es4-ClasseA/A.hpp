#ifndef A_HPP
#define A_HPP
#include <iostream>

using namespace std;

class A
{public:
  A(unsigned d = 5);
  A(const A& a);
  ~A();
  A& operator=(const A& a);
  double Get(unsigned i) const 
      { if (b) return v[i]; 
        else return (v[i]+w[i])/2; }
  void Set(unsigned i, int e)  
      { if (b) v[i] = e; 
        else w[i] = e; }
  void X();
 private:
  int* v;
  int* w;
  bool b;
  unsigned dim;
};

#endif
