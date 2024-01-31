// Cascading member function calls with the this pointer.
#include <iostream>
using std::cout;
using std::endl;

#include "Time1.h" // Time class definition

int main()
{
	Time1 t; // create Time object

	// cascaded function calls
	t.setHour(18).setMinute(30).setSecond(22);

	// output time in universal and standard formats
	cout << "Universal time: ";
	t.printUniversal();

	cout << "\nStandard time: ";
	t.printStandard();

	cout << "\n\nNew standard time: ";

	// cascaded function calls
	t.setTime(20, 20, 20).printStandard();
	cout << endl;
	return 0;
} // end main

