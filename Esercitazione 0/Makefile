Driver.exe: Driver.o Primo.o
	g++ -o Driver.exe Driver.o Primo.o

Primo.o: Primo.cpp Primo.hpp
	g++ -c -Wall Primo.cpp Primo.hpp

Driver.o: Driver.cpp Primo.hpp
	g++ -c -Wall Driver.cpp Primo.hpp

clean: 	
	rm -f Driver.exe

ElementiDistinti.exe: ElementiDistinti.cpp
	g++ -o ElementiDistinti.exe ElementiDistinti.cpp
	
