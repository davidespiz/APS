// File MainConvegno.cpp
#include "Convegno.hpp"

unsigned PresentazioniInConflittoContemporanee(const Convegno& c);

int main()
{
  try
  {
  Data d(1,3,2011);
  Convegno c("Giulio Cesare", d, d+5);
  std::cout << c << std::endl;
  
  Aula a1("A", 100);
  Aula a2("B", 80);
  Aula a3("C", 80);
  Aula a4("D", 60);
  Presentazione p1("Le riforme di Cesare", "Emilio Gabba", 80);
  Presentazione p2("I poteri dell'ultimo Cesare", "Marta Sordi", 90);
  Presentazione p3("Gli Etruschi e la politica di Cesare", "Luciana Aigner Foresti", 70);
  Presentazione p4("Il calendario giuliano", "Leandro Polverini", 60);
  
  std::cout << "Inserisco aule e presentazioni:" << std::endl;
  c.InserisciPresentazione(&p1);
  c.InserisciPresentazione(&p2);
  c.InserisciPresentazione(&p3);
  c.InserisciPresentazione(&p4);
  c.InserisciAula(&a1);
  c.InserisciAula(&a2);
  c.InserisciAula(&a3);
  c.InserisciAula(&a4);
  std::cout << c;
  
  std::cout << "Inserisco conflitti:" << std::endl;
  c.InserisciConflitto(&p1, &p2);
  c.InserisciConflitto(&p3, &p4);
  c.InserisciConflitto(&p1, &p4);
  std::cout << c;
  std::cout << "Nel corso del convegno si tengono in contemporanea " <<
    PresentazioniInConflittoContemporanee(c) <<
    " coppie di presentazioni in conflitto\n" << std::endl;
  
  std::cout << "Inserisco schedulazioni:" << std::endl;
  c.SchedulaPresentazione(&p1, &a2, d+2, 9);
  c.SchedulaPresentazione(&p2, &a1, d+2, 9);
  c.SchedulaPresentazione(&p3, &a3, d+2, 9);
  c.SchedulaPresentazione(&p4, &a4, d+2, 9);
  std::cout << c;
  std::cout << "Nel corso del convegno si tengono in contemporanea " <<
    PresentazioniInConflittoContemporanee(c) <<
    " coppie di presentazioni in conflitto\n" << std::endl;
  
  std::cout << "Rimuovo un conflitto:" << std::endl;
  c.RimuoviConflitto(&p3, &p4);
  std::cout << c;
  std::cout << "Nel corso del convegno si tengono in contemporanea " <<
    PresentazioniInConflittoContemporanee(c) <<
    " coppie di presentazioni in conflitto\n" << std::endl;
  
  std::cout << "Elimino una presentazione:" << std::endl;
  c.EliminaPresentazione(&p4);
  std::cout << c;
  std::cout << "Ho eliminato la presentazione " << p4;
  std::cout << "Nel corso del convegno si tengono in contemporanea " <<
    PresentazioniInConflittoContemporanee(c) <<
    " coppie di presentazioni in conflitto\n" << std::endl;
  }
  catch (std::exception& e)
  {
	  std::cerr << "Eccezione: " << e.what() << std::endl;
	  return 1;
  }
  return 0;
}

unsigned PresentazioniInConflittoContemporanee(const Convegno& c)
{
  unsigned conta = 0;
  for (unsigned i = 0; i < c.NumPresentazioni() - 1; i++)
    for (unsigned j = i+1; j < c.NumPresentazioni(); j++)
      if (c.VediPresentazione(i)->InConflitto(c.VediPresentazione(j)) &&
	       c.VediPresentazione(i)->AulaPresentazione() != nullptr &&
	       c.VediPresentazione(j)->AulaPresentazione() != nullptr &&
	       c.VediPresentazione(i)->OraPresentazione() == 
	         c.VediPresentazione(j)->OraPresentazione() &&
	       c.VediPresentazione(i)->DataPresentazione() == 
	         c.VediPresentazione(j)->DataPresentazione())
	     conta++;
  return conta;
}
