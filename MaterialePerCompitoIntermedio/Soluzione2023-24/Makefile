OPZIONI = -Wall -Wfatal-errors

TestVettore.exe: Driver.o Vettore.o
	g++ -o TestVettore.exe Driver.o Vettore.o

Driver.o: Driver.cpp Vettore.hpp
	g++ $(OPZIONI) -c Driver.cpp

Vettore.o: Vettore.cpp Vettore.hpp
	g++ $(OPZIONI) -c Vettore.cpp

clean:
	rm -f TestVettore.exe Driver.o Vettore.o