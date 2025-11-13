OPZIONI = -Wall -Wfatal-errors -g

TestA.exe: A.o MainA.o
	g++ -o TestA.exe A.o MainA.o

MainA.o: MainA.cpp A.hpp
	g++ -c $(OPZIONI) MainA.cpp

A.o: A.cpp A.hpp
	g++ -c $(OPZIONI) A.cpp

clean:
	rm -f MainA.o A.o TestA.exe