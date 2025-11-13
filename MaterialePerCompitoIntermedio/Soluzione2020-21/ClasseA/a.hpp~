// File a.hpp
#ifndef A_HPP
#define A_HPP

using namespace std;

class B                             
{public:                                       
  B(int n) { num = n; }
  void Set(int n) { num = n; }
  char Get() const { return num; }
 private: 
  int num;
};

class A                             
{public:                                       
  A(int v = 0) { p1 = new B(v); p2 = p1; }
  A(const A&);             
  A& operator=(const A&);  
  ~A();                    
  void Set1(int v) {  p1->Set(v); }
  void Set3(int v) {  p2->Set(v); }
  int Get1() const { return p1->Get(); }
  int Get2() const { return p2->Get(); }
  void Flip() { if (p1 == p2) p2 = new B(p1->Get());
                else { delete p2; p2 = p1; } }
 private: 
  B* p1;                                       
  B* p2;
};

#endif
