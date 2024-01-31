// Demonstrating input and output with iterators.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iterator> // ostream_iterator and istream_iterator

int main()
{
	cout << "Enter two integers: ";

	// create istream_iterator for reading int values from cin
	std::istream_iterator< int > inputInt(cin);

	int number1 = *inputInt; // read int from standard input
	++inputInt; // move iterator to next input value
	int number2 = *inputInt; // read int from standard input

	// create ostream_iterator for writing int values to cout
	std::ostream_iterator< int > outputInt(cout);

	cout << "The sum is: ";
	*outputInt = number1 + number2; // output result to cout
	cout << endl;
	return 0;
} // end main


