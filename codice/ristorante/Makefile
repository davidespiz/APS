OPTIONS = -Wall -std=c++11

ristorante.exe: ristorante.o DriverRistorante.o 
	g++ -o ristorante.exe ristorante.o DriverRistorante.o 

ristorante.o: ristorante.cpp ristorante.hpp persona.hpp
	g++ -c $(OPTIONS) ristorante.cpp

DriverRistorante.o: DriverRistorante.cpp ristorante.hpp persona.hpp
	g++ -c $(OPTIONS) DriverRistorante.cpp

clean:
	rm ristorante.exe ristorante.o DriverRistorante.o