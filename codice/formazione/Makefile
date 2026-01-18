OPTIONS = -Wall -Wextra -std=c++11

DriverAzienda.exe: DriverAzienda.o Azienda.o Corso.o Lezione.o Docente.o Cliente.o ../utils/Data.o
	g++ -o DriverAzienda.exe DriverAzienda.o Azienda.o Corso.o Lezione.o Docente.o Cliente.o ../utils/Data.o

DriverAzienda.o: DriverAzienda.cpp
	g++ -c $(OPTIONS) DriverAzienda.cpp

Azienda.o: Azienda.cpp Azienda.hpp
	g++ -c $(OPTIONS) Azienda.cpp Azienda.hpp

Corso.o: Corso.cpp Corso.hpp
	g++ -c $(OPTIONS) Corso.cpp Corso.hpp

Lezione.o: Lezione.cpp Lezione.hpp
	g++ -c $(OPTIONS) Lezione.cpp Lezione.hpp

Docente.o: Docente.cpp Docente.hpp
	g++ -c $(OPTIONS) Docente.cpp Docente.hpp

Cliente.o: Cliente.cpp Cliente.hpp
	g++ -c $(OPTIONS) Cliente.cpp Cliente.hpp

clean:
	rm -f DriverAzienda.exe DriverAzienda.o Azienda.o Corso.o Lezione.o Docente.o Cliente.o
