#include <iostream>

//int main() {
//    int n;
//    char k;
//    std::cin >> n >> k;
//
//    char arr[100];
//    int foundIndex = -1;
//
//    for (int i = 0; i < n; ++i) {
//        std::cin >> arr[i];
//    }
//
//    for (int j = 0; j < n; ++j) {
//        if (arr[j] == k) {
//            foundIndex = i;
//            break;
//        }
//    }
//
//    std::cout << foundIndex << std::endl;
//
//    return 0;
//}


//int main() {
//    int n, k;
//    std::cin >> n >> k;
//
//    int arr[100];
//
//    int counter = 0;
//
//    for (int i = 0; i < n; ++i) {
//        std::cin >> arr[i];
//    }
//
//    for (int j = 0; j < n; ++j) {
//        if (arr[j] == k) {
//            counter++;
//        }
//    }
//
//    std::cout << counter << std::endl;
//
//    return 0;
//}


//int main() {
//	int n;
//	std::cin >> n;
//
//	int arr[100];
//	int maxEl;
//	int maxIndex = 0;
//
//	for (int i = 0; i < n; ++i) {
//		std::cin >> arr[i];
//	}
//
//	maxEl = arr[0];
//
//	for (int j = 1; j < n; ++j) {
//		if (arr[j] > maxEl) {
//			maxEl = arr[j];
//			maxIndex = j;
//		}
//	}
//
//	std::cout << "Element: " << maxEl << "\n" << "index: " << maxIndex << std::endl;
//
//
//	return 0;
//}


//int main() {
//	//int maxEl = 20;
//	int maxEl;
//
//	std::cout << maxEl;
//
//	return 0;
//}


//int main() {
//	int n;
//	std::cin >> n;
//
//	int arr[] = { -23, -23, -55, -12, -10 };
//	int maxEl;
//	int minEl;
//
//	/*for (int i = 0; i < n; ++i) {
//		std::cin >> arr[i];
//	}*/
//
//	maxEl = arr[0];
//	minEl = arr[0];
//
//	for (int j = 1; j < n; ++j) {
//		if (maxEl < arr[j]) {
//			maxEl = arr[j];
//		}
//
//		if (minEl > arr[j]) {
//			minEl = arr[j];
//		}
//	}
//
//	int size = sizeof(arr) / sizeof(arr[0]);
//	std::cout << size << std::endl;
//
//	std::cout << "min element: " << minEl << "\n";
//	std::cout << "max element: " << maxEl << std::endl;
//
//	return 0;
//}


//int main() {
//	int n;
//	std::cin >> n;
//
//	int arr[100];
//	int minIndex[100];
//	int minEl;
//	int z = 0;
//
//
//	for (int i = 0; i < n; ++i) {
//		std::cin >> arr[i];
//	}
//
//	minEl = arr[0];
//
//	for (int j = 0; j < n; ++j) {
//		if (minEl > arr[j]) {
//			minEl = arr[j];
//		}
//	}
//
//	for (int k = 0; k < n; ++k) {
//		if (minEl == arr[k]) {
//			minIndex[z] = k;
//			++z;
//		}
//	}
//
//	for (int x = 0; x < z; ++x) {
//		std::cout << minIndex[x] << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}


//int main() {
//	int n;
//	std::cin >> n;
//
//	int arr[100];
//
//	double average = 0.0;
//
//	for (int i = 0; i < n; ++i) {
//		std::cin >> arr[i];
//		average += arr[i];
//	}
//
//	average /= n;
//
//	std::cout << average << std::endl;
//
//	for (int j = 0; j < n; ++j) {
//		if (arr[j] > average) {
//			std::cout << arr[j] << " ";
//		}
//	}
//	std::cout << std::endl;	
//
//	return 0;
//}


int main() {
	int n, m;
	std::cout << "Enter pow: ";
	std::cin >> n;

	std::cout << "Enter number: ";
	std::cin >> m;

	bool find = false;

	int temp = 1;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			temp *= i;
		}

		if (temp > m) {
			std::cout << "The biggest number is " << i - 1 << std::endl;
			find = true;
			break;
		}

		temp = 1;
	}

	return 0;
}
