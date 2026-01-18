// File orario.hpp
#ifndef ORARIO_HPP
#define ORARIO_HPP
#include <iostream>

class Orario
{
  friend bool operator<(const Orario& o1, const Orario& o2);
  friend bool operator<=(const Orario& o1, const Orario& o2);
  friend bool operator==(const Orario& o1, const Orario& o2);
  friend int operator-(const Orario& o1, const Orario& o2);  // differenza in minuti
  friend std::ostream& operator<<(std::ostream& os, const Orario& o);
public:
  Orario(unsigned o, unsigned m);
  unsigned Ore() const { return ore; }
  unsigned Minuti() const { return minuti; }
private:
  unsigned ore, minuti;
};
#endif
