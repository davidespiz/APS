Driver: driver.o persona.o data.o
	g++ -o Driver driver.o persona.o data.o

driver.o: driver.cpp persona.hpp
	g++ -c -Wall driver.cpp persona.hpp

persona.o: persona.cpp persona.hpp 
	g++ -c -Wall persona.cpp persona.hpp 

clean:
	rm -f Driver driver.o persona.o