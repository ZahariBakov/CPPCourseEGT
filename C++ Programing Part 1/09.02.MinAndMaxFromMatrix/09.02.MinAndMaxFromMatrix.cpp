#include <iostream>

int main() {
    // initializing variables
    int arr2D[6][5]{ {48,72,13,14,15},
                     {21,22,53,24,75},
                     {31,57,33,34,35},
                     {41,95,43,44,45},
                     {59,52,53,54,55},
                     {61,69,63,64,65} };
    int maxNum = INT_MIN;
    int minNum = INT_MAX;

    // traversing the matrix and finding the minNum and maxNum
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 5; ++col) {
            if (arr2D[row][col] > maxNum) {
                maxNum = arr2D[row][col];
            }

            if (arr2D[row][col] < minNum) {
                minNum = arr2D[row][col];
            }
        }
    }

    // printing result
    std::cout << "Min number is: " << minNum << "\n";
    std::cout << "Max numbers is: " << maxNum << std::endl;

    return 0;
}
