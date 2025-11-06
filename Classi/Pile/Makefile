Driver: Driver.o Pile.o
	g++ -o Driver Driver.o Pile.o

Driver.o: Driver.cpp Pile.hpp
	g++ -c -Wall Driver.cpp Pile.hpp

Pile.o: Pile.cpp Pile.hpp
	g++ -c -Wall Pile.cpp Pile.hpp

clean: 
	rm -f Driver