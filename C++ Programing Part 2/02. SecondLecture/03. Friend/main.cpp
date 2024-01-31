// Non-friend/non-member functions cannot access private data of a class.
#include <iostream>
using std::cout;
using std::endl;

// Count class definition (note that there is no friendship declaration)
class Count {
    friend void setX(Count&, int);

public:
    // constructor
    Count(): x(0) // initialize x to 0
    {
        // empty body
    } // end constructor Count

    // output x 
    void print() const {
        cout << x << endl;
    } // end function print

private:
    int x; // data member
}; // end class Count

// function setX modifies private data of Count
void setX(Count& c, int val) {
    c.x = val; // ERROR: cannot access private member in Count
} // end function cannotSetX

int main() {
    Count counter; // create Count object

    setX(counter, 3); // SetX is a friend
    counter.print();
    return 0;
} // end main

