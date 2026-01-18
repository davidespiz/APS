// File snake.hpp
#ifndef SNAKE_HPP
#define SNAKE_HPP
#include <iostream>
#include <vector>
#include "../minato/casella.hpp"

class Snake
{
  friend std::ostream& operator<<(std::ostream& os, const Snake& sn);
  friend std::istream& operator>>(std::istream& os, Snake& sn);
 public:
  Snake(unsigned n, unsigned k);
  void Muovi(char dir);
  void Resuscita() { vivo = true; }
  unsigned Presenza(Casella c) const; // 0: niente, 1: testa, 
                                      //2: collo, ..., k: coda
  bool Vivo() const { return vivo; }
 private:
  unsigned dim;
  std::vector<Casella> corpo; // la testa e' nella locazione 0 del vettore
  bool vivo;
};
#endif
