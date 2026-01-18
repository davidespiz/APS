// file Turno.hpp
#ifndef TURNO_HPP
#define TURNO_HPP
#include <string>
#include <stdexcept>

class Turno
{
 public:
  Turno(unsigned s1, unsigned s2) 
  { if (s1 >= s2) throw std::domain_error("Turno impossibile"); start = s1; stop = s2; }
  unsigned Start() const { return start; }
  unsigned Stop() const { return stop; }
  unsigned NumOre() const { return stop - start; }
 private:
  unsigned start, stop;
};                                                 

inline bool Disgiunti(Turno* t1, Turno* t2) 
{ return t1->Stop() <= t2->Start() || t2->Stop() <= t1->Start(); }    
#endif
