// File noleggio.hpp
#ifndef NOLEGGIO_HPP
#define NOLEGGIO_HPP
#include <stdexcept>
#include "copia_film.hpp"
#include "cliente.hpp"

class Noleggio
{
  friend std::ostream& operator<<(std::ostream& os, const Noleggio& n);  
public:
  Noleggio(CopiaFilm* cp, Cliente* c);
  CopiaFilm* VediCopia() const { return copia; }
  Cliente* VediCliente() const { return cliente; }
  bool Restituito() const { return restituito; }
  Data Inizio() const { return inizio; }
  Data Restituzione() const 
  { if (!restituito) throw std::invalid_argument("Film non ancora restituito"); 
    return restituzione; }
  int Addebito() const 
  { if (!restituito) throw std::invalid_argument("Film non ancora restituito"); 
    return addebito; }       	
  void Restituisci(unsigned t);  
private:
  CopiaFilm* copia;
  Cliente* cliente;
  Data inizio;
  Data restituzione;
  bool restituito;
  unsigned addebito;
};
#endif

