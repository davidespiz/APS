OPTIONS = -Wall -std=c++11

Anagrafe.exe: Comune.o Persona.o Anagrafe.o ../utils/Data.o DriverAnagrafe.o
	g++ -o Anagrafe.exe Comune.o Persona.o Anagrafe.o ../utils/Data.o DriverAnagrafe.o

Comune.o: Comune.cpp Comune.hpp
	g++ -c $(OPTIONS) Comune.cpp

Persona.o: Persona.cpp Persona.hpp ../utils/Data.hpp
	g++ -c $(OPTIONS) Persona.cpp

Anagrafe.o: Anagrafe.cpp Anagrafe.hpp Persona.hpp Comune.hpp ../utils/Data.hpp
	g++ -c $(OPTIONS) Anagrafe.cpp

DriverAnagrafe.o: DriverAnagrafe.cpp Anagrafe.hpp Persona.hpp Comune.hpp ../utils/Data.hpp
	g++ -c $(OPTIONS) DriverAnagrafe.cpp

