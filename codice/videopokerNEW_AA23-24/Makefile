OPTIONS = -Wall -Wfatal-errors -O3

all: VideoPoker.exe TestMazzo.exe TestMano.exe TestFrequenze.exe

VideoPoker.exe: Carta.o Random.o Mazzo.o Mano.o VideoPoker.o MainVideoPoker.o
	g++ -o VideoPoker.exe Carta.o Random.o Mazzo.o Mano.o VideoPoker.o MainVideoPoker.o

TestMazzo.exe: Carta.o Random.o Mazzo.o DriverMazzo.o
	g++ -o TestMazzo.exe Carta.o Random.o Mazzo.o DriverMazzo.o

TestMano.exe: Carta.o Random.o Mazzo.o Mano.o DriverMano.o
	g++ -o TestMano.exe Carta.o Random.o Mazzo.o Mano.o DriverMano.o

TestFrequenze.exe: Carta.o Random.o Mazzo.o Mano.o DriverFrequenze.o
	g++ -o TestFrequenze.exe Carta.o Random.o Mazzo.o Mano.o DriverFrequenze.o

Carta.o: Carta.hpp Carta.cpp
	g++ $(OPTIONS) -c Carta.cpp

Random.o: Random.hpp Random.cpp
	g++ $(OPTIONS) -c Random.cpp

Mazzo.o: Mazzo.hpp Carta.hpp Mazzo.cpp
	g++ $(OPTIONS) -c Mazzo.cpp

Mano.o: Mano.hpp Mazzo.hpp Carta.hpp Mano.cpp
	g++ $(OPTIONS) -c Mano.cpp

VideoPoker.o: VideoPoker.hpp Mano.hpp Mazzo.hpp Carta.hpp VideoPoker.cpp
	g++ $(OPTIONS) -c VideoPoker.cpp

MainVideoPoker.o: VideoPoker.hpp Mano.hpp Mazzo.hpp Carta.hpp MainVideoPoker.cpp 
	g++ $(OPTIONS) -c MainVideoPoker.cpp

DriverMazzo.o: Mazzo.hpp Carta.hpp DriverMazzo.cpp
	g++ $(OPTIONS) -c DriverMazzo.cpp

DriverMano.o: Mano.hpp Mazzo.hpp Carta.hpp DriverMano.cpp
	g++ $(OPTIONS) -c DriverMano.cpp
	
clean:
	rm -f Carta.o Random.o Mazzo.o Mano.o VideoPoker.o MainVideoPoker.o DriverMazzo.o DriverMano.o DriverFrequenze.o VideoPoker.exe TestMazzo.exe TestMano.exe TestFrequenze.exe
	

DriverFrequenze.o: Mano.hpp Mazzo.hpp Carta.hpp DriverFrequenze.cpp
	g++ $(OPTIONS) -c DriverFrequenze.cpp

