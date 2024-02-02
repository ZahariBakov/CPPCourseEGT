#include <iostream>

//int main() {
//    int n;
//
//    std::cout << "enter array length " << std::endl;
//    std::cin >> n;
//
//    int* arr = new int[n];
//
//    for (int i = 0; i < n; ++i) {
//        std::cout << "arr[" << i << "] = ";
//        std::cin >> arr[i];
//    }
//
//    for (int j = 0; j < n; ++j) {
//        std::cout << arr[j] << std::endl;
//    }
//
//    return 0;
//}


//void printArray2D(int arr2D[2][4]) {
//    for (int row = 0; row < 2; ++row) {
//        for (int col = 0; col < 4; ++col) {
//            std::cout << arr2D[row][col] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    std::cout << std::endl;
//}

//int main() {
//    int arr2D[2][4] = {
//        { 11, 12, 45, 55 }, // row 0 values
//        { 23, 45, 56, 77 } // row 0 values
//    };
//
//    printArray2D(arr2D);
//
//    return 0;
//}


//int main() {
//    int rows;
//    std::cout << "Enter array rows ";
//    std::cin >> rows;
//
//    int cols;
//    std::cout << "Enter array cols ";
//    std::cin >> cols;
//
//    int numbers[rows][cols];
//
//    for (int row = 0; row < rows; ++row) {
//        for (int col = 0; col < cols; ++col) {
//            std::cout << "Enter element ";
//            std::cin >> numbers[row][col];
//        }
//    }
//
//    printArray2D(numbers);
//
//    return 0;
//}


void printArray2DPtr(int** arr2D, int rows, int cols) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::cout << arr2D[row][col] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void createArr2DFromInput(int** arr2D, int rows, int cols) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::cout << "Enter current day temperature ";
            std::cin >> arr2D[row][col];
        }
    }
}

void monthFromArray(int num) {
    switch (num)  {
    case 1:
        std::cout << "January ";
        break;
    case 2:
        std::cout << "February ";
        break;
    case 3:
        std::cout << "March ";
        break;
    default:
        break;
    }
}

int main() {
    int rows, cols;
    std::cout << "enter array rows " << std::endl;
    std::cin >> rows;
    std::cout << "enter array cols " << std::endl;
    std::cin >> cols;

    int product = 1;
    int count = 0;

    std::string months[12] = { "January", "February", "March", "April", 
        "May",  "June", "July", "August", "September", "October", 
        "November", "December" };

    int** arr2D = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr2D[i] = new int[cols];
    }
    
    createArr2DFromInput(arr2D, rows, cols); 

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (arr2D[row][col] == 20) {
                std::cout << "Month is ";
                std::cout << months[row];
                //monthFromArray(row + 1);
                std::cout << std::endl;
                std::cout << "Day is " << col + 1 << std::endl;
                // product *= arr2D[row][col];
                count++;
            }
        }
    }

    // std::cout << "Product is: " << product << "\n" << std::endl;
    std::cout << "Temp 20 count " << count << "\n" << std::endl;

    // printArray2DPtr(arr2D, rows, cols);

    return 0;
}
