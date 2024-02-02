#include <iostream>
#include <string>

int firstDayFromInput() {
	int firstDay;
	std::string jan1Str;

	// Entering a day
	std::cout << "Enter which day of the week is January 1st. Monday, Tuesday, Wednesday, Thursday, Friday, Saturday or Sunday \n";
	std::cin >> jan1Str;

	// add int from day
	if (jan1Str == "Monday" || jan1Str == "monday") {
		firstDay = 0;
	}
	else if (jan1Str == "Tuesday" || jan1Str == "tuesday") {
		firstDay = 1;
	}
	else if (jan1Str == "Wednesday" || jan1Str == "wednesday") {
		firstDay = 2;
	}
	else if (jan1Str == "Thursday" || jan1Str == "thursday") {
		firstDay = 3;
	}
	else if (jan1Str == "Friday" || jan1Str == "friday") {
		firstDay = 4;
	}
	else if (jan1Str == "Saturday" || jan1Str == "saturday") {
		firstDay = 5;
	}
	else {
		firstDay = 6;
	}

	return firstDay;
}

int leapYearFromInput() {
	int leapYear = 0;
	std::string leapYearStr;

	// Entering whether it is a leap year. 
	std::cout << "Enter if it is a leap year. Yes or No \n";
	std::cin >> leapYearStr;

	if (leapYearStr == "Yes" || leapYearStr == "yes") {
		leapYear = 1;
	}

	return leapYear;
}

int searchedDateFromInput() {
	int searchedDate;

	std::cout << "Entar a searched date: \n";
	std::cin >> searchedDate;

	return searchedDate;
}

int searchedDayFromInput() {
	int day;
	std::string dayStr;

	// Entering searched day
	std::cout << "Entar a searched day. Monday, Tuesday, Wednesday, Thursday, Friday, Saturday or Sunday: \n";
	std::cin >> dayStr;

	// switch searchet day from string to int
	if (dayStr == "Monday" || dayStr == "monday") {
		day = 0;
	}
	else if (dayStr == "Tuesday" || dayStr == "tuesday") {
		day = 1;
	}
	else if (dayStr == "Wednesday" || dayStr == "wednesday") {
		day = 2;
	}
	else if (dayStr == "Thursday" || dayStr == "thursday") {
		day = 3;
	}
	else if (dayStr == "Friday" || dayStr == "friday") {
		day = 4;
	}
	else if (dayStr == "Saturday" || dayStr == "saturday") {
		day = 5;
	}
	else {
		day = 6;
	}

	return day;
}

int main() {
	int jan1 = firstDayFromInput();
	int leapYear = leapYearFromInput();
	int months[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int searchedDate = searchedDateFromInput();
	int searchedDay = searchedDayFromInput();

	int currentFirstDay = jan1;

	int monthSize[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	monthSize[1] += leapYear;

	for (int i = 0; i < 12; ++i) {

		if ((currentFirstDay + (searchedDate - 1)) % 7 == searchedDay) {
			months[i]++;
		}

		currentFirstDay = (currentFirstDay + monthSize[i]) % 7;
	}

	// Printing result
	std::string monthStr[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	std::cout << std::endl;
	std::cout << "The searched date is available in the following months: \n";
	
	for (int i = 0; i < 12; ++i) {
		if (months[i] == 1) {
			std::cout << monthStr[i] << "\n";
		}

	}
	std::cout << std::endl;

	return 0;
}
