#include <iostream>
#include <vector>

std::vector<int> createVectorFromInout(int num) {
	std::vector<int> vec;
	int currNum;

	for (int i = 0; i < num; ++i) {
		std::cout << "Enter a number: ";
		std::cin >> currNum;
		vec.push_back(currNum);
	}
	std::cout << std::endl;

	return vec;
}

void printResultFromVector(std::vector<int> vec) {
	size_t size = vec.size();
	std::string result;

	for (size_t i = 0; i < size; ++i) {
		result = (vec[i] % 2 == 0 ? "even" : "odd");

		std::cout << "Number: " << vec[i] << " is " << result << std::endl;
	}
}

int main() {

	int numbers;
	std::cout << "How many numbers do you want to check? ";
	std::cin >> numbers;

	std::vector<int> numbersVec = createVectorFromInout(numbers);
	printResultFromVector(numbersVec);

	return 0;
}
