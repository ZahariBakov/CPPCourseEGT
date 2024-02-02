#include <iostream>

int main() {
    int arr2D[6][5]{ {79,72,13,14,15},
                     {21,22,53,24,75},
                     {31,57,33,34,35},
                     {41,25,43,44,45},
                     {59,52,53,54,55},
                     {61,69,63,64,65} };
    int number;

    std::cout << "Enter number btween 0 and 100 \n";
    std::cin >> number;

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 5; ++col) {
            if (arr2D[row][col] < number) {
                std::cout << "On indexes [" << row << "][" << col << "] is number " << arr2D[row][col] << std::endl;
            }
        }
    }

    return 0;
}
