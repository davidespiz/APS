// file biblioteca.cpp
#include <stdexcept>
#include "biblioteca.hpp"

void Biblioteca::Acquisisce(Libro * l)
{
  RecordLibro r;
  r.volume = l;
  r.affidatario = nullptr;
  r.in_prestito = false;
  bib.push_back(r);
}

void Biblioteca::Prestito(Libro* l, Persona* p)
{
  int i = CercaLibro(l);
  if (i == -1)
    throw std::invalid_argument("Libro assente");
  if (bib[i].in_prestito)
    throw std::invalid_argument("Libro gia' in prestito");
  bib[i].affidatario = p;
  bib[i].in_prestito = true;
}

void Biblioteca::Restituzione(Libro* l)
{
  int i = CercaLibro(l);
  if (i == -1)
    throw std::invalid_argument("Libro assente");
  if (!bib[i].in_prestito)
    throw std::invalid_argument("Libro non in prestito");
  bib[i].affidatario = nullptr;
  bib[i].in_prestito = false;
}

bool Biblioteca::InPrestito(Libro* l) const
{
  int i = CercaLibro(l);
  return i != -1 && bib[i].in_prestito;
}
 
bool Biblioteca::Disponibile(Libro* l) const
{
  int i = CercaLibro(l);
  return i != -1 && !bib[i].in_prestito;
}
 
std::vector<Libro*> Biblioteca::Prestiti(Persona* p) const
{
  std::vector<Libro*> libri;
  for (unsigned i = 0; i < bib.size(); i++)
    if (bib[i].in_prestito && bib[i].affidatario == p)
      libri.push_back(bib[i].volume);
  return libri;
}

int Biblioteca::CercaLibro(Libro* l) const
{
  for (unsigned i = 0; i < bib.size(); i++)
    if (bib[i].volume == l)
      return i;
  return -1;
}

std::ostream& operator<<(std::ostream& os, const Biblioteca& b)
{
   for (unsigned i = 0; i < b.bib.size(); i++)
   {
      os << b.bib[i].volume->Nome() << " ";
      if (b.bib[i].in_prestito)
        os << "in prestito a " << b.bib[i].affidatario->Nome() << std::endl;
      else
        os << "disponibile" << std::endl;
   }
   return os;
}
