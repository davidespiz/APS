Driver.exe: Driver.o contocorrente.o
	g++ -o Driver.exe Driver.o contocorrente.o

Driver.o: Driver.cpp contocorrente.hpp
	g++ -c -Wall Driver.cpp contocorrente.hpp

contocorrente.o: contocorrente.cpp contocorrente.hpp
	g++ -c -Wall contocorrente.cpp contocorrente.hpp

clean: 	
	rm -f Driver.exe