OPTIONS = -Wall -std=c++11

DriverVettore.exe: DriverVettore.o VettoreCompatto.o
	g++ -o DriverVettore.exe DriverVettore.o VettoreCompatto.o

VettoreCompatto.o: VettoreCompatto.cpp VettoreCompatto.hpp
	g++ -c $(OPTIONS) VettoreCompatto.cpp

DriverVettore.o: DriverVettore.cpp VettoreCompatto.hpp
	g++ -c $(OPTIONS) DriverVettore.cpp

clean:
	rm -f DriverVettore.exe DriverVettore.o VettoreCompatto.o
