#include <iostream>

//void printHello() {
//    std::cout << "Hello world!" << std::endl;
//}
//
//int sumTwoNumbers(int a, int b) {
//    int result;
//
//    result = a + b;
//
//    return result;
//}
//
//void printLine(int start, int end) {
//    for (int i = start; i <= end; ++i) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//}
//
//void printTriangle(int start, int end) {
//    for (int line = start; line <= end; ++line) {
//        printLine(start, line);
//    }
//
//    for (int line = end - 1; line > 0; --line) {
//        printLine(start, line);
//    }
//}
//
//int main() {
//    printHello();
//
//    int a = 10;
//
//    std::cout << sumTwoNumbers(5, 10) << std::endl;
//    std::cout << a + sumTwoNumbers(5, 10) << std::endl;
//
//    int num;
//    std::cout << "Enter num: " << std::endl;
//    std::cin >> num;
//
//    printTriangle(1, num);
//    /*for (int line = 1; line <= num; ++line) {
//        printLine(1, line);
//    }
//
//    for (int line = num - 1; line > 0; --line) {
//        printLine(1, line);
//    }*/
//
//    return 0;
//}

//int getMax(int a, int b) {
//    if (a > b) {
//        return a;
//    }
//
//    return b;
//}

//int getMax(int a, int b, int c) {
//    int maxNum = a;
//
//    if (b > maxNum) {
//        maxNum = b;
//    }
//
//    if (c > maxNum) {
//        maxNum = c;
//    }
//
//    return maxNum;
//}


//int main() {
//    int a, b, c;
//    std::cin >> a >> b >> c;
//
//    std::cout << "max(" << a << ", " << b << "): " << getMax(a, b) << std::endl;
//    std::cout << "max(" << a << ", " << b << ", " << c << "): " << getMax(a, b, c) << std::endl;
//
//    return 0;
//}

//float findX(float a, float b) {
//    return (-b / a);
//}
//
//int main() {
//    // a * x + b = 0
//    float a, b;
//    std::cin >> a >> b;
//
//    std::cout << findX(a, b) << std::endl;
//
//    return 0;
//}

//void printLastDigit(int number) {
//	int n = number % 10;
//
//	switch (n) {
//	case 1:
//		std::cout << "one" << std::endl;
//		break;
//	case 2:
//		std::cout << "two" << std::endl;
//		break;
//	case 3:
//		std::cout << "three" << std::endl;
//		break;
//	case 4:
//		std::cout << "four" << std::endl;
//		break;
//	case 5:
//		std::cout << "five" << std::endl;
//		break;
//	case 6:
//		std::cout << "six" << std::endl;
//		break;
//	case 7:
//		std::cout << "seven" << std::endl;
//		break;
//	case 8:
//		std::cout << "eight" << std::endl;
//		break;
//	case 9:
//		std::cout << "nine" << std::endl;
//		break;
//	case 0:
//		std::cout << "zero" << std::endl;
//		break;
//	default:
//		std::cout << "error" << std::endl;
//		break;
//	}
//}
//
//int main() {
//	int a;
//	std::cout << "Enter number: " << std::endl;
//	std::cin >> a;
//
//	printLastDigit(a);
//
//    return 0;
//}

//int findNumberOfIntervals(int arr[], int size) {
//    int count = 1;
//
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] - arr[i - 1] > 1) {
//            count++;
//        }
//    }
//
//    return count;
//}
//
//
//int main() {
//    //{ 1, 2, 3, 5, 6, 7, 8, 10 }
//    //3
//
//    int arr[] = { 3, 4, 6, 7, 8, 9, 11, 22, 33 };
//    int size = 9;
//
//    std::cout << findNumberOfIntervals(arr, size);
//
//    return 0;
//}


int main() {
    int arr[100];
    int size;

    std::cout << "Enter size " << std::endl;
    std::cin >> size;

    std::cout << "Enter array numbers: " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int temp;

    for (int j = 0; j < size - 1; ++j) {
        for (int k = 1; k < size; ++k) {
            if (arr[k] < arr[k - 1]) {
                temp = arr[k];
                arr[k] = arr[k - 1];
                arr[k - 1] = temp;
            }
        }
    }

    for (int x = 0; x < size; ++x) {
        std::cout << arr[x] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// 4 2 5 3 1 