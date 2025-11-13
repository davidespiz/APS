#ifndef A_HPP
#define A_HPP
#include <iostream>

using namespace std;

const unsigned DIM = 6;

class A
{
 public:
  friend ostream& operator<<(ostream& os, const A& a);
  A(const A& a);
  ~A();
  A& operator=(const A& a);
  A(bool empty, float val = 0.0);
  float operator[](int i) const 
     { return v[i]; }
  float& operator[](int i)
     { return v[i]; }
 private:
  float* v;
};

#endif
