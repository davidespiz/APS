Driver: driver.o vettore.o
	g++ -o Driver driver.o vettore.o

driver.o: driver.cpp vettore.hpp
	g++ -c -Wall driver.cpp vettore.hpp

vettore.o: vettore.cpp vettore.hpp
	g++ -c -Wall vettore.cpp vettore.hpp

clean: 
	rm -f Driver