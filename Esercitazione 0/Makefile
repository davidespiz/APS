Driver.exe: Driver.o Eser_0.o
	g++ -o Driver.exe Driver.o Eser_0.o

Eser_0.o: Eser_0.cpp Eser_0.hpp
	g++ -c -Wall Eser_0.cpp Eser_0.hpp

Driver.o: Driver.cpp Eser_0.hpp
	g++ -c -Wall Driver.cpp Eser_0.hpp

clean: 	
	rm -f Driver.exe

ElementiDistinti.exe: ElementiDistinti.cpp
	g++ -o ElementiDistinti.exe ElementiDistinti.cpp
	
