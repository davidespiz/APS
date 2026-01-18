// File casella.hpp
#ifndef CASELLA_HPP
#define CASELLA_HPP
#include <iostream>

class Casella
{
  friend bool operator==(const Casella& c1, const Casella& c2);
  friend std::ostream& operator<<(std::ostream& os, const Casella& c);
 public:
  Casella(unsigned i = 0, unsigned j = 0) { riga = i; colonna = j; }
  unsigned Riga() const { return riga; }
  unsigned Colonna() const { return colonna; }
  void Set(unsigned i, unsigned j) { riga = i; colonna = j; }
 private:
  unsigned riga, colonna;
};

inline bool operator==(const Casella& c1, const Casella& c2)
{
  return c1.riga == c2.riga && c1.colonna == c2.colonna;
}

inline std::ostream& operator<<(std::ostream& os, const Casella& c)
{
  os << "(" << c.riga << "," << c.colonna << ")";
  return os;
}
#endif
