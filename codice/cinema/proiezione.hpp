// File proiezione.hpp
#ifndef PROIEZIONE_HPP
#define PROIEZIONE_HPP
#include <vector>
#include <iostream>
#include "film.hpp"
#include "sala.hpp"
#include "orario.hpp"
#include "prenotazione.hpp"

class Proiezione
{
  friend std::ostream& operator<<(std::ostream& os, const Proiezione& p);
public:
  Proiezione(Film* f, Sala* s, Orario inizio, Orario fine);
  Film* FilmProiettato() const { return film; }
  Sala* SalaProiezione() const { return sala; }
  Prenotazione* VediPrenotazione(unsigned i) const { return prenotazioni[i]; }
  unsigned NumeroPrenotazioni() const { return prenotazioni.size(); }
  Orario OraInizio() const { return ora_inizio; }
  Orario OraFine() const { return ora_fine; }
  bool AggiungiPrenotazione(Prenotazione* p);
  void CambiaSala(Sala* s);
  void CambiaOrario(Orario i, Orario f);
private:
  Film* film;
  Sala* sala;
  Orario ora_inizio, ora_fine;
  std::vector<Prenotazione*> prenotazioni;
  unsigned totale_prenotazioni;
};
#endif
