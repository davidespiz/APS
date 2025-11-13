#include <iostream>
#include <vector>

using namespace std;

class A
{public:
  A(unsigned n, int e = 0);
  int operator[]( unsigned i) const
    { return v1[i] + v2[i]; }
  void Set1(unsigned i, int e) 
    { v1[i] = e; }
  void Set2(unsigned i, int e) 
    { v2[i] = e; }
  void Copy(bool b);
 private:
  int* v1;
  vector<int> v2;
};

void A::Copy(bool b)
{ unsigned i;
  if (b)
    for (i = 0; i < v2.size(); i++)
      v1[i] = v2[i];
  else
    for (i = 0; i < v2.size(); i++)
      v2[i] = v1[i];
}

A::A(unsigned n, int e)
    : v2(n,e)
{ v1 = new int[n];
  for (unsigned i = 0; i < n; i++)
    v1[i] = e;
}

int main ()
{  A a1(4), a2(3,5);
   A a3;
   a2.Set2(2,7);
   a2.Set2(1,3);
   a2.Copy(true);
   a1[0] = 5;
   a1 = a2;
   a1.Set1(2,4);
   a1.Set2(2,2);
   cout << a2[0] << " " << a2[1] 
        << " " << a2[2] << endl;
   return 0;
}