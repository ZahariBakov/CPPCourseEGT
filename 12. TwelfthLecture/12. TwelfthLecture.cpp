#include <iostream>
#include <string>

//int printSignOfNumber() {
//    int number;
//    std::cout << "Enter number: " << std::endl;
//    std::cin >> number;
//
//    if (number > 0) {
//        std::cout << "+";
//    }
//    else {
//        std::cout << "-";
//    }
//
//    std::cout << std::endl;
//
//    return number;
//}
//
//int sumOfTwoNumbersFromInput() {
//    int a, b;
//
//    std::cout << "Enter first number: " << " ";
//    std::cin >> a;
//
//    std::cout << "Enter second number: " << " ";
//    std::cin >> b;
//
//    int sum = a + b;
//
//    return sum;
//}
//
//int elevateNumber(int a) {
//    return a + 1;
//}
//
//int sumOfTwoNumbersWithParameters(int a, int b) {
//    return a + b;
//}
//
//int main() {
//    int x = printSignOfNumber();
//
//    int y = printSignOfNumber();
//    
//    int z = printSignOfNumber();
//    
//    int k = printSignOfNumber();
//
//    std::cout << x << " " << y << " " << z << " " << k << std::endl;
//
//    int sum = sumOfTwoNumbersFromInput();
//
//    std::cout << sum << std::endl;
//
//    int result = sumOfTwoNumbersWithParameters(x, y);
//
//    std::cout << result << std::endl;
//
//    int a = 67;
//
//    std::cout << elevateNumber(a) << std::endl;
//
//    std::cout << a << std::endl;
//
//    return 0;
//}


//int main() {
//    std::string s = "Hello, C++!";
//    int len = s.length();
//    int size = s.size();
//
//    std::cout << len << " vs " << size << "\n";
//
//    char ch = s.at(4);
//    std::cout << ch << std::endl;
//
//    // char to int
//    std::cout << ch - '0' << std::endl;
//
//    for (int i = 0; i < len; ++i) {
//        std::cout << "index[" << i << "] = " << s[i] << std::endl;
//    }
//
//    std::string words;
//    std::cout << "Enter text: ";
//
//    getline(std::cin, words);
//
//    //std::cout << words;
//    std::string sentence = s + " " + words;
//
//    std::cout << sentence << std::endl;
//
//    std::string firstWord = "Asen";
//    std::string secodWord = "Asenov";
//
//    if (firstWord > secodWord) {
//        std::cout << firstWord << " is after " << secodWord;
//    }
//    else if (firstWord == secodWord) {
//        std::cout << firstWord << " is equal to " << secodWord;
//    }
//    else {
//        std::cout << firstWord << " is before " << secodWord;
//    }
//
//    std::cout << std::endl;
//
//    if (firstWord.compare(secodWord) > 0) {
//        std::cout << "firstWord is after secondWord" << std::endl;
//    }
//
//    std::cout << firstWord.compare(secodWord) << std::endl;
//
//    std::string appentedWords = firstWord.append(secodWord);
//
//    std::cout << appentedWords << std::endl;
//
//    std::string result;
//
//    for (int i = 0; i < 100; ++i) {
//        // bad practice
//        //result += "a";
//
//        if (i % 20 == 0) {
//            result.append("\n");
//        }
//
//        result.append("a");
//    }
//
//    std::cout << result << std::endl;
//         
//    return 0;
//}


int main() {
    std::string str = "C++ $ Programming $ Course $";

    int index = str.find_first_of("++");
    std::cout << index << "\n";

    index = str.find_first_of("ourse");
    std::cout << index << std::endl;

    index = str.find("ourse");
    std::cout << index << std::endl;

    index = str.find_first_of("--");
    std::cout << index << std::endl;

    index = str.find_first_of("r", 9);
    std::cout << index << std::endl;

    index = str.find("$");

    std::cout << std::endl;

    while (index != std::string::npos) {
        std::cout << "index: " << index << std::endl;

        str.replace(index, 1, "@");
        
        index = str.find("$");
    }
    
    std::cout << str << std::endl;

    //str.find_last_of("atv", 3);

    return 0;
}


//int main() {
//
//
//    return 0;
//}
