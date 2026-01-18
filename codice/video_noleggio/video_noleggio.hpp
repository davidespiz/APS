//file video_noleggio.hpp
#ifndef VIDEO_NOLEGGIO_HPP
#define VIDEO_NOLEGGIO_HPP
#include <vector>
#include "copia_film.hpp"
#include "noleggio.hpp"

class VideoNoleggio
{
  friend std::ostream& operator<<(std::ostream& os, const VideoNoleggio& vn);
public:
  VideoNoleggio(std::string n) : nome(n) {}
  std::string Nome() const { return nome; }
  unsigned NumFilm() const { return catalogo.size(); }
  unsigned NumClienti() const { return clienti.size(); }
  unsigned NumCopie() const { return copie.size(); }
  unsigned NumNoleggi() const { return noleggi.size(); }
  unsigned NumCopieFilm(Film* f) const;
  Film* VediFilm(unsigned i) const;
  Cliente* VediCliente(unsigned i) const;
  CopiaFilm VediCopia(unsigned i) const;
  Noleggio VediNoleggio(unsigned i) const;
  void InserisciFilm(Film* f);
  void InserisciCliente(Cliente* c);
  void CreaCopiaFilm(std::string s, Film* f);
  void NoleggioCopiaFilm(unsigned n, Film* f, Cliente* c);
  void RestituzioneCopiaFilm(unsigned n, Film* f, int t);
private:
  std::string nome;
  std::vector <Film*> catalogo;
  std::vector <Cliente*> clienti;
  std::vector <CopiaFilm> copie;
  std::vector <Noleggio> noleggi;	
  int CercaFilm(Film* f) const;
  int CercaCliente(Cliente* c) const;
  int CercaCopia(Film* f, int n) const;
};
#endif

