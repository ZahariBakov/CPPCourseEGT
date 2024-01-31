#include <iostream>

//int main() {
//    int n;
//    int sum = 0;
//    std::cin >> n;
//
//    int arr2D[100][100];
//
//    int maxEl = arr2D[n - 1][0];
//
//    for (int row = 0; row < n; ++row) {
//        for (int col = 0; col < n; ++col) {
//            std::cin >> arr2D[i][j];
//        }
//    }
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (i == j) {
//                sum += arr2D[i][j];
//            }
//
//            if (j > i) {
//                if (maxEl < arr2D[i][j]) {
//                    maxEl = arr2D[i][j];
//                }
//            }
//        }
//    }
//
//    std::cout << sum << std::endl;
//    std::cout << maxEl << std::endl;
//
//    return 0;
//}


//int main() {
//    int n, m;
//    std::cin >> n >> m;
//
//    int arr[100][100];
//
//    int sum = 0;
//    int maxSum = arr[0][0] + arr[0][1] + arr[1][0] + arr[1][1];
//
//    for (int row = 0; row < m; ++row) {
//        for (int col = 0; col < n; ++col) {
//            std::cin >> arr[row][col];
//        }
//    }
//
//    for (int i = 0; i < m - 1; ++i) {
//        for (int k = 0; k < n; ++k) {
//            sum += arr[i][k];
//            sum += arr[i][k+1];
//            sum += arr[i+1][k];
//            sum += arr[i+1][k+1];
//
//            if (sum > maxSum) {
//                maxSum = sum; 
//            }
//
//            sum = 0;
//            std::cout << sum << std::endl;
//        }    
//    }
//
//    std::cout << maxSum << std::endl;
//
//    return 0;
//}


//int main() {
//	int jan1; // 0, 1, 2, 3, 4, 5, 6
//	bool visokosna; //  0, 1
//	int months[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//
//	std::cin >> jan1 >> visokosna;
//
//	int tekushtParvi = jan1;
//
//	int monthSize[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	monthSize[1] += visokosna;
//
//	for (int i = 0; i < 12; ++i) {
//		if ((tekushtParvi + 12) % 7 == 4) {
//			months[i]++;
//		}
//
//		tekushtParvi = (tekushtParvi + monthSize[i]) % 7;
//	}
//
//	for (int i = 0; i < 12; ++i) {
//		std::cout << months[i] << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}


int main() {
	int firstHouseNum, housesNum;
	std::cin >> firstHouseNum >> housesNum;
	
	int currHouse = 0;
	int numbers[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int currNum = 0;

	for (int i = firstHouseNum; currHouse++ < housesNum; i += 2) {
		currNum = i;

		std::cout << currNum << " ";
		while (currNum > 0) {
			numbers[currNum % 10]++;
			currNum /= 10;
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << numbers[i] << " ";
	}

	std::cout << std::endl;
	// input
	// 5, 5
	
	// output
	// numers for house
	//  5, 7, 9, 11, 13
	// using numbers
	// 0 3 0 1 0 1 0 1 0 1


	return 0;
}
