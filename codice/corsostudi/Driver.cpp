#include "CorsoStudi.hpp"

unsigned CreditiObbligatoriComuni(const std::vector<CorsoStudi>& v);

int main()
{
  try
  {
    Insegnamento i1("APS",6,"ING-INF/05",1),
		i2("BD",6,"ING-INF/05",2), i3("RC",9,"ING-INF/05",2),
		i4("AM1",12,"MAT/03",2), i5("AM2",9,"MAT/03",1), i6("SI",7,"ING-INF/05",1);
  
    CorsoStudi gest("Ing. Gestionale", "L08/L09", 180), elet("Ing. Elettronica", "L08", 180),
	    mecc("Ing. Meccanica", "L09", 180);
    gest.CreaCurriculum("Informazione");

    gest.InserisciInsegnamento(&i1,Tipologia::curricolare,3);
    gest.InserisciInsegnamento(&i2,Tipologia::obbligatorio,2);
    gest.InserisciInsegnamento(&i3,Tipologia::obbligatorio,3);
    gest.InserisciInsegnamento(&i4,Tipologia::obbligatorio,1);
    gest.InserisciInsegnamento(&i5,Tipologia::obbligatorio,1);
    gest.InserisciInsegnamento(&i6,Tipologia::curricolare,3);
    gest.InserisciInCurriculum(&i1,"Informazione");
    gest.InserisciInCurriculum(&i6,"Informazione");
    elet.InserisciInsegnamento(&i4,Tipologia::obbligatorio,1);
    elet.InserisciInsegnamento(&i5,Tipologia::obbligatorio,1);
    mecc.InserisciInsegnamento(&i4,Tipologia::obbligatorio,1);
    elet.InserisciInsegnamento(&i5,Tipologia::scelta,2);

	//    gest.InserisciInCurriculum(&i2,"Informazione");

    std::cout << gest << std::endl;
    if (gest.VerificaCrediti())
      std::cout << "Verifica ok" << std::endl;
    else
      std::cout << "Verifica negativa" << std::endl;
    std::cout << elet << std::endl;
    std::cout << mecc << std::endl;
    
    std::vector<CorsoStudi> vet{gest,elet};
    std::cout << "Crediti obbligatori in comune gest/elet: " << CreditiObbligatoriComuni(vet) << std::endl;
    vet.push_back(mecc);
    std::cout << "Crediti obbligatori in comune gest/elet/mecc: " << CreditiObbligatoriComuni(vet) << std::endl;
  }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
  return 0;
}

// funzione esterna che prende un vettore corsi di studi e verifica quanti crediti obbligatori hanno in comune
unsigned CreditiObbligatoriComuni(const std::vector<CorsoStudi>& corsi_studi)
{
  unsigned i, c, crediti = 0;
  std::vector<Insegnamento*> insegnamenti;
  for (i = 0; i < corsi_studi[0].Insegnamenti(); ++i)
  {
    if (corsi_studi[0].VediInsegnamento(i).tipo == Tipologia::obbligatorio)
      insegnamenti.push_back(corsi_studi[0].VediInsegnamento(i).insegnamento);
  }
  for (c = 1; c < corsi_studi.size(); ++c)
    {
      i = 0;
      while (i < insegnamenti.size())
        {
          if(!corsi_studi[c].EsisteInsegnamento(insegnamenti[i],
                                                Tipologia::obbligatorio))
            insegnamenti.erase(insegnamenti.begin() + i);
          else
            i++;
        }		 
    }		  
  for (i = 0; i < insegnamenti.size(); ++i)
    crediti += insegnamenti[i]->Crediti();
  return crediti;
}
