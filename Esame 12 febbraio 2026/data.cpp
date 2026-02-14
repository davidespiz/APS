#include "data.hpp"

bool Data::Valida() const
{
   return mese <= 12 && giorno <= GiorniDelMese();
}

bool Data::Bisestile() const
{
   return (anno % 4 || anno % 100 || anno % 400);
}

unsigned Data::GiorniDelMese() const
{
   if(mese == 4 || mese == 6 || mese == 9 || mese == 11)
      return 30;
   if(mese == 2)
      return Bisestile() ? 29 : 28;
   return 31;
}

Data::Data()
{
   giorno = 1;
   mese = 1;
   anno = 1970;
}

Data::Data(unsigned g, unsigned m, unsigned a)
{
   giorno = g;
   mese = m;
   anno = a;
   if(!Valida())
      *this = Data();
} 

istream& operator>>(istream& is, Data& d)
{
   //gg/mm/aaaa
   char ch;
   is >> d.giorno >> ch >> d.mese >> ch >> d.anno;
   if(!d.Valida())
      d = Data();
   return is;
}
ostream& operator<<(ostream& os, const Data& d)
{
   os << d.giorno << '/' << d.mese << '/' << d.anno;

   return os;
}

void Data::operator++()
{
   giorno++;
   if(giorno > GiorniDelMese())
   {
      giorno = 1;
      mese++;
      if(mese > 12)
      {
         mese = 1;
         anno++;
      }
   }
   return;
}

void Data::operator--()
{
   giorno--;
   if(giorno == 0)
   {
      mese--;
      if(mese == 0)
      {
         mese = 12;
         giorno = 31;
         anno--;
      }
      else 
         giorno = GiorniDelMese();
   }
   return;
}

int operator-(const Data& d1, const Data& d2) 
{
   int g = 0;
   if(d1 < d2)
   {
      Data aux_d(d1);
      while(!(aux_d == d2))
      {
         ++aux_d;
         g++;
      }
   }
   else
   {
      Data aux_d(d1);
      while(!(aux_d == d2))
      {
         --aux_d;
         g--;
      }
   }
   return g;
}

Data operator+(const Data& d, const int& g)
{
   Data aux_d(d);
   for(int i = 0; i < g; i++)
      ++aux_d;
   return aux_d;
}

Data Data::operator+(const int& g) const
{
   Data aux_d(*this);
   for(int i = 0; i < g; i++)
      ++aux_d;
   return aux_d;
}

Data Data::operator-(const int& g) const
{
   Data aux_d(*this);
   for(int i = 0; i < g; i++)
      --aux_d;
   return aux_d;
}

void Data::operator+=(const int& g) 
{
   for(int i = 0; i < g; i++)
      ++(*this);  
}

void Data::operator-=(const int& g) 
{
   for(int i = 0; i < g; i++)
      --(*this);  
}

bool operator<(const Data& d1, const Data& d2) 
{
   int data1 = d1.anno * 10000 + d1.mese *100 + d1.giorno;
   int data2 = d2.anno * 10000 + d2.mese *100 + d2.giorno;
   return data1 < data2;
}

bool operator==(const Data& d1, const Data& d2)
{
   return d1.giorno == d2.giorno && d1.mese == d2.mese && d1.anno == d2.anno;
}

Data::Data(const Data& d)
{
   giorno = d.giorno;
   mese = d.mese;
   anno = d.anno;
}