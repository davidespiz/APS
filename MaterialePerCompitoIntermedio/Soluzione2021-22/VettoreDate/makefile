TestData.exe: VettoreDate.o Data.o
	g++ -o TestData.exe VettoreDate.o Data.o

VettoreDate.o: VettoreDate.cpp Data.hpp
	g++ -Wall -Wfatal-errors -c -std=c++11 VettoreDate.cpp

Data.o: Data.cpp Data.hpp
	g++ -Wall -Wfatal-errors -c -std=c++11 Data.cpp

clean:
	rm -f TestData.exe VettoreDate.o Data.o