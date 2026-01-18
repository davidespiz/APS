OPTIONS = -Wall -std=c++11

cinema.exe: DriverCinema.o cinema.o proiezione.o film.o orario.o prenotazione.o sala.o
	g++ -o cinema.exe DriverCinema.o cinema.o proiezione.o film.o orario.o prenotazione.o sala.o

DriverCinema.o: DriverCinema.cpp cinema.hpp proiezione.hpp film.hpp sala.hpp orario.hpp prenotazione.hpp
	g++ -c $(OPTIONS) DriverCinema.cpp

cinema.o: cinema.cpp cinema.hpp proiezione.hpp film.hpp sala.hpp orario.hpp prenotazione.hpp
	g++ -c $(OPTIONS) cinema.cpp

proiezione.o: proiezione.cpp proiezione.hpp film.hpp sala.hpp orario.hpp prenotazione.hpp
	g++ -c $(OPTIONS) proiezione.cpp

film.o: film.cpp film.hpp
	g++ -c $(OPTIONS) film.cpp

orario.o: orario.cpp orario.hpp
	g++ -c $(OPTIONS) orario.cpp

prenotazione.o: prenotazione.cpp prenotazione.hpp
	g++ -c $(OPTIONS) prenotazione.cpp

sala.o: sala.cpp sala.hpp
	g++ -c $(OPTIONS) sala.cpp

clean:
	rm -f cinema.exe DriverCinema.o cinema.o proiezione.o film.o orario.o prenotazione.o sala.o