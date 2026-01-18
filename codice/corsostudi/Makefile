COMP_OPT = -Wall -Wfatal-errors -std=c++11 -Wextra

TestCorsoStudi.exe: Driver.o CorsoStudi.o Curriculum.o Insegnamento.o
	g++ -o TestCorsoStudi.exe Driver.o CorsoStudi.o Curriculum.o Insegnamento.o

Driver.o: Driver.cpp CorsoStudi.hpp Curriculum.hpp Insegnamento.hpp
	g++ $(COMP_OPT) -c Driver.cpp

CorsoStudi.o: CorsoStudi.cpp CorsoStudi.hpp Curriculum.hpp Insegnamento.hpp
	g++ $(COMP_OPT) -c CorsoStudi.cpp

Curriculum.o: Curriculum.cpp Curriculum.hpp Insegnamento.hpp
	g++ $(COMP_OPT) -c Curriculum.cpp

Insegnamento.o: Insegnamento.cpp Insegnamento.hpp
	g++ $(COMP_OPT) -c Insegnamento.cpp

clean:
	rm -f TestCorsoStudi.exe Driver.o CorsoStudi.o Curriculum.o Ingegnamento.o