Driver.exe: driver.o vettori3D.o
	g++ -o Driver.exe driver.o vettori3D.o

driver.o: driver.cpp vettori3D.hpp
	g++ -c -Wall driver.cpp vettori3D.hpp

vettori3D.o: vettori3D.cpp vettori3D.hpp
	g++ -c -Wall vettori3D.cpp vettori3D.hpp

clean: rm -f Driver.exe