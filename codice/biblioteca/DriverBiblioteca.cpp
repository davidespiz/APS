// file DriveBiblioteca.cpp
#include <iostream>
#include <vector>
#include "biblioteca.hpp"

unsigned ControllaStato(const Biblioteca& b, const std::vector<Libro*>& v);

int main()
{
  Libro l1("a"), l2("b"), l3("c"), l4("d");
  Persona p1("p1");
  std::vector<Libro*> vet(3), vet2;
  Biblioteca b;
  unsigned i;

  vet[0] = &l1;
  vet[1] = &l2;
  vet[2] = &l3;
  b.Acquisisce(&l1);
  b.Acquisisce(&l2);
  b.Acquisisce(&l3);
  std::cout << b << std::endl;
  b.Prestito(&l1, &p1);
  b.Prestito(&l2, &p1);
  
  vet2 = b.Prestiti(&p1);
  std::cout << "Libri in prestito a " << p1.Nome()<< std::endl;
  for (i = 0; i < vet2.size(); i++)
    std::cout << i+1 << " " << vet2[i]->Nome() << std::endl;
  std::cout << std::endl;

  std::cout << b << std::endl;
  std::cout << "Stato vettore : " <<  ControllaStato(b,vet) << std::endl;
  b.Restituzione(&l1);
  b.Restituzione(&l2);
  std::cout << b << std::endl;
  std::cout << "Stato vettore : " <<  ControllaStato(b,vet) << std::endl;
  vet[2] = &l4;
  std::cout << "Stato vettore : " <<  ControllaStato(b,vet) << std::endl;
}

unsigned ControllaStato(const Biblioteca& b, const std::vector<Libro*>& v)
{
  bool esiste_libro_in_prestito = false;
  for (unsigned i = 0; i < v.size(); i++)
  {
    if (b.InPrestito(v[i]))
      esiste_libro_in_prestito = true;
    else
      if (!b.Disponibile(v[i]))
	return 0;
  }
  return esiste_libro_in_prestito ? 2 : 1;
}
