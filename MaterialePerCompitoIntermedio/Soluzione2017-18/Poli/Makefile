OPZIONI = -Wall -Wfatal-errors -std=c++11

TestPoli.exe: Poli.o MainPoli.o
	g++ -o TestPoli.exe Poli.o MainPoli.o

MainPoli.o: MainPoli.cpp Poli.hpp
	g++ -c $(OPZIONI) MainPoli.cpp

Poli.o: Poli.cpp Poli.hpp
	g++ -c $(OPZIONI) Poli.cpp

clean:
	rm -f MainPoli.o Poli.o TestPoli.exe