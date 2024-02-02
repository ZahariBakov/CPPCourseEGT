#include <iostream>

void findSeat(int seats[]) {
    for (int i = 0; i < 10; ++i) {
        int currSeat;
        std::cout << "Witch seat you want? ";
        std::cin >> currSeat;

        if (seats[currSeat - 1] == 0) {
            seats[currSeat - 1] = 1;
            std::cout << "Your seat is " << currSeat << std::endl;
        }
        else {
            for (int j = 0; j < 10; ++j) {
                if (seats[j] == 0) {
                    seats[j] = 1;
                    std::cout << "Your seat is " << j + 1 << std::endl;
                    break;
                }
            }
        }
    }
}

void printSeats(int seats[]) {
    for (int i = 0; i < 10; ++i) {
        std::cout << seats[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int seats[10] {};

    findSeat(seats);

    printSeats(seats);

    return 0;
}
