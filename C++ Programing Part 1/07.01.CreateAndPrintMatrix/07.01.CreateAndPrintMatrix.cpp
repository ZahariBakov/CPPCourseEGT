#include <iostream>

int main() {
    int arr2D[5][10]{};
    int element = 10;

    // Adding element to aray
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 10; ++col) {
            element++;
            arr2D[row][col] = element;
        }
    }

    // Printing array in normal tabular form
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 10; ++col) {
            std::cout << arr2D[row][col] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Printing array in with rows and columns reversed
    for (int col = 0; col < 10; ++col) {
        for (int row = 0; row < 5; ++row) {
            std::cout << arr2D[row][col] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
