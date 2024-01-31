// Member-function definitions for class Time1.
#include <iostream>
using std::cout;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Time1.h" // include definition of class Time1

// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time1::Time1(int hour, int minute, int second)
{
    setTime(hour, minute, second);
} // end Time1 constructor

// set hour, minute and second values
void Time1::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
} // end function setTime

// set hour value
void Time1::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0; // validate hour
} // end function setHour

// set minute value
void Time1::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0; // validate minute
} // end function setMinute

// set second value
void Time1::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0; // validate second
} // end function setSecond

// return hour value
int Time1::getHour() const // get functions should be const
{
    return hour;
} // end function getHour

// return minute value
int Time1::getMinute() const
{
    return minute;
} // end function getMinute

// return second value
int Time1::getSecond() const
{
    return second;
} // end function getSecond

// print Time1 in universal-time format (HH:MM:SS)
void Time1::printUniversal() const
{
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << second;
} // end function printUniversal

// print Time1 in standard-time format (HH:MM:SS AM or PM)
void Time1::printStandard() // note lack of const declaration
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
        << ":" << setfill('0') << setw(2) << minute
        << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM");
} // end function printStandard


