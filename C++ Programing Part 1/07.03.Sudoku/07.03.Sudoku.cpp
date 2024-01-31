#include <iostream>

int main() {

    // Creating array
    int arr[]{ 6, 8, 3, 4, 5, 2, 1, 9, 7,
               9, 1, 5, 7, 8, 6, 3, 4, 2,
               4, 2, 7, 3, 1, 9, 5, 6, 8,
               5, 9, 8, 2, 6, 1, 7, 3, 4,
               7, 6, 4, 8, 3, 5, 2, 1, 9,
               1, 3, 2, 9, 7, 4, 6, 8, 5,
               8, 7, 1, 5, 4, 3, 9, 2, 6,
               3, 4, 9, 6, 2, 7, 8, 5, 1,
               2, 5, 6, 1, 9, 8, 4, 7, 3 };

    /*int arr[]{ 3,5,2, 4,6,9, 7,8,1,
               6,9,7, 1,8,5, 9,3,2,
               8,9,1, 2,7,3, 6,5,4,
               1,3,9, 6,4,2, 5,7,8,
               4,6,5, 8,4,7, 2,1,3,
               2,7,8, 5,3,1, 4,9,6,
               1,2,4, 5,1,8, 3,6,7,
               5,1,3, 9,2,6, 8,4,7,
               7,8,6, 3,5,4, 1,2,9 };*/

    // Printing array in 9x9
    int separator = 0;
    int row = 0;

    for (int i = 0; i < 81; ++i) {
        std::cout << arr[i] << " ";
        separator++;

        if (separator == 9) {
            std::cout << std::endl;
            row++;
            separator = 0;
        }

        if (separator == 3 || separator == 6) {
            std::cout << "|";
        }

        if (row == 3) {
            std::cout << "-------------------";
            std::cout << std::endl;
            row = 0;
        }
    }

    std::cout << std::endl;

    // Create table sudoku
    int sudoku[9][9];
    int idx = 0;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            sudoku[row][col] = arr[idx];
            idx++;
        }
    }
    
    // Checking if Sudoku is correct
    bool isCorrect = true;
    int currNum = 0;
    int digitsArray[9]{};
    int digitsArrayCol[9]{};

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            currNum = sudoku[row][col];
            int idx = currNum - 1;
            digitsArray[idx]++;
            digitsArrayCol[idx]++;
        }   

        // Chek every line if is correct
        for (int i = 0; i < 9; ++i) {
            if (digitsArrayCol[i] != 1) {
                isCorrect = false;
                break;
            }

            digitsArrayCol[i] = 0;
        }

        if (!isCorrect) {
            break;
        }
    }
     // Check all numbers occur exactly 9 times
    for (int i = 0; i < 9; ++i) {
        if (digitsArray[i] != 9) {
            isCorrect = false;
        }
    }

    // Check that numbers occur in each 3x3 cell only once
    // If both checks have passed, then this one has also passed.

    // If is correct
    if (isCorrect) {
        std::cout << "Sudoku is correct.";
    }
    else {
        std::cout << "Sudoku is incorrect.";
    }
    std::cout << std::endl;

    return 0;
}
