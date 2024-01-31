#include <iostream>
#include<algorithm>

int main() {
    int n = 14;
    int arr[14]{}; // 10 0 12 85 -5 8 3 -9 12 -78 6 65 9 3

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Input array is: ";
    for (int k = 0; k < n; ++k) {
        std::cout << arr[k] << " ";
    }
    std::cout << "\n" << "\n";

    int lastElement = arr[n - 1];
    int idx = 0;

    if (!(lastElement & 1)) {
        idx = 1;;
    }

    std::cout << "Last element is: " << lastElement << "\n";
    std::cout << "\n";

    int filteredArr[7]{};
    int filteredArrSize = 0;
    
    for (idx; idx < n; idx += 2) {
        filteredArr[filteredArrSize] = arr[idx];
        filteredArrSize++;
    }

    std::cout << "Filtered array is: ";
    for (int j = 0; j < filteredArrSize; ++j) {
        std::cout << filteredArr[j] << " "; // 10 12 -5 3 12 6 9
    }
    std::cout << "\n" << "\n";

    std::sort(filteredArr, filteredArr + filteredArrSize, std::greater<int>()); // 12 12 10 9 6 3 -5

    std::cout << "Sorted aray is: ";
    for (int j = 0; j < filteredArrSize; ++j) {
        std::cout << filteredArr[j] << " ";
    }
    std::cout << "\n" << "\n";

    double middleElement = filteredArr[3];
    std::cout << "The middle element is: " << middleElement << "\n";
    std::cout << "\n";

    bool find = false;
    int sumArray[4]{};
    int sumArrayIdx = 0;

    for (int y = 0; y < filteredArrSize; ++y) {
        int currSum = (filteredArr[y] + filteredArr[(filteredArrSize - 1) - y]);
        sumArray[sumArrayIdx] = currSum;
        sumArrayIdx++;

        if (sumArrayIdx == 3) {
            break;
        }
    }

    std::cout << "SumArray is: ";
    for (int d = 0; d < sumArrayIdx; ++d) {
        std::cout << sumArray[d] << " ";
    }

    std::cout << "\n" << "\n";

    for (int z = 0; z < sumArrayIdx; ++z) {
        int currNum = sumArray[z];
        if (currNum > middleElement) {
            if (!find) {
                find = true;
                std::cout << "The numbers that are greater than the middle are: " << sumArray[z] << " ";
            }
            else {
                std::cout << sumArray[z] << " ";
            }
        }  
    }  

    std::cout << std::endl;

    if (!find) {
        std::cout << "No numbers found that are greater than: " << middleElement << "." << std::endl;
    }

    return 0;
}
