#include "data.hpp"

int main()
{
   Data d1, d2;
   cin >> d1;
   for(int i = 0; i < 4602; i++)
      ++d1;
   cout << d1 << endl;

   return 0;
}