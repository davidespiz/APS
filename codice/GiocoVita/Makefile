OPTIONS = -Wall -std=c++11

GiocoVita.exe: Mondo.o Driver.o
	g++ -o GiocoVita.exe Mondo.o Driver.o

clean:
	rm *.o *.exe

Mondo.o: Mondo.hpp Mondo.cpp
	g++ -c $(OPTIONS) Mondo.cpp

Driver.o: Driver.cpp Mondo.hpp
	g++ -c $(OPTIONS) Driver.cpp

