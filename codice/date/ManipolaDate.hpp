// File ManipolaDate.hpp
#ifndef MANIPOLA_DATE_HPP
#define MANIPOLA_DATE_HPP

bool Bisestile(unsigned);
unsigned GiorniDelMese(unsigned, unsigned);
bool DataValida(unsigned, unsigned, unsigned);
void StampaData(unsigned giorno, unsigned mese, unsigned anno);
void DataSuccessiva(unsigned& giorno, unsigned& mese, unsigned& anno);
void DataSuccessiva2(unsigned& giorno, unsigned& mese, unsigned& anno);
void DataSuccessiva3(unsigned& giorno, unsigned& mese, unsigned& anno);
int ComparaDate(unsigned g1, unsigned m1, unsigned a1, 
		unsigned g2, unsigned m2, unsigned a2);
void InvertiDate(unsigned& g1, unsigned& m1, unsigned& a1, 
		 unsigned& g2, unsigned& m2, unsigned& a2);
unsigned DistanzaTraDate(unsigned g1, unsigned m1, unsigned a1, 
			 unsigned g2, unsigned m2, unsigned a2);
int DistanzaTraDateBidirezionale(unsigned g1, unsigned m1, unsigned a1, 
			 unsigned g2, unsigned m2, unsigned a2);
void Scambia(unsigned& a, unsigned& b);

#endif
