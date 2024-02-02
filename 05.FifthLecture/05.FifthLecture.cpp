#include <iostream>

//int main() {
//    int counter = 0;
//
//    while (true) {
//        counter++;
//
//        if (counter == 5) {
//            continue;
//        }
//
//        if (counter == 10) {
//            break;
//        }
//
//        std::cout << counter << std::endl;
//    }
//    std::cout << std::endl;
//
//    int i = 11;
//
//    do {
//        std::cout << i << std::endl;
//        i++;
//    } while (i <= 10);
//
//    return 0;
//}

//int main() {
//    /*int arraySize;
//    std::cout << "Enter array size: " << std::endl;
//    std::cin >> arraySize;
//
//    int temperature[arraySize];*/
//
//    //for (int i = 1; i <= 9; ++i) {
//    //    std::cout << "Enter temperature " << std::endl;
//    //    std::cin >> temperature[i];
//    //}
//
//    /*int temperature[10];
//
//    for (int i = 0; i < 10; ++i) {
//        std::cout << "Enter temperature " << std::endl;
//        std::cin >> temperature[i];
//    }
//
//    int sum = 0;
//
//    for (int x = 0; x < 10; ++x) {
//        sum += temperature[x];
//    }
//
//    double average = sum / double(10);
//
//    std::cout << "Sum " << sum << std::endl;
//    std::cout << "Average " << average << std::endl;
//
//    std::cout << std::endl;*/
//
//    
//    return 0;
//}


int main() {
    int temperature[30] = { 12, 23, 12, -4 , 7, -2, 8, 12, 11, 23,
                            9, -2 ,12 , 8, -9, 12, 7, 2, 8, 12,
                            23, 11, 17, 15, 16, -8,  -9, -7, -7, 11 };

    int arraySize = std::size(temperature);

    int count = 0;

    for (int i = 0; i < arraySize; ++i) {
        if (temperature[i] >= 0) {
            ++count;;
        }

        if (temperature[i] == 11) {
            temperature[i] = 150;
        }
    }

    /*for (auto& idx : temperature) {
        if (idx == 11) {
            idx = 150;
        }
    }*/

    for (auto idx : temperature) {
        if (idx == 11) {
            idx = 150;        
        }

        std::cout << idx << std::endl;
    }

    for (auto elem : temperature) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;
    std::cout << "Positive temps " << count << std::endl;

    return 0;
}

//int main() {
//    std::cout << sizeof(int) << std::endl;
//    std::cout << sizeof(float) << std::endl;
//    std::cout << sizeof(double) << std::endl;
//    std::cout << sizeof(bool) << std::endl;
//    std::cout << sizeof(char) << std::endl;
//
//    return 0;
//}


//int main() {
//
//
//    return 0;
//}
