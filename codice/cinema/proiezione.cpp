// File proiezione.cpp
#include <stdexcept>
#include "proiezione.hpp"

Proiezione::Proiezione(Film* f, Sala* s, Orario inizio, Orario fine)
 : ora_inizio(inizio), ora_fine(fine)
{
  film = f;
  sala = s;
  totale_prenotazioni = 0;
}

bool Proiezione::AggiungiPrenotazione(Prenotazione* p)
{
  if (totale_prenotazioni + p->Posti() <= sala->Capienza())
  {
    prenotazioni.push_back(p);
    totale_prenotazioni += p->Posti();
    return true;
  }
  else
    return false;
}

void Proiezione::CambiaSala(Sala* s)
{
  if (totale_prenotazioni > s->Capienza())
    throw std::invalid_argument("Sala troppo piccola");
  sala = s;
}

void Proiezione::CambiaOrario(Orario i, Orario f)
{
  ora_inizio = i;
  ora_fine = f;
}

std::ostream& operator<<(std::ostream& os, const Proiezione& p)
{
  os << "Film: " << *(p.film) << std::endl
     << "Sala " << *(p.sala) << ", "
     << p.ora_inizio << "-" << p.ora_fine << std::endl;
  if (p.prenotazioni.size() == 0)
    os << "NESSUNA PRENOTAZIONE" << std::endl;
  else
    {
      os << "PRENOTAZIONI:" << std::endl;
      for (unsigned i = 0; i < p.prenotazioni.size(); i++)
        os << *(p.prenotazioni[i]) << std::endl;
    }
  return os;
}
