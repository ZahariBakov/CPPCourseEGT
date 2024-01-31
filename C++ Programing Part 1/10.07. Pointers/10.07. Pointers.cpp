#include <iostream>

int main() {
    int originalVar = 42;

    // Деклариране на пойнтър
    int* ptrVar = &originalVar;

    std::cout << "Original Variable: " << originalVar << std::endl;
    std::cout << "Pointer Variable (Value): " << *ptrVar << std::endl;
    std::cout << "Pointer Variable (Address): " << ptrVar << std::endl;

    // Промяна на стойността през пойнтъра
    *ptrVar = 99;

    std::cout << "After Modification:" << std::endl;
    std::cout << "Original Variable: " << originalVar << std::endl;
    std::cout << "Pointer Variable (Value): " << *ptrVar << std::endl;
    std::cout << "Pointer Variable (Address): " << ptrVar << std::endl;

    return 0;
}
