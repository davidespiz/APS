#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <vector>

int convertiRomani(char c);
int sommaCifreQuadrate(int n);
bool cercaInVettore(int v[], int n);

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

unsigned int numeriRomani(string s)
{
   int n = s.size();
   int numTot = 0;
   int num1;
   int num2;
     
   //if(n == 1)
   //   return convertiRomani(s[0]);

   for(int i = 0; i < n; i++)
   {
      if(convertiRomani(s[i]) == 0)
         return 0;

      num1 = convertiRomani(s[i]);
      num2 = convertiRomani(s[i+1]);
      if (num1 < num2)
         numTot -= num1;
      else 
         numTot += num1;
   }
   return numTot;
}

int convertiRomani(char c)
{
   if(c == 'I')
      return 1;
   else if(c == 'V')
      return 5;
   else if(c == 'X')
      return 10;
   else if(c == 'L')
      return 50;
   else if(c == 'C')
      return 100;
   else if(c == 'D')
      return 500;
   else if(c == 'M')
      return 1000;
   // valore di default per caratteri non riconosciuti
   return 0;
}

bool numFelice(int n)
{
   int buff[100];
   //inizializzo perché sennò non funziona na ceppa
   for (int i = 0; i < 100; i++)
      buff[i] = 0;

   buff[0] = n;
   int i = 1;

   while(n != 1)
   {
      n = sommaCifreQuadrate(n);
      if(cercaInVettore(buff, n) == true)
         return false;
      buff[i++] = n;
   }
   
   return true;
}

int sommaCifreQuadrate(int n)
{
   int somma = 0;
   while (n > 0)
   {
      somma += pow((n % 10), 2);
      n /= 10;
   }
   return somma;
}

bool cercaInVettore(int v[], int n)
{
   for (int i = 0; i < 100; i++)
      if (v[i] == n)
         return true;
   return false;
}