// File DriverCinema.cpp
#include "cinema.hpp"

bool EsisteFilmTroppoLungo(const GestioneCinema& c);
unsigned ContaClientiFedeli(const GestioneCinema& c, std::vector<std::string> v, unsigned k);

int main()
{  
  Film 
    f1("Zelig",123), 
    f2("La rosa purpurea del cairo",90),
    f3("Crimini e misfatti", 200), 
    f4("Anna e le sue sorelle", 93);
  Sala s1("A",200), s2("B",150);
  Proiezione 
    p1(&f1,&s1,Orario(17,00),Orario(19,20)),
    p2(&f1,&s2,Orario(17,00),Orario(19,20)),
    p3(&f2,&s1,Orario(15,00),Orario(17,00)),
    p4(&f2,&s2,Orario(19,40),Orario(21,20)),
    p5(&f3,&s1,Orario(19,30),Orario(21,30)),
    p6(&f4,&s2,Orario(22,00),Orario(23,50));
  Prenotazione q1("Mario",10),
    q2("Mario",8),
    q3("Piero",12),
    q4("Piero",9),
    q5("Piero",7),
    q6("Lucia",4),
    q7("Lucia",4),
    q8("Giovanni",5);
  GestioneCinema c("Multisala Verdi");
  std::vector<std::string> persone;
  unsigned soglia;

  persone.push_back("Mario");
  persone.push_back("Piero");
  persone.push_back("Lucia");
  

  c.InserisciProiezione(&p1);
  c.InserisciProiezione(&p2);
  c.InserisciProiezione(&p3);
  c.InserisciProiezione(&p4);
  c.InserisciProiezione(&p5);
  c.InserisciProiezione(&p6);

  p1.AggiungiPrenotazione(&q1);
  p1.AggiungiPrenotazione(&q2);
  p1.AggiungiPrenotazione(&q3);
  p2.AggiungiPrenotazione(&q4);
  p2.AggiungiPrenotazione(&q5);
  p2.AggiungiPrenotazione(&q6);
  p3.AggiungiPrenotazione(&q7);
  p3.AggiungiPrenotazione(&q8);

  std::cout << c << std::endl;
  if (EsisteFilmTroppoLungo(c))
    std::cout << "Esiste un film troppo lungo" << std::endl;
  else
    std::cout << "Tutti i film sono a posto con la lunghezza" << std::endl;

  c.RimuoviProiezione(&p5);
  if (EsisteFilmTroppoLungo(c))
    std::cout << "Esiste un film troppo lungo" << std::endl;
  else
    std::cout << "Tutti i film sono a posto con la lunghezza" << std::endl;

  std::cout << "Inserisci la soglia di posti: ";
  std::cin >> soglia;
  std::cout << "Ci sono " << ContaClientiFedeli(c,persone,soglia) << " clienti fedeli" << std::endl;
}

bool EsisteFilmTroppoLungo(const GestioneCinema& c)
{
  for (unsigned i = 0; i < c.NumeroProiezioni(); i++)
    {
      Proiezione* p = c.VediProiezione(i);
      if (p->FilmProiettato()->Durata() > 
          static_cast<unsigned>(p->OraFine() - p->OraInizio()))
        return true;
    }
  return false;
}

unsigned ContaClientiFedeli(const GestioneCinema& c, 
                            std::vector<std::string> v, unsigned k)
{
  unsigned conta_prenotazioni, conta_persone = 0;
  for (unsigned i = 0; i < v.size(); i++)
    {
      conta_prenotazioni = 0;
      for (unsigned j = 0; j < c.NumeroProiezioni(); j++)
        {
          Proiezione* p = c.VediProiezione(j);
          for (unsigned h = 0; h < p->NumeroPrenotazioni(); h++)            
            if (p->VediPrenotazione(h)->NomePrenotante() == v[i])
              conta_prenotazioni += p->VediPrenotazione(h)->Posti();
        }
      if (conta_prenotazioni > k)
        conta_persone++;
    }
  return conta_persone;
}
