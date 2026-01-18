OPTIONS = -Wall -std=c++11

GiocoOca.exe: GiocoOca.o DriverOca.o
	g++ -o GiocoOca.exe GiocoOca.o DriverOca.o ../utils/Random.o

GiocoOca.o: GiocoOca.cpp GiocoOca.hpp
	g++ -c $(OPTIONS) GiocoOca.cpp

DriverOca.o: DriverOca.cpp GiocoOca.hpp
	g++ -c $(OPTIONS) DriverOca.cpp

clean:
	rm -f GiocoOca.exe GiocoOca.o DriverOca.o

