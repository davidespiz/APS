#ifndef A_HPP
#define A_HPP

using namespace std;

class A
{
friend ostream& 
 operator<<(ostream& os, const A& a);
public:
  A(unsigned n = 3);
  A(const A& a);
  A& operator=(const A& a);
  ~A();
  int& operator[](unsigned i) 
     { return v[i]; }
  void BackUp();
  void Restore();
  unsigned Dim() const 
    { return dim; }
private:
  unsigned dim;
  int* v;
  int* vb; // vettore di back-up
};
#endif
