#include <iostream>

#include "Account.h"

int main() {
    Account firstAccount(500);
    Account secondAccount(400);

    //firstAccount.debit(100);
    //std::cout << firstAccount.getBalance() << std::endl;
    //firstAccount.credit(300);
    std::cout << firstAccount.getBalance() << std::endl;

    secondAccount.debit(400);
    std::cout << secondAccount.getBalance() << std::endl;

    return 0;
}
