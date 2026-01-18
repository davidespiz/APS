OPTIONS = -Wall -std=c++11

DriverBiPila1.exe: Pila.o BiPila1.o DriverBiPila1.o
	g++ -o DriveBiPila1.exe Pila.o BiPila1.o DriverBiPila1.o

DriverBiPila2.exe: BiPila2.o DriverBiPila2.o
	g++ -o DriveBiPila2.exe BiPila2.o DriverBiPila2.o

Pila.o: Pila.cpp Pila.hpp
	g++ -c $(OPTIONS) Pila.cpp

BiPila1.o: BiPila1.cpp BiPila1.hpp Pila.hpp
	g++ -c $(OPTIONS) BiPila1.cpp

BiPila2.o: BiPila2.cpp BiPila2.hpp
	g++ -c $(OPTIONS) BiPila2.cpp

DriverBiPila1.o: DriverBiPila1.cpp BiPila1.hpp Pila.hpp
	g++ -c $(OPTIONS) DriverBiPila1.cpp

DriverBiPila2.o: DriverBiPila2.cpp BiPila2.hpp
	g++ -c $(OPTIONS) DriverBiPila2.cpp

