#include <iostream>
#include <list>

int main() {
    std::list<int> sequence;
    int sum = 0;
    double average = 0;

    int num = 0;
    std::cout << "Enter a number or 0 for end. ";
    std::cin >> num;
    
    while (num != 0) {
        sequence.push_back(num);

        std::cout << "Enter a number or 0 for end. ";
        std::cin >> num;
    }

    size_t size = sequence.size();

    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
        sum += *it;

        *it = 2222;
    }
    std::cout << std::endl;

    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    /*for (int elem : sequence) {
        sum += elem;
    }*/

    /*for (size_t i = 0; i < size; ++i) {
        sum += sequence.front();
        sequence.pop_front();
    }*/

    std::cout << sum << std::endl;
    std::cout << sum * 1.0 / sequence.size() << std::endl;

    //average = (sum * 1.0) / size;    
    //std::cout << average << std::endl;

    return 0;
}
