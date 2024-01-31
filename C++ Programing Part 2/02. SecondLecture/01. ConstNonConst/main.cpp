// Attempting to access a const object with non-const member functions.
#include "Time1.h" // include Time1 class definition

int main()
{
    Time1 wakeUp(6, 45, 0); // non-constant object
    const Time1 noon(12, 0, 0); // constant object

    // OBJECT      MEMBER FUNCTION
    wakeUp.setHour(18);  // non-const   non-const

    noon.setHour(12);    // const       non-const

    wakeUp.getHour();      // non-const   const

    noon.getMinute();      // const       const
    noon.printUniversal(); // const       const

    noon.printStandard();  // const       non-const
    return 0;
} // end main

