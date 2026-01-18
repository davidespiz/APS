OPTIONS = -Wall -std=c++11

TurniAzienda.exe: DriverTurni.o azienda.o
	g++ -o TurniAzienda.exe DriverTurni.o azienda.o

DriverTurni.o: DriverTurni.cpp azienda.hpp impiegato.hpp turno.hpp
	g++ -c $(OPTIONS) DriverTurni.cpp

azienda.o: azienda.cpp azienda.hpp impiegato.hpp turno.hpp
	g++ -c $(OPTIONS) azienda.cpp

clean:
	rm -f DriverTurni.exe DriverTurni.o azienda.o

