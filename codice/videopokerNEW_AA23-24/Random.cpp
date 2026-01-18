#include <ctime>
#include <cstdlib>

int Random(int i, int j)
{ static bool init = false;
  if (!init) // alla prima invocazione bisogna inizializzare
             // la sorgente di numeri random
    {
      srand(time(0));
      init = true;
   }
  return (rand() % (j - i + 1)) + i;
}

