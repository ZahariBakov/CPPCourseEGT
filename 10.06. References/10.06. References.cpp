#include <iostream>

int main() {
    int originalVar = 42;

    // Деклариране на референция
    int& refVar = originalVar;

    std::cout << "Original Variable: " << originalVar << std::endl;
    std::cout << "Reference Variable: " << refVar << std::endl;

    // Промяна на стойността през референцията
    refVar = 99;

    std::cout << "After Modification:" << std::endl;
    std::cout << "Original Variable: " << originalVar << std::endl;
    std::cout << "Reference Variable: " << refVar << std::endl;

    return 0;
}
