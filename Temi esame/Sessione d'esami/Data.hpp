// File data.hpp
#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class Data
{
  friend bool operator==(const Data& d1, const Data& d2);
  friend bool operator!=(const Data& d1, const Data& d2);
  friend bool operator<(const Data& d1, const Data& d2);
  friend bool operator<=(const Data& d1, const Data& d2);
  friend bool operator>(const Data& d1, const Data& d2);
  friend bool operator>=(const Data& d1, const Data& d2);
  friend int operator-(const Data& d1, const Data& d2);
  friend std::istream& operator>>(std::istream&, Data&);
  friend  std::ostream& operator<<( std::ostream&, const Data&);
 public:
  Data();
  Data(unsigned g, unsigned m, unsigned a);
  unsigned Giorno() const { return giorno; }
  unsigned Mese() const { return mese; }
  unsigned Anno() const { return anno; }
  void operator++();
  void operator--();
  void operator+=(int n);
  Data operator+(int n);
  void operator=(const Data& d);
  void Stampa() const;
 private:
  unsigned giorno;
  unsigned mese;
  unsigned anno;
  bool Valida() const;
  bool Bisestile() const;
  unsigned GiorniDelMese() const;
};
#endif
