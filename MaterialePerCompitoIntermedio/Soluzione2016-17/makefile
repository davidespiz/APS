TestCoda.exe: DriverCoda.o Coda.o
	g++ -o TestCoda.exe DriverCoda.o Coda.o

DriverCoda.o: DriverCoda.cpp Coda.hpp
	g++ -Wall -c -std=c++11 DriverCoda.cpp

Coda.o: Coda.cpp Coda.hpp
	g++ -Wall -c -std=c++11 Coda.cpp

clean:
	rm -f TestCoda.exe DriverCoda.o Coda.o