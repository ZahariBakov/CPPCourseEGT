#include <iostream>

int main() {
    int n;
    std::cout << "Enter matrix size \n";
    std::cin >> n;

    int primaryDiagonalSum = 0;
    int underPrimaryDiagonalSum = 0;
    int underPrimaryDiagonalMaxNum =INT_MIN;
    int underPrimaryDiagonalMinNum =INT_MAX;
    
    // Create matrix 
    // int matrix[10][10]{};

    // This is how to create matrix with dinamic number for Visual Studio
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    // Array with nunbers under primary diagonal in matrix
    // Size of array is ((n * n) - n) / 2 
    int x = ((n * n) - n) / 2;
    int* res = new int[x];
    int resIdx = 0;

    // Fill matrix
    int num = 10;

    for (int i = 0; i < n; ++i) { // i = 0 ; i  1 ; i = 2 ; i = 3
        for (int j = 0; j < n; ++j) { // j = 0 ; j = 1 ; j = 2 ; j = 3
            //std::cout << "Enter matrix element in row " << i 
            //    << " and col " << j << std::endl;
            // std::cin >> matrix[i][j];
            matrix[i][j] = num;
            num++;
        }
    }

    // Primary diagonal sum
    for (int i = 0; i < n; ++i) {
        primaryDiagonalSum += matrix[i][i];
    }

    // Under primary diagonal sum and find max and min num
    for (int row = 1; row < n; ++row) {
        for (int col = 0; col < row; ++col) {
            // Add current number to sum
            underPrimaryDiagonalSum += matrix[row][col];

            // Add current number in res array
            res[resIdx] = matrix[row][col];
            resIdx++;
            
            // Check if current number in matrix is bigger from underPrimaryDiagonalMaxNum
            if (underPrimaryDiagonalMaxNum < matrix[row][col]) {
                underPrimaryDiagonalMaxNum = matrix[row][col];
            }

            // Check if current number in matrix is lower from underPrimaryDiagonalMaxNum
            if (underPrimaryDiagonalMinNum > matrix[row][col]) {
                underPrimaryDiagonalMinNum = matrix[row][col];
            }
        }
    }

    // printing matrix
    std::cout << "matris is \n";
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {

            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // printing res array
    std::cout << "res array is ";
    for (int i = 0; i < x; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Primary diagonal sum is " << primaryDiagonalSum << std::endl;
    std::cout << "Under primary diagonal sum is " << underPrimaryDiagonalSum << std::endl;
    std::cout << "Under primary diagonal max num is " << underPrimaryDiagonalMaxNum << std::endl;
    std::cout << "Under primary diagonal min num is " << underPrimaryDiagonalMinNum << std::endl;

    // creating matrix with 0 values
    int arr2D[5][5]{};

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << arr2D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
