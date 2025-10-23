#include "vettori3D.hpp"

Vettori3D::Vettori3D()
{
   x = 0.0;
   y = 0.0; 
   z = 0.0;
}
Vettori3D::Vettori3D(double X, double Y, double Z = 0.0)
{
   x = X;
   y = Y;
   z = Z;
}

Vettori3D operator+(const Vettori3D& v1, const Vettori3D& v2)
{
   return Vettori3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vettori3D operator&(const Vettori3D& v1, const Vettori3D& v2)
{
   return Vettori3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

Vettori3D Vettori3D::operator*(const double& n) const
{
   return Vettori3D(x * n, y * n, z * n);
}

ostream& operator<<(ostream& os, const Vettori3D& v)
{
   os << v.x << '|' << v.y << '|' << v.z;
   return os;
}
istream& operator>>(istream& is, Vettori3D& v)
{
   char ch;
   is >> v.x >> ch >> v.y >> ch >> v.z;
   return is;
}