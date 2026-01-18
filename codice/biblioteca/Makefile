OPTIONS = -Wall -std=c++11

biblioteca.exe: DriverBiblioteca.o biblioteca.o
	g++ -o biblioteca.exe DriverBiblioteca.o biblioteca.o

DriverBiblioteca.o: DriverBiblioteca.cpp biblioteca.hpp persona.hpp libro.hpp
	g++ -c $(OPTIONS) DriverBiblioteca.cpp

biblioteca.o: biblioteca.cpp biblioteca.hpp persona.hpp libro.hpp
	g++ -c $(OPTIONS) biblioteca.cpp

clean:
	rm -f biblioteca.exe DriverBiblioteca.o biblioteca.o