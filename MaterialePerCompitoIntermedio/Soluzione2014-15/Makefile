TestMultiPila.exe: MenuMultiPila.o MultiPila.o
	g++ -o TestMultiPila.exe MenuMultiPila.o MultiPila.o

MenuMultiPila.o: MenuMultiPila.cpp MultiPila.hpp
	g++ -Wall -g -c MenuMultiPila.cpp

MultiPila.o: MultiPila.cpp MultiPila.hpp
	g++ -Wall -g -c MultiPila.cpp

clean:
	rm -f TestMultiPila.exe MenuMultiPila.o MultiPila.o