// File DriverRistorante.cpp
#include <iostream>
#include "persona.hpp"
#include "ristorante.hpp"

void AssegnaGruppi(Ristorante* r, const std::vector<Gruppo*>& gr);
void AssegnaGruppi2(Ristorante* r, std::vector<Gruppo*> gr);

int main()
{ 
  Ristorante ris1("La pergola",7);
  Ristorante ris2("Da Piero",5);
  Persona p1("Mario");
  Persona p2("Luca");
  Persona p3("Francesca");
  Persona p4("Irene");
  Persona p5("Laura");
  Persona p6("Giulio");
  Persona p7("Ilaria");
  Persona p8("Giovanni");
  Persona p9("Alberto");
  Persona p10("Claudia");
  Persona p11("Ludovica");
  Persona p12("Paolo");
  Persona p13("Claudia2");
  Persona p14("Ludovica2");
  Persona p15("Paolo2");

  ris1.AggiungiPersona(&p1,1);
  ris1.AggiungiPersona(&p2,2);
  ris1.AggiungiPersona(&p3,2);
  ris1.ModificaTavolo(3,10);
  std::cout << ris1;
  Gruppo g1,g2, g3, g4, g5;
  g1.AggiungiPersona(&p1);
  g1.AggiungiPersona(&p2);
  g1.AggiungiPersona(&p3);
  g1.AggiungiPersona(&p4);
  g1.AggiungiPersona(&p5);
  g2.AggiungiPersona(&p6);
  g2.AggiungiPersona(&p7);
  g3.AggiungiPersona(&p8);
  g3.AggiungiPersona(&p9);
  g3.AggiungiPersona(&p10);
  g4.AggiungiPersona(&p11);
  g4.AggiungiPersona(&p12);
  g5.AggiungiPersona(&p13);
  g5.AggiungiPersona(&p14);
  g5.AggiungiPersona(&p15);
  ris2.ModificaTavolo(0,6);
  std::vector<Gruppo*> vet(5);
  vet[0] = &g1;
  vet[1] = &g2;
  vet[2] = &g3;
  vet[3] = &g4;
  vet[4] = &g5;
  AssegnaGruppi2(&ris2,vet);
  std::cout << ris2;
}

void AssegnaGruppi(Ristorante* r, const std::vector<Gruppo*>& gr)
{// versione semplice: riempie i tavoli spezzando i gruppi
  unsigned i, j, k = 0;
  for (i = 0; i < gr.size(); i++)
    for (j = 0; j < gr[i]->QuantePersone(); j++)
      {
        if (r->PostiTavolo(k) == r->SedutiTavolo(k))
          k++;
        r->AggiungiPersona(gr[i]->QualePersona(j),k);
      }
}
          
void AssegnaGruppi2(Ristorante* r, std::vector<Gruppo*> gr)
{ // versione 2: alloca un gruppo per tavolo e poi completa
  // i tavoli con gli altri gruppi
  unsigned i, j, k = 0;
  for (i = 0; i < gr.size() && k < r->NumTavoli(); i++)
    {
      for (j = 0; j < gr[i]->QuantePersone(); j++)
        {            
          r->AggiungiPersona(gr[i]->QualePersona(j),k);
          if (r->PostiTavolo(k) == r->SedutiTavolo(k))
            k++;
        }
      k++;
    }
  if (i < gr.size())
    { // i gruppi non sono finiti
      k = 0;
      for (i = 0; i < gr.size(); i++)
        for (j = 0; j < gr[i]->QuantePersone(); j++)
          {
            while (r->PostiTavolo(k) == r->SedutiTavolo(k))
              k++;
            r->AggiungiPersona(gr[i]->QualePersona(j),k);
          }
    }
}
