#include <iostream>
#include "Data.hpp"

using namespace std;


int main()
{
	Data d1(12,9,2018), d2(21,10,2018), d3(2,11,2018);
	cout << (d1 & d2) << endl;
	cout << (d3 & d2) << endl;
	return 0;
}

