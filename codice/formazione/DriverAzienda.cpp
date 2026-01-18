//File DriverAzienda.cpp
#include <cstdlib>
#include "Azienda.hpp"

unsigned NumMaxCorsi(const Azienda& a);

int main()
{
  Azienda a("CorsiDiCucina");
  std::cout << "Il nome dell'azienda e' " << a << std::endl << std::endl;
  
  Cliente c1("Marco","marco@mail.it"), c2("MariaLucia","malu@mail.it"), c3("Andrea","andrea@mail.it"),
    c4("Eleonora","leo@mail.it");
  std::cout << "La lista dei clienti dell'azienda e':" << std::endl;
  std::cout << c1 << std::endl << c2 << std::endl << c3 << std::endl << c4 << std::endl << std::endl;
  a.InserisciCliente(&c1);
  a.InserisciCliente(&c2);
  a.InserisciCliente(&c3);
  a.InserisciCliente(&c4);
  //a.InserisciCliente(&c4);	
  
  Data incor1(1,9,2011), fincor1(15,9,2011), incor2(10,9,2011), fincor2(25,9,2011);	
  Docente doc1("Mario Rossi","rossi@email.it","MR");
  Corso cor1("CucinaItaliana","I migliori piatti del nord e sud Italia",incor1,fincor1,10,&doc1);
  Corso cor2("CucinaFrancese","I segreti piu' importanti degli chef francesi",incor2,fincor2,12,&doc1);
  std::cout << "Corsi disponibili:" << std::endl;
  std::cout << cor1 << std::endl << cor2 << std::endl << std::endl;
  a.InserisciDocente(&doc1);
  a.InserisciCorso(&cor1);
  a.InserisciCorso(&cor2);
  //a.InserisciCorso(&cor2);
  
  a.InserisciClienteCorso(&c1,&cor1);
  a.InserisciClienteCorso(&c2,&cor1);
  a.InserisciClienteCorso(&c3,&cor1);	
  a.InserisciClienteCorso(&c3,&cor2);
  a.InserisciClienteCorso(&c4,&cor2);
  
  std::cout << "Dopo l'inserimento dei clienti nei corsi:" << std::endl;
  std::cout << cor1 << std::endl << cor2 << std::endl << std::endl;
  
  Data giorl1cor1(1,9,2011), giorl2cor1(2,9,2011), giorl3cor1(3,9,2011),
    giorl1cor2(10,9,2011), giorl2cor2(11,9,2011), giorl3cor2(12,9,2011);
  Lezione l1cor1("L1IT",giorl1cor1), l2cor1("L2IT",giorl2cor1), l3cor1("L3IT",giorl3cor1),
    l1cor2("L1FR",giorl1cor2), l2cor2("L2FR",giorl2cor2), l3cor2("L3FR",giorl3cor2);
  a.InserisciLezioneCorso(&l1cor1,&cor1);
  a.InserisciLezioneCorso(&l2cor1,&cor1);
  a.InserisciLezioneCorso(&l3cor1,&cor1);
  a.InserisciLezioneCorso(&l1cor2,&cor2);
  a.InserisciLezioneCorso(&l2cor2,&cor2); //commentando questa riga si testa l'eccezione sull'inserimento di lezioni
  a.InserisciLezioneCorso(&l3cor2,&cor2); //in date successive
  
  std::cout << "Dopo l'inserimento delle lezioni nei corsi:" << std::endl;
  std::cout << cor1 << std::endl << cor2 << std::endl << std::endl;
  
  //a.RimuoviClienteCorso(&c4,&cor1);
  a.RimuoviClienteCorso(&c1,&cor1);
  a.RimuoviClienteCorso(&c4,&cor2);
  
  unsigned n;
  n=NumMaxCorsi(a);
  std::cout << "Il numero massimo di corsi seguiti da un singolo cliente e': " << n << std::endl << std::endl;
  
  std::cout << "Dopo aver rimosso alcuni clienti dai corsi:" << std::endl;
  std::cout << cor1 << std::endl << cor2 << std::endl << std::endl;
  
  a.CancellaLezione(&l3cor2);
  //a.CancellaLezione(&l2cor2);
  
  std::cout << "Dopo aver cancellato l'ultima lezione del corso di cucina francese:" << std::endl;
  std::cout << cor1 << std::endl << cor2 << std::endl << std::endl;	
  
  return 0;
}

unsigned NumMaxCorsi(const Azienda& a)
{
  unsigned i, j, max = 0;
  std::vector<unsigned> num_corsi(a.NumClienti(),0);
  
  for(i = 0; i < a.NumCorsi(); i++)
    for(j = 0; j < a.NumClienti(); j++)
      if (a.VediCorso(i)->EsistePartecipante(a.VediCliente(j)))
	num_corsi[j]++;
  
  max = 0;
  for(j = 0; j < num_corsi.size(); j++)
    if(num_corsi[j] > max)
      max = num_corsi[j];
  return max;
}
