OPTIONS = -Wall -std=c++11

Driver: driver.o palestra.o persona.o
	g++ -o Driver palestra.o driver.o persona.o

palestra.o: palestra.cpp palestra.hpp
	g++ -c $(OPTIONS) palestra.cpp 

driver.o: driver.cpp palestra.hpp
	g++ -c $(OPTIONS) driver.cpp 

persona.o: persona.cpp persona.hpp
	g++ -c $(OPTIONS) persona.cpp 

clean:
	rm -f Driver palestra.o driver.o persona.o 
