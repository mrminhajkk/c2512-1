#include <execution>
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {5, 3, 8, 1, 2};

    std::sort(std::execution::par, vec.begin(), vec.end());

    for (auto x : vec) {
        std::cout << x << " ";  // Output: 1 2 3 5 8
    }
}