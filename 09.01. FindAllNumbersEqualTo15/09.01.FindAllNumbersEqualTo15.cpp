#include <iostream>

int main() {
    // initializing variables
    int numbersCount = 0;
    int numbers[9000]{};
    int multiplicationNumberArray[9000]{};
    int currNumSum = 0;
    int numberOfRepetitions = 0;
    int multiplicationSum = 0;
    int biggestNumsAray[10]{};
    int biggestNum = 0;


    // crawling the numbers
    for (int i = 1000; i < 10000; ++i) {
        int fourth = i % 10;
        int third = (i / 10) % 10;
        int second = (i / 100) % 10;
        int first = i / 1000;
        int currNumSum = first + second + third + fourth;

        // if sum of number = 15
        if (currNumSum == 15) {
            numbers[numbersCount] = i;
            multiplicationSum = first * second * third * fourth;
            multiplicationNumberArray[numbersCount] = multiplicationSum;
            numbersCount++;
        }
    }

    // print all numbers whose sum is equal to 15
    std::cout << "All numbers whose sum is equal to 15 are: \n";
    for (int x = 0; x < numbersCount; ++x) {
        std::cout << numbers[x] << " ";
    }
    std::cout << "\n" << "\n";

    // Find biggest multiplication number and count of repetitions
    biggestNum = multiplicationNumberArray[0];

    for (int y = 1; y < numbersCount; ++y) {
        if (multiplicationNumberArray[y] > biggestNum) {
            biggestNum = multiplicationNumberArray[y];
            biggestNumsAray[0] = numbers[y];
            numberOfRepetitions = 1;
        }
        else if (multiplicationNumberArray[y] == biggestNum) {
            biggestNumsAray[numberOfRepetitions] = numbers[y];
            numberOfRepetitions++;
        }
    }

    // print biggest multiplication number or numbers
    if (numberOfRepetitions > 1) {
        if (numberOfRepetitions % 2 != 0) {
            biggestNum = biggestNumsAray[numberOfRepetitions / 2];
        }
        else {
            std::cout << "Biggets multiplication numbers is " << biggestNumsAray[(numberOfRepetitions / 2) - 1]
                << " and " << biggestNumsAray[numberOfRepetitions / 2] << std::endl;
            return 0;
        }
    }
    else if (numberOfRepetitions == 1) {
        biggestNum = biggestNumsAray[0];
    }
    else {
        std::cout << "No matching numbers found." << std::endl;
        return 0;
    }

    std::cout << "Biggets multiplication number is " << biggestNum << std::endl;

    return 0;
}
