#include <fstream>
#include <cstdlib>
#include "Mondo.hpp"

unsigned Evoluzione(std::string file, unsigned k);
bool Membro(const Mondo& m, const std::vector<Mondo>& v);

int main(int argc, char* argv[])
{ // questo programma verifica la funzione Evoluzione e la classe Mondo
  unsigned n, ris;
  std::string nome_file_input;

  if (argc == 3)
    {
      nome_file_input = argv[1];
      n = atoi(argv[2]);
    }
  else if (argc == 2)
    {
      nome_file_input = argv[1];
      std::cout << "Numero di generazioni: ";
      std::cin >> n;
    }
  else if (argc == 1)
    {
      std::cout << "nome file di input: ";
      std::cin >> nome_file_input;
      std::cout << "Numero di generazioni: ";
      std::cin >> n;
    }     	
  else
    {
      std::cerr << "Numero errato di parametri" << std::endl;
      return 1;
    }
  
  ris = Evoluzione(nome_file_input, n);
  if (ris == 1)
    std::cout << "Il mondo muore entro " << n << " generazioni" << std::endl;
  else if (ris == 2)
    std::cout << "Il mondo entra in un ciclo" << std::endl;
  else 
    std::cout << "Il mondo e' ancora in evoluzione" << std::endl;
  return 0;
}

unsigned Evoluzione(std::string nome_file, unsigned k)
{
  std::ifstream is(nome_file.c_str());
  std::vector<Mondo> v;
  Mondo m;
  unsigned i;

  is >> m;
  for (i = 0; i < k; i++)
    {
      v.push_back(m);
      m.Evolvi();
      std::cout << m << std::endl;
      if (!m.EsisteVita())
	return 1;
      if (Membro(m,v))
	return 2;
    }
  return 3;
}

bool Membro(const Mondo& m, const std::vector<Mondo>& v)
{
  for (unsigned i = 0; i < v.size(); i++)
    if (m == v[i])
      return true;
  return false;
}
