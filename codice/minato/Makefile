OPTIONS = -Wall -std=c++11

campominato.exe: campominato.o main.o ../utils/Random.o
	g++ -o campominato.exe campominato.o main.o ../utils/Random.o

campominato.o: campominato.cpp campominato.hpp casella.hpp ../utils/Random.hpp
	g++ -c $(OPTIONS) campominato.cpp

main.o: main.cpp campominato.hpp casella.hpp
	g++ -c $(OPTIONS) main.cpp

clean:
	rm campominato.exe campominato.o main.o