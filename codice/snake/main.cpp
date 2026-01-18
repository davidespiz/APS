// File main.cpp
#include <fstream>
#include <cstdlib>
#include "snake.hpp"

void Esegui(Snake& sn, std::string mosse);

int main(int argc, char* argv[])
{
  unsigned lato_scacchiera, lunghezza_serpente;
  std::string mosse, nome_file;
  unsigned scelta;

  if (argc == 1)
    {
      std::cout << "Dimensione del lato della scacchiera : ";
      std::cin >> lato_scacchiera;
      std::cout << "Lunghezza del serpente: ";
      std::cin >> lunghezza_serpente;
    }
  else if (argc == 3)
    {
      lato_scacchiera = atoi(argv[1]);
      lunghezza_serpente = atoi(argv[2]);
    }
  else
    {
      std::cerr << "Uso: " << argv[0] << " [lato_scacchiera lunghezza_serpente]";
      return 1;
    }
  Snake sn(lato_scacchiera,lunghezza_serpente);  
  do
    {
      std::cout << sn << std::endl;
      std::cout << "Menu : " << std::endl
           << "  (1) Esegui sequenza di mosse" << std::endl
           << "  (2) Resuscita serpente" << std::endl
           << "  (3) Salva su file" << std::endl
           << "  (4) Leggi da file" << std::endl
           << "  (0) Esci" << std::endl
           << " Scelta : ";
      std::cin >> scelta;
      switch (scelta)
        {
        case 1:
          {
            std::cout << "Sequenza di mosse: ";
            std::cin >> mosse;
            Esegui(sn, mosse);
            break;
          }
        case 2:
          {
            sn.Resuscita();
            break;
          }
        case 3:
          {            
            std::cout << "Nome del file: ";
            std::cin >> nome_file;
            std::ofstream os(nome_file.c_str());
            os << sn;
            break;
          }
        case 4:
          {
            std::cout << "Nome del file: ";
            std::cin >> nome_file;
            std::ifstream is(nome_file.c_str());
            is >> sn;
            break;
          }
        }
    }
  while (scelta != 0);              
  std::cout << "Ciao, alla prossima!" << std::endl;
  return 0;
}

void Esegui(Snake& sn, std::string mosse)
{
  unsigned i = 0;
  while (sn.Vivo() && i < mosse.size())
    {
      sn.Muovi(mosse[i]);
      i++;
    }
}
