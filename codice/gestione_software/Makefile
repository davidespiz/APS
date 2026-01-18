OPTIONS = -Wall -std=c++11

DriverGestione.exe: DriverGestione.o Gestione.o Pacchetto.o Versione.o 
	g++ -o DriverGestione.exe DriverGestione.o Pacchetto.o Versione.o Gestione.o ../utils/Data.o

DriverGestione.o: DriverGestione.cpp Gestione.hpp Pacchetto.hpp Versione.hpp
	g++ -c $(OPTIONS) DriverGestione.cpp

Gestione.o: Gestione.cpp Gestione.hpp Pacchetto.hpp Versione.hpp
	g++ -c $(OPTIONS) Gestione.cpp

Versione.o: Versione.cpp Pacchetto.hpp Versione.hpp
	g++ -c $(OPTIONS) Versione.cpp

Pacchetto.o: Pacchetto.cpp Pacchetto.hpp
	g++ -c $(OPTIONS) Pacchetto.cpp

clean:
	rm -f DriverGestione.exe DriverGestione.o Gestione.o Pacchetto.o Versione.o 