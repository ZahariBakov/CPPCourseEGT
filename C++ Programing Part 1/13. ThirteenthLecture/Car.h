#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
public:
	Car(string, int, string, string, string, string, string);

	void setModel(string);
	void inputData();
	void setYear(int);
	void setColor(string);
	void setFuel(string);
	void setTransmission(string);
	void setVin(string);
	void setPlate(string);
	void displayMessage();

private:
	string model;
	int year;
	string color;
	string fuel;
	string vin;
	string transmission;
	string plate;
};

#endif // !CAR_H
