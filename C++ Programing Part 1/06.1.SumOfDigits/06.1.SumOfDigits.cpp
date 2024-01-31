#include <iostream>

int main() {
    int arrSize = 0;
    std::cout << "Enter array size: ";
    std::cin >> arrSize;

    int arr[1000];
    bool find = false;

    for (int i = 0; i < arrSize; ++i) {
        int number = 0;
        std::cout << "Enter number: ";
        std::cin >> number;

        if (abs(number) < 100 || abs(number) > 999) {
            std::cout << "Please enter three-digit numbers only.";
            i--;
        }
        else {
            arr[i] = number;
        }
    }

    for (int j = 0; j < arrSize; ++j) {
        int currNumber = abs(arr[j]);

        int sum = 0;

        for (int k = 0; k < 3; ++k) {
            sum += currNumber % 10;
            currNumber /= 10;
        }
        
        if (sum == 9) {
            if (!find) {
                find = true;
                std::cout << "The numbers whose sum is equal to 9. " << arr[j] << " ";
            }
            else {
                std::cout << arr[j] << " ";
            }
        }

    }

    if (find) {
        std::cout << std::endl;
    }
    else {
        std::cout << "There are no numbers whose sum is equal to 9." << std::endl;
    }

    return 0;
}
