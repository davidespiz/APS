#include <fstream>
#include "data.hpp"

void ModificaDate(string nome_file_r, string nome_file_w, int s)
{
   char ch;
   Data data;
   ifstream is(nome_file_r);
   ofstream os(nome_file_w);
   while((ch = is.peek()) != EOF)
   {
      if(ch == '0' || ch == '1' || ch == '2' || ch == '3')
      {
         is >> data;
         data += s;
         os << data;
      }
      else
      {
         ch = is.get();
         os << ch;
      }
   }
   is.close();
   os.close();
}

int main()
{
   ModificaDate("input.txt", "output.txt", 20);
}