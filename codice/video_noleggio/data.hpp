//file data.hpp
#ifndef DATA_HPP
#define DATA_HPP

#include <ctime>
#include <iostream>

class Data
{
  friend bool operator ==(const Data&, const Data&);
  friend bool operator !=(const Data&, const Data&);
  friend bool operator <=(const Data&, const Data&);
  friend bool operator >=(const Data&, const Data&);
  friend bool operator <(const Data&, const Data&);
  friend bool operator >(const Data&, const Data&);
  friend std::ostream& operator<<(std::ostream&, const Data&);
  friend int operator-(const Data& d1, const Data& d2);
  friend std::istream& operator>>(std::istream& is, Data& d);     
public:
  Data();
  Data(unsigned g, unsigned m, unsigned a);
  unsigned Giorno() const { return giorno; };
  unsigned Mese() const { return mese; };
  unsigned Anno() const { return anno; };
  void operator++();
  void operator--();
  void operator+=(int);
  void operator-=(int);
  Data operator+(int) const;
  Data operator-(int) const;	
private:
  unsigned giorno;
  unsigned mese;
  unsigned anno;
  unsigned GiorniDelMese() const;
  bool Valida() const;
  bool Bisestile() const;
};

#endif

