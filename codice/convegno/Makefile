OPTIONS = -Wall -std=c++11

TestConvegno.exe: Convegno.o Presentazione.o TestConvegno.o
	g++ -o TestConvegno.exe Convegno.o Presentazione.o TestConvegno.o ../utils/Data.o

clean:
	rm *.o *.exe

Convegno.o: Convegno.cpp Convegno.hpp Presentazione.hpp ../utils/Data.hpp Aula.hpp
	g++ $(OPTIONS) -g -c Convegno.cpp

Presentazione.o: Presentazione.cpp Presentazione.hpp ../utils/Data.hpp Aula.hpp
	g++ $(OPTIONS) -g -c Presentazione.cpp

MenuConvegno.o: MenuConvegno.cpp Convegno.hpp Presentazione.hpp ../utils/Data.hpp Aula.hpp
	g++ $(OPTIONS) -g -c MenuConvegno.cpp

TestConvegno.o: TestConvegno.cpp Convegno.hpp Presentazione.hpp ../utils/Data.hpp Aula.hpp
	g++ $(OPTIONS) -g -c TestConvegno.cpp
