// Testing Standard Library class multiset
#include <iostream>
using std::cout;
using std::endl;

#include <set> // multiset class-template definition

// define short name for multiset type used in this program
typedef std::multiset< int, std::less< int > > Ims;

#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator

int main()
{
    const int SIZE = 10;
    int a[SIZE] = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };
    Ims intMultiset; // Ims is typedef for "integer multiset"
    std::ostream_iterator< int > output(cout, " ");

    cout << "There are currently " << intMultiset.count(15)
        << " values of 15 in the multiset\n";

    intMultiset.insert(15); // insert 15 in intMultiset
    intMultiset.insert(15); // insert 15 in intMultiset
    cout << "After inserts, there are " << intMultiset.count(15)
        << " values of 15 in the multiset\n\n";

    // iterator that cannot be used to change element values
    Ims::const_iterator result;

    // find 15 in intMultiset; find returns iterator
    result = intMultiset.find(15);

    if (result != intMultiset.end()) // if iterator not at end
        cout << "Found value 15\n"; // found search value 15

    // find 20 in intMultiset; find returns iterator
    result = intMultiset.find(20);

    if (result == intMultiset.end()) // will be true hence
        cout << "Did not find value 20\n"; // did not find 20

    // insert elements of array a into intMultiset
    intMultiset.insert(a, a + SIZE);
    cout << "\nAfter insert, intMultiset contains:\n";
    std::copy(intMultiset.begin(), intMultiset.end(), output);

    // determine lower and upper bound of 22 in intMultiset
    cout << "\n\nLower bound of 22: "
        << *(intMultiset.lower_bound(22));
    cout << "\nUpper bound of 22: " << *(intMultiset.upper_bound(22));

    // p represents pair of const_iterators 
    std::pair< Ims::const_iterator, Ims::const_iterator > p;

    // use equal_range to determine lower and upper bound 
    // of 22 in intMultiset
    p = intMultiset.equal_range(22);

    cout << "\n\nequal_range of 22:" << "\n   Lower bound: "
        << *(p.first) << "\n   Upper bound: " << *(p.second);
    cout << endl;
    return 0;
} // end main
