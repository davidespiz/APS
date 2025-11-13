// File ClasseData.hpp
#ifndef DATA_HPP
#define DATA_HPP

using namespace std;

class Data
{
  friend ostream& operator<<(ostream& os, const Data& d);
  friend bool operator==(const Data& d1, const Data& d2);
  friend bool operator<(const Data& d1, const Data& d2);
  friend int operator-(Data d1, Data d2);
//   friend Data operator&(Data d1, Data d2);
  friend Data operator&(const Data& d1, const Data& d2);
 public:
  Data();
  Data(unsigned g, unsigned m, unsigned a);
  unsigned Giorno() const { return giorno; }
  unsigned Mese() const { return mese; }
  unsigned Anno() const { return anno; }
  void operator++();
  void operator--();
  void operator+=(int n);
  Data operator+(int n) const;
 private:
  unsigned giorno;
  unsigned mese;
  unsigned anno;
  bool Valida() const;
  bool Bisestile() const;
  unsigned GiorniDelMese() const;
};

#endif
