#include <iostream>
using namespace std;
#include <cmath>

bool Primo(int n)
{
   if(n % 2 == 0)
      return 0;
   for(int i = 3; i <= sqrt(n); i += 2)
   {
      if(n % i == 0)
         return 0;
   }
   return 1;
}

void StampaPriamide(int n)
{
   for(int i = 1; i <= n; i++)
   {
      for(int j = n - i; j > 0; j--)
         cout << " ";
      for(int j = 1; j <= i; j++)
         cout << j;
      for(int j = i - 1; j > 0; j--)
         cout << j;
      cout << endl;
   }
}

double radq(double n)
{
   double xkk = 1.0;
   double xk = 0;
   const double e = 0.000001;
   while(fabs(xkk - xk) >= e)
   {
      xk = xkk;   
      xkk = (xk + n/xk)/2.0;
   }
   return xkk;
}

bool numeroPerfetto(int n)
{
   int sum = 0;
   for(int i = 1; i <= n/2; i++)
      if(n % i == 0)
         sum += i;
   if(sum == n)
      return true;
   return false;
}

void stampaPerfetti(int n)
{
   for (int i = 1; i < n; i++)
      if(numeroPerfetto(i) == true)
         cout << i << " ";

   cout << endl;
   return;
}