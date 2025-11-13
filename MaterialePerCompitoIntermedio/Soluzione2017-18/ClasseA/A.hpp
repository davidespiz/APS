#ifndef A_HPP
#define A_HPP
#include <iostream>

using namespace std;

class A
{
 public:
  A(unsigned d, bool split = true);
  A(const A& a);
  ~A();
  A& operator=(const A& a);
  double Get1(unsigned i) const 
                   { return p1[i]; }
  double Get2(unsigned i) const 
                   { return p2[i]; }
  void Set1(unsigned i, double val)  
                   { p1[i] = val; }
  void Set2(unsigned i, double val)  
                   { p2[i] = val; }
  void Merge();
  void Split();
 private:
  double* p1;
  double* p2;
  unsigned dim;
};

#endif
