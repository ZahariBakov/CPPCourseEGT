#include <iostream>

int main() {
    int a;
    a = 7;

    int* aPtr = &a;

    std::cout << &a << std::endl;
    std::cout << aPtr << std::endl;
    std::cout << *aPtr << std::endl;

    aPtr++;

    std::cout << aPtr++ << std::endl;
    std::cout << *aPtr++ << std::endl;

    return 0;
}
