OPTIONS = -Wall -std=c++11

contravvenzioni.exe: DriverContravvenzioni.o vigile.o
	g++ -o contravvenzioni.exe DriverContravvenzioni.o vigile.o

DriverContravvenzioni.o: DriverContravvenzioni.cpp vigile.hpp veicolo.hpp contravvenzione.hpp
	g++ -c $(OPTIONS) DriverContravvenzioni.cpp

vigile.o: vigile.cpp vigile.hpp veicolo.hpp contravvenzione.hpp
	g++ -c $(OPTIONS) vigile.cpp

clean:
	rm -f contravvenzioni.exe DriverContravvenzioni.o vigile.o