#include <iostream>

int main() {
    int intMatrix[3][3] = { {65, 66, 67}, {68, 69, 70}, {71, 72, 73} };

    // Convert int to char
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int num = intMatrix[i][j];
            char c = static_cast<char>(num);
            std::cout << num << " <-> " << c << std::endl;
        }
    }

    return 0;
}