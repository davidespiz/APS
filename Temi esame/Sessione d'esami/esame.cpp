#include "esame.hpp"

void Esame::PrenotaEsame(Studente* s)
{
   iscritti.push_back(s);
}

void Esame::PosticipaEsame(const Data& d)
{
   data = d;
}
