// File data.hpp
#ifndef DATA_HPP
#define DATA_HPP
#include<iostream>

using namespace std;

class Data
{
  friend Data operator|(const Data& d1, const Data& d2);
  friend bool operator==(const Data& d1, const Data& d2);
  friend bool operator<(const Data& d1, const Data& d2);
  friend bool operator>(const Data& d1, const Data& d2);
  friend bool operator!=(const Data& d1, const Data& d2);
  friend int operator-(const Data& d1, const Data& d2);
  friend istream& operator>>(istream& is, Data& d);
  friend ostream& operator<<(ostream& os, const Data& d);
 public:
  Data(int g, int m, int a);
  Data();
  int Giorno() const { return giorno; }
  int Mese() const { return mese; }
  int Anno() const { return anno; }
  void operator++();
  void operator--();
  void operator+=(int n);
  Data operator+(int n) const;
  void Stampa() const;
 private:
  int giorno;
  int mese;
  int anno;
  bool Valida() const;
  bool Bisestile() const;
  int GiorniDelMese() const;
};

#endif
