#ifndef VETTORI3D
#define VETTORI3D
#include <iostream>
using namespace std;

class Vettori3D
{
      friend Vettori3D operator+(const Vettori3D& v1, const Vettori3D& v2);
      friend Vettori3D operator&(const Vettori3D& v1, const Vettori3D& v2);
      friend ostream& operator<<(ostream& os, const Vettori3D& v);
      friend istream& operator>>(istream& is, Vettori3D& v);
   public:
      Vettori3D();
      Vettori3D(double X, double Y, double Z);
      double X() const {return x;}
      double Y() const {return y;}
      double Z() const {return z;}
      Vettori3D operator*(const double& n) const;
   private:
      double x;
      double y; 
      double z;

};
#endif