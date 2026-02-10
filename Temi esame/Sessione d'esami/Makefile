OPTIONS = -Wall -std=c++11

Driver: driver.o sessione.o corso.o esame.o data.o
	g++ -o Driver driver.o sessione.o corso.o esame.o data.o

driver.o: driver.cpp sessione.hpp
	g++ -c $(OPTIONS) driver.cpp 

sessione.o: sessione.cpp sessione.hpp corso.hpp studente.hpp esame.hpp
	g++ -c $(OPTIONS) sessione.cpp

corso.o: corso.cpp corso.hpp
	g++ -c $(OPTIONS) corso.cpp

esame.o: esame.cpp esame.hpp corso.hpp studente.hpp Data.hpp
	g++ -c $(OPTIONS) esame.cpp

data.o: Data.cpp Data.hpp
	g++ -c $(OPTIONS) Data.cpp

clean:
	rm -f *.o Driver

