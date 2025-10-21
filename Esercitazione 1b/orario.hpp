#ifndef ORA
#define ORA

#include <ctime>

class Orario
{
   public:
   Orario(){secTot = time(NULL);} 
   Orario(unsigned o, unsigned m, unsigned s = 0){secTot = o * 3600 + m * 60 + s;}

   unsigned Ore() const {return secTot / 3600;}
   unsigned Minuti() const {return secTot / 60;}
   unsigned Secondi() const {return secTot;}
   void SommaSecondi(int s);

   private:
   unsigned secTot;
   
};

#endif