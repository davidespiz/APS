OPTIONS = -Wall -std=c++11

Driver: teatro.o data.o driver.o
	g++ -o Driver teatro.o data.o driver.o

driver.o: driver.cpp teatro.hpp 
	g++ -c $(OPTIONS) driver.cpp

teatro.o: teatro.cpp teatro.hpp data.hpp persona.hpp
	g++ -c $(OPTIONS) teatro.cpp 

data.o: data.cpp data.hpp
	g++ -c $(OPTIONS) data.cpp

clean:
	rm -f *.o Driver