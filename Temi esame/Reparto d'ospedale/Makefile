OPTIONS = -Wall -std=c++11

Driver: driver.o reparto.o data.o stanza.o
	g++ -o Driver driver.o reparto.o data.o stanza.o

driver.o: driver.cpp reparto.hpp
	g++ -c $(OPTIONS) driver.cpp 

reparto.o: reparto.cpp reparto.hpp data.hpp paziente.hpp stanza.hpp
	g++ -c $(OPTIONS) reparto.cpp

data.o: data.cpp data.hpp
	g++ -c $(OPTIONS) data.cpp

stanza.o: stanza.cpp stanza.hpp data.hpp
	g++ -c $(OPTIONS) stanza.cpp

clean:
	rm -f *.o Driver

