#ifndef A_HPP
#define A_HPP
#include <iostream>

using namespace std;

class A
{
 public:
  friend A operator*(const A& a1, const A& a2);
  friend ostream& operator<<(ostream& os, const A& a);
  A(const A& a);
  ~A();
  A& operator=(const A& a);
  A(unsigned nr, unsigned nc);
  double operator()(unsigned i, 
                    unsigned j) const 
     { return v[i*c+j]; }
  double& operator()(unsigned i, 
                     unsigned j)
     { return v[i*c+j]; }
  unsigned R() const { return r; }
  unsigned C() const { return c; }
 private:
  double* v;
  unsigned r;
  unsigned c;
};

#endif
