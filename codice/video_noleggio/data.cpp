//file data.cpp
#include "data.hpp"

Data::Data()
{
  //il costruttore senza parametri crea la data odierna
  time_t t = time(nullptr);
  tm* time;
  time = localtime(&t);  
  giorno = time->tm_mday;
  mese = time->tm_mon + 1;  		//i mesi sono rappresentati da 0 a 11
  anno = time->tm_year + 1900;		//gli anni sono contati a partire dal 1900
}

Data::Data( unsigned g, unsigned m, unsigned a)
{
  giorno = g;
  mese = m;
  anno = a;
  
  //se la data non è valida, ponila pari all 1-1-1970
  if (!Valida())
    {
      giorno = 1;
      mese = 1;
      anno = 1970;
    }
}

void Data::operator++()
{
  if (giorno < GiorniDelMese())
    giorno = giorno + 1;
  else if ( mese < 12)
    {
      giorno = 1;
      mese = mese + 1;
    }
  else
    {   
      giorno = 1;
      mese = 1;
      anno = anno + 1;
    }	
}

void Data::operator--()
{
  if (giorno > 1)
    giorno = giorno - 1;
  else if ( mese > 1)
    {         
      mese = mese - 1;
      giorno = GiorniDelMese();
    }	  
  else
    {   
      anno = anno - 1;
      mese = 12;
      giorno = GiorniDelMese();
    }	     	  
}  
  
  
void Data::operator+=(int n)
{  
  int i;

  if (n > 0)
    for (i = 0; i < n; i++)
      ++(*this);
  else 
    for (i = 0; i > n; i--)
      --(*this);
}
 

void Data::operator-=(int n)
{  
  int i;

  if (n > 0)
    for (i = 0; i < n; i++)
      --(*this);
  else 
    for (i = 0; i > n; i--)
      ++(*this);
}
 
 
unsigned Data::GiorniDelMese() const
{
  if ( mese == 4 || mese == 6 || mese == 9 || mese == 11)
    return 30;
  else if (mese == 2)
    {
      if (Bisestile())
	return 29;
      else 
	return 28;
    }
  else 
    return 31;
}

bool Data::Valida() const
{
  return (giorno > 0 && giorno <= GiorniDelMese() && mese > 0 && mese <= 12 && anno >= 0);
}

bool Data::Bisestile() const
{
  if (anno % 4 != 0)
    return false;
  else if (anno % 100 != 0)
    return true;
  else if (anno % 400 != 0)
    return false;
  else
    return true;
}

Data Data::operator+(int n) const
{
  Data d = *this;
  d += n;
  return d;
}

Data Data::operator-(int n) const
{
  Data d = *this;
  d -= n;
  return d;
}

bool operator ==(const Data& d1, const Data& d2)
{
  return ( (d1.giorno == d2.giorno) && (d1.mese == d2.mese) && (d1.anno == d2.anno) );
}

bool operator !=(const Data& d1, const Data& d2)
{
  return ( (d1.giorno != d2.giorno) || (d1.mese != d2.mese) || (d1.anno != d2.anno) );
}

bool operator <=(const Data& d1, const Data& d2)
{
  if (d1.anno < d2.anno)
    return true;
  else if ((d1.anno == d2.anno) && (d1.mese < d2.mese))
    return true;
  else if ((d1.mese == d2.mese) && (d1.giorno <= d2.giorno))
    return true;
  else 
    return false;
}

bool operator >=(const Data& d1, const Data& d2)
{
  if (d1.anno > d2.anno)
    return true;
  else if ((d1.anno == d2.anno) && (d1.mese > d2.mese))
    return true;
  else if ((d1.mese == d2.mese) && (d1.giorno >= d2.giorno))
    return true;
  else 
    return false;
}

bool operator <(const Data& d1, const Data& d2)
{
  if (d1.anno < d2.anno)
    return true;
  else if ((d1.anno == d2.anno) && (d1.mese < d2.mese))
    return true;
  else if ((d1.mese == d2.mese) && (d1.giorno < d2.giorno))
    return true;
  else 
    return false;
}

bool operator >(const Data& d1, const Data& d2)
{
  if (d1.anno > d2.anno)
    return true;
  else if ((d1.anno == d2.anno) && (d1.mese > d2.mese))
    return true;
  else if ((d1.mese == d2.mese) && (d1.giorno > d2.giorno))
    return true;
  else 
    return false;
}

std::ostream& operator<<(std::ostream& os, const Data& d)
{
  os << d.giorno << '/' << d.mese << '/' << d.anno;
  return os;
}

int operator-(const Data& d1, const Data& d2)
{
  int i = 0;
  Data d = d1;
  
  while (d != d2)
    {
      if ( d > d2)
	{
	  i++;
	  --(d);
	}
      else
	{
	  i--;
	  ++(d);
	}
    }
  
  return i;
}

//Compitino del 4 11 2003
//operatore di input che accetta la data sia nel formato:  gg/mm/aaaa  che nel formato:  mm gg, aaaa
//con controllo di validità con impostazione al 1 1 2000 se non è valida
std::istream& operator>>(std::istream& is, Data& d)
{
  char ch;
  unsigned valore;
  
  //leggi il primo numero (potrebbe essere giorno o mese)
  is >> valore;
  
  ch = is.get();
  
  if (ch == '/')
    {
      //formato gg/mm/aaaa
      d.giorno = valore;
      is >> d.mese >> ch >> d.anno;
    }
  else if (ch == ' ')
    {
      //formato mm gg, aaaa
      d.mese = valore;
      is >> d.giorno >> ch >> d.anno;
    }
  else 
    std::cerr << "ATTENZIONE: formato della data in ingresso non valida"<< std::endl;
  
  //verifica la validità
  if (!d.Valida())
    {
      std::cerr << "ATTENZIONE: data inserita non valida. Verra' posta automaticamente al 1/1/2000" << std::endl;
      d.giorno = 1;
      d.mese = 1;
      d.anno = 2000;
    }
  
  return is;
}

