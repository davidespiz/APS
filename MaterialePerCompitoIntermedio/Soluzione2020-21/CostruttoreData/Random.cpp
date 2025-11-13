#include <random>
#include "Random.hpp"

int Random(int a, int b)
{ 
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(a,b);
  return dis(gen);
}


