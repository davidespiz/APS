Driver.exe: driver.o orario.o
	g++ -o Driver.exe driver.o orario.o 

orario.o: orario.cpp orario.hpp
	g++ -c -Wall orario.cpp orario.hpp
 
driver.o: driver.cpp orario.hpp
	g++ -c -Wall driver.cpp orario.hpp

clean: 
	rm -f Driver.exe