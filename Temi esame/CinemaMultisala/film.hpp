#include <iostream>
using namespace std;

#ifndef FILM_HPP
#define FILM_HPP

class Film
{
   friend ostream& operator<<(ostream& os, const Film& f);
   public:
      Film(string t, int d);
      string Titolo() const {return titolo;}
      int Durata() const {return durata;}
   private:
      string titolo;
      int durata;
};

#endif