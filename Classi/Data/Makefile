Driver: driver.o data.o
	g++ -o Driver driver.o data.o

driver.o: driver.cpp data.hpp
	g++ -c -Wall driver.cpp data.hpp

data.o: data.cpp data.hpp
	g++ -c -Wall data.cpp data.hpp

clean:
	rm -f Driver