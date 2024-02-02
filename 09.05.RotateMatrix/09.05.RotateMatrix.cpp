#include <iostream>

int main() {
    // създаване на матрица
    int arr2D[4][4]{ {1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}
    };
    int size = 4;

    // принтиране на +90 градуса
    for (int col = 0; col < size; ++col) {
        for (int row = size - 1; row >= 0; --row) {
            std::cout << arr2D[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // принтиране на -90 градуса
    for (int j = size - 1; j >= 0; --j) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr2D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
