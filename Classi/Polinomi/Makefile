Driver: driver.o polinomi.o
	g++ -o Driver driver.o polinomi.o 

driver.o: driver.cpp polinomi.hpp
	g++ -c -Wall driver.cpp polinomi.hpp

polinomi.o: polinomi.cpp polinomi.hpp
	g++ -c -Wall polinomi.cpp polinomi.hpp

clean: 
	rm -f Driver