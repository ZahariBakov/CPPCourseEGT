#include <iostream>

double calculateTax(int& time) {
    double totalPay = 2.0;

    if (time > 3) {
        int currTime = time - 3;
        totalPay += (currTime * 0.5);
    }

    if (totalPay > 10.00) {
        totalPay = 10.00;
    }

    return totalPay;
}

int timeToParking(int& time) {
    std::cout << "Enter parking hour : ";
    std::cin >> time;

    return time;
}

int main() {
    int time;
    int clientsNumber;
    std::cout << "Enter number of clients: \n";
    std::cin >> clientsNumber;

    for (int i = 1; i <= clientsNumber; ++i) {
        std::cout << "Client number " << i << " ";
        timeToParking(time);

        std::cout << " need to pay " << calculateTax(time) << std::endl;
    }

    /*std::cout << "First client: \n";
    timeToParking(time);
    std::cout << calculateTax(time) << std::endl;

    std::cout << "Second client: \n";
    timeToParking(time);
    std::cout << calculateTax(time) << std::endl;

    std::cout << "Third client: \n";
    timeToParking(time);
    std::cout << calculateTax(time) << std::endl;*/    

    return 0;
}
