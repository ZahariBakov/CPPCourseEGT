// Member-function definitions for Time class.
#include <iostream>
using std::cout;

#include <iomanip>
using std::setfill;
using std::setw;

#include "Time1.h" // Time class definition

// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time1::Time1(int hr, int min, int sec)
{
    setTime(hr, min, sec);
} // end Time constructor

// set values of hour, minute, and second
Time1& Time1::setTime(int h, int m, int s) // note Time & return
{
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this; // enables cascading
} // end function setTime

// set hour value
Time1& Time1::setHour(int h) // note Time & return
{
    hour = (h >= 0 && h < 24) ? h : 0; // validate hour
    return *this; // enables cascading
} // end function setHour

// set minute value
Time1& Time1::setMinute(int m) // note Time & return
{
    minute = (m >= 0 && m < 60) ? m : 0; // validate minute
    return *this; // enables cascading
} // end function setMinute

// set second value
Time1& Time1::setSecond(int s) // note Time & return
{
    second = (s >= 0 && s < 60) ? s : 0; // validate second
    return *this; // enables cascading
} // end function setSecond

// get hour value
int Time1::getHour() const
{
    return hour;
} // end function getHour

// get minute value
int Time1::getMinute() const
{
    return minute;
} // end function getMinute

// get second value
int Time1::getSecond() const
{
    return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS) 
void Time1::printUniversal() const
{
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << second;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time1::printStandard() const
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
        << ":" << setfill('0') << setw(2) << minute
        << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM");
} // end function printStandard

