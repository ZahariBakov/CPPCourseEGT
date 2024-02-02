#include <iostream>
#include <string>

std::string readInput() {
    std::string result;

    getline(std::cin, result);

    return result;
}

std::string  reverseString(std::string sentence) {
    std::string result;
    int len = sentence.length();

    for (int i = len - 1; i >= 0; --i) {
        result += sentence[i];
    }

    return result;
}

void printString(std::string output) {
    std::cout << output << std::endl;
}

void printNumbersOfVowels(std::string result) {
    int vowels = 0;
    int len = result.length();

    for (int i = 0; i < len; ++i) {
        if (result[i] == 'a' || result[i] == 'e' || result[i] == 'o' || result[i] == 'i' || result[i] == 'u' 
            || result[i] == 'A' || result[i] == 'E' || result[i] == 'O' || result[i] == 'I' || result[i] == 'U') {
            vowels++;
        }
    }

    std::cout << "In sentence: \n" << result << "\n";
    std::cout << "Numbers of vowels is: " << vowels << "." << std::endl;
}

int main() {
    std::string sentence = readInput();
    std::string reverseSentence = reverseString(sentence);
    printString(reverseSentence);

    printNumbersOfVowels(sentence);

    return 0;
}
