DriverPila.exe: DriverPila.o Pila.o
	g++ -o DriverPila.exe DriverPila.o Pila.o

DriverPila.o: DriverPila.cpp Pila.hpp
	g++ -c -g -Wall DriverPila.cpp

Pila.o: Pila.cpp Pila.hpp
	g++ -c -g -Wall Pila.cpp

clean:
	rm -f DriverPila.o Pila.o DriverPila.exe