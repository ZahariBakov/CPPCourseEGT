#include <iostream>
#include <map>
#include <set>

int main() {
    std::map<int, int> counters;
    int size = 15;
    int arr[15] = { 12, 12, 4, 4, 4, 8, 1, 4, 4, 4, 4, 4, 9, 8, 8 };
    //int arr[15] = { 12, 12, 4, 1, 1, 1, 1, 3, 4, 4, 4, 4, 9, 8, 8 };

    std::set<int> mySet;
    mySet.insert(arr, arr + 15);

    for (int elem : mySet) {
        //std::cout << elem << " ";
        //counters.insert({ elem, 0 });
        counters[elem] = 0;
    }

    /*std::cout << std::endl;
    for (std::pair<int, int> el : counters) {
        std::cout << el.first << " " << el.second << std::endl;
    }*/

    int currCount = 0;
    for (int i = 0; i < size - 1; ++i) {
        currCount++;

        if (arr[i] != arr[i + 1]) {
            if (counters[arr[i]] < currCount) {
                counters[arr[i]] = currCount;
            }

            currCount = 0;
        }
    }
    int key;
    int value = 0;

    for (std::pair<int, int> el : counters) {
        //std::cout << el.first << " " << el.second << std::endl;
        if (value < el.second) {
            key = el.first;
            value = el.second;
        }
    }

    std::cout << "Longest sub sequence is with lenght: " << value << " for num: " << key << std::endl;

    return 0;
}
