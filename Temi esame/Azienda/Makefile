FLAGS = -Wall -Wfatal-errors

Distribuzione: Driver.o Azienda.o Negozio.o Magazzino.o
	g++ -o Distribuzione.exe Driver.o Azienda.o Negozio.o Magazzino.o
	
Driver.o: Driver.cpp Azienda.hpp Negozio.hpp Magazzino.hpp
	g++ $(FLAGS) -c Driver.cpp

Azienda.o: Azienda.cpp Azienda.hpp Negozio.hpp Magazzino.hpp
	g++ $(FLAGS) -c Azienda.cpp

Negozio.o: Negozio.cpp Negozio.hpp Magazzino.hpp
	g++ $(FLAGS) -c Negozio.cpp

Magazzino.o: Magazzino.cpp Magazzino.hpp
	g++ $(FLAGS) -c Magazzino.cpp
	
clean:
	rm -f Distribuzione.exe Driver.o Azienda.o Negozio.o Magazzino.o