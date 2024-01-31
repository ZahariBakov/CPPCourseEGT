#include <iostream>

int main() {
    int size;
    std::cout << "Enter size of cube: \n";
    std::cin >> size;
    int arr2D[20][20]{};
    int colSum = 0;
    int rowSum = 0;
    int primDiagSum = 0;
    int secondDiagSum = 0;
    int oldSum = -5;
    bool isCorrect = false;

    // създаване и попълване на куба
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            std::cout << "Enter number between 0 and 20 \n";
            std::cin >> arr2D[row][col];
        }

    }

    // обхождане и пресмятане на колони, редове и диагонали
    for (int i = 0; i < size; ++i) {
        colSum = 0;
        rowSum = 0;
        // обхождане на всеки ред и вска колона
        for (int j = 0; j < size; ++j) {
            colSum += arr2D[i][j];
            rowSum += arr2D[j][i];

            if (i == j) {
                primDiagSum += arr2D[i][j];
            }

            if ((i + j) == (size - 1)) {
                secondDiagSum += arr2D[i][j];
            }
        }

        if (colSum == rowSum) {
            isCorrect = true;
        }
        else {
            break;
        }
    }

    if (isCorrect) {
        if (oldSum == -5 && colSum == rowSum && rowSum == primDiagSum && primDiagSum == secondDiagSum) {
            isCorrect = true;
        }
        else {
            isCorrect = false;
        }
    }
    
    

    if (isCorrect) {
        std::cout << "The cube is correct, sum is " << colSum << std::endl;
    }

    return 0;
}
