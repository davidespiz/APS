OPTIONS = -Wall -std=c++11

driver.exe: data.o film.o cliente.o copia_film.o noleggio.o video_noleggio.o driver.o
	g++ -o driver.exe driver.o data.o film.o cliente.o copia_film.o noleggio.o video_noleggio.o

clean:
	rm *.o *.exe

data.o: data.hpp data.cpp
	g++ -c $(OPTIONS) data.cpp

film.o: film.hpp film.cpp
	g++ -c $(OPTIONS) film.cpp

cliente.o: cliente.hpp cliente.cpp
	g++ -c $(OPTIONS) cliente.cpp

copia_film.o: copia_film.hpp copia_film.cpp film.hpp data.hpp
	g++ -c $(OPTIONS) copia_film.cpp

noleggio.o: noleggio.hpp noleggio.cpp copia_film.hpp cliente.hpp
	g++ -c $(OPTIONS) noleggio.cpp

video_noleggio.o: video_noleggio.hpp video_noleggio.cpp noleggio.hpp
	g++ -c $(OPTIONS) video_noleggio.cpp

driver.o: driver.cpp video_noleggio.hpp
	g++ -c $(OPTIONS) driver.cpp

