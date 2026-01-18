OPTIONS = -Wall -std=c++11

snake.exe: main.o snake.o
	g++ -o snake.exe snake.o main.o ../utils/Random.o

snake.o: snake.cpp snake.hpp
	g++ -c $(OPTIONS) snake.cpp

main.o: main.cpp snake.hpp
	g++ -c $(OPTIONS) main.cpp

clean:
	rm -f snake.exe snake.o main.o

