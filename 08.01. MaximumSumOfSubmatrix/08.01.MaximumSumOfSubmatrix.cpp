#include <iostream>

int main() {
    int rows, cols, sizeSubmatrix;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    std::cout << "Enter number of cols: ";
    std::cin >> cols;

    std::cout << "Enter size of submatrix: ";
    std::cin >> sizeSubmatrix;

    int arr[10][10];

    std::cout << "Enter matrix: " << std::endl;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::cin >> arr[row][col];
        }
    }

    int maxSum = arr[0][0];

    for (int row = 0; row < (rows - sizeSubmatrix + 1); ++row) {
        for (int col = 0; col < (cols - sizeSubmatrix + 1); ++col) {
            
            int sum = 0;
            
            for (int i = 0; i < sizeSubmatrix; ++i) {
                for (int j = 0; j < sizeSubmatrix; ++j) {
                    sum += arr[row + i][col + j];
                }
            }

            if (sum > maxSum) {
                maxSum = sum; 
            }
        }    
    }
    std::cout << std::endl;

    std::cout << "Maximum sum of submatrix with size " << sizeSubmatrix << " is " << maxSum << std::endl;

    return 0;
}