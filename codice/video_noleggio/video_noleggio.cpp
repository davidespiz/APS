//file video_noleggio.cpp
#include "video_noleggio.hpp"

unsigned VideoNoleggio::NumCopieFilm(Film* f) const
{ // il numero piu' alto e' quello dell'ultima copia inserita
  for (int i = copie.size() - 1; i >= 0; i--)
    if (copie[i].VediFilm() == f)
      return copie[i].Numero();
  return 0; // il film non c'e'
}

Film* VideoNoleggio::VediFilm(unsigned i) const
{
  return catalogo[i];
}

Cliente* VideoNoleggio::VediCliente(unsigned i) const
{
  return clienti[i];
}

CopiaFilm VideoNoleggio::VediCopia(unsigned i) const
{
  return copie[i];
}

Noleggio VideoNoleggio::VediNoleggio(unsigned i) const
{
  return noleggi[i];
}

int VideoNoleggio::CercaFilm(Film* f) const
{
  for (unsigned i = 0; i < catalogo.size(); i++)
    if (catalogo[i] == f)
      return i;	  
  return -1;
}

int VideoNoleggio::CercaCliente(Cliente* c) const
{
  for (unsigned i = 0; i < clienti.size(); i++)
    if (clienti[i] == c)
      return i;	  
  return -1;
}

int VideoNoleggio::CercaCopia(Film* f, int n) const
{
  unsigned i;
  for (i = 0; i < copie.size(); i++)
    if (copie[i].VediFilm() == f && copie[i].Numero() == n)
      return i;	
  return -1;
}

void VideoNoleggio::InserisciFilm(Film* f)
{
  if (CercaFilm(f) != -1)
    throw std::invalid_argument("Film gia' presente");
  catalogo.push_back(f);
}

void VideoNoleggio::InserisciCliente(Cliente* c)
{
  if (CercaCliente(c) != -1)
    throw std::invalid_argument("Cliente gia' presente");
  clienti.push_back(c);
}

void VideoNoleggio::CreaCopiaFilm(std::string s, Film* f)
{
  if (CercaFilm(f) == -1)
    throw std::invalid_argument("Film inesistente");
  Data oggi;
  copie.push_back(CopiaFilm(s, NumCopieFilm(f) + 1, oggi, f));
}

void VideoNoleggio::NoleggioCopiaFilm(unsigned n, Film* f, Cliente* c)
{
  unsigned i; 
  int co = CercaCopia(f, n);
  if (CercaCliente(c) == -1)
    throw std::invalid_argument("Cliente inesistente");
  if (co == -1)
    throw std::invalid_argument("Copia inesistente");
  // verifica che la copia non sia attualmente in noleggio
  for (i = 0; i < noleggi.size(); i++)
    if (noleggi[i].VediCopia()->VediFilm() == copie[co].VediFilm() 
	&&  noleggi[i].VediCopia()->Numero() == copie[co].Numero()
        && !noleggi[i].Restituito())
      throw std::invalid_argument("Copia attualmente in noleggio");
  // poni la copia a noleggio
  noleggi.push_back(Noleggio(&copie[co], c));
}

void VideoNoleggio::RestituzioneCopiaFilm(unsigned n, Film* f, int t)
{
  //verifica l'esistenza della copia
  int indice_noleggio = -1, co = CercaCopia(f, n), addebito;
  unsigned i; 

  if (co == -1)
    throw std::invalid_argument("Copia assente");
  //verifica che la copia sia attualmente in prestito
  for (i = 0; i < noleggi.size(); i++)
    if (noleggi[i].VediCopia()->VediFilm() == copie[co].VediFilm() 
	&& noleggi[i].VediCopia()->Numero() == copie[co].Numero()
	&& !noleggi[i].Restituito())
      {
	indice_noleggio = i;
	break;
      }
  if (indice_noleggio == -1 || noleggi[indice_noleggio].Inizio() > Data())
    throw std::invalid_argument("Noleggio impossibile");
  noleggi[indice_noleggio].Restituisci(t);  
  //addebita il costo del noleggio al cliente
  addebito = noleggi[indice_noleggio].Addebito();
  noleggi[indice_noleggio].VediCliente()->Prelievo(addebito);
}

std::ostream& operator<<(std::ostream& os, const VideoNoleggio& vn)
{
  unsigned i;

  os << std::endl <<"VIDEONOLEGGIO:  " << vn.nome << std::endl << std::endl;
  if (vn.catalogo.size() > 0)  
    {
      os << "Catalogo film:  " << std::endl 
	 << "-------------" << std::endl << std::endl;
      for (i = 0; i < vn.catalogo.size(); i++)
	os << *(vn.catalogo[i]) << std::endl;
    }
  else
    os << "Non ci sono film in catalogo" << std::endl;
  if (vn.copie.size() > 0)  
    {
      os << std::endl << "Copie dei film in catalogo: " << std::endl 
	 << "--------------------------" << std::endl << std::endl;

      for (i = 0; i < vn.copie.size(); i++)
	os << vn.copie[i] << std::endl;
    }
  else
    os << std::endl << "Non ci sono copie dei film in catalogo" << std::endl;
  if (vn.clienti.size() > 0)  
    {  
      os << std::endl << "Clienti con tessera:" << std::endl
	 << "-------------------" << std::endl << std::endl;  
      for (i = 0; i < vn.clienti.size(); i++)
	os << *(vn.clienti[i]) << std::endl;
    }
  else 
    os << std::endl << "Il videonoleggio non ha clienti" << std::endl;  
  if (vn.noleggi.size() > 0)  
    {  
      os << std::endl << "Noleggi effettuati: " << std::endl
	 << "------------------" << std::endl << std::endl;
      for (i = 0; i < vn.noleggi.size(); i++)
	os << vn.noleggi[i] << std::endl;
    }
  else
    os << std::endl << "Non ci sono stati noleggi" << std::endl;	
  os << std::endl << "--------------------------------------------" << std::endl << std::endl;
  return os;
}

