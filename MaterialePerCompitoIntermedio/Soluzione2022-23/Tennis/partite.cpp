#include <fstream>
#include <string>
#include <tuple>  // per tie
#include "../Date/Data.hpp"

using namespace std;

pair<unsigned,Data> RisultatiGiocatore(string nome_file, string giocatore)
{
	string nome1, nome2, buffer;
	Data d, ds_max, dg_min, dg_max;
	bool giocato = false, perso = false;
	
   ifstream is(nome_file);
   while (is >> nome1 >> buffer >> nome2 >> buffer >> buffer >> d)
   {
	   if (nome1 == giocatore || nome2 == giocatore )
	   {
		   if (!giocato)
		   {
			   dg_min = d;
			   dg_max = d;
			   giocato = true;
		   }
		   else
		   {
			   if (d < dg_min)
			      dg_min = d;
			   else if (d > dg_max)
				  dg_max = d;				   
		   }
	   }
	   if (nome2 == giocatore)
	   {
		   if (!perso)
		   {
			   ds_max = d;
			   perso = true;
		   }
		   else
		   {
			   if (d > ds_max)
				   ds_max = d;
		   }
	   }
   }
   cerr << dg_max << " " << dg_min << endl;
   return make_pair(dg_max - dg_min,ds_max);
}

int main (int argc, char* argv[])
{ 
  unsigned giorni_tra_giocate;
  Data ultima_sconfitta;
  tie(giorni_tra_giocate,ultima_sconfitta) = RisultatiGiocatore(argv[1], argv[2]);
  cout << "Numero di giorni tra le partite giocate " << giorni_tra_giocate << endl;
  cout << "Data dell'ultima sconfitta " << ultima_sconfitta << endl;
  return 0;
}