#include <ranges>
#include <vector>
#include <iostream>

int main() {
     std::vector<int> nums = {4, 5, 3, 6, 1, 2};

    // Filter even numbers and square them
    auto filtered_transformed = nums 
        | std::views::filter([](int x) { return x % 2 == 0; })
        | std::views::transform([](int x) { return x * x; });
    
    std::sort(nums.begin(), nums.end());

    // Print the results
    for (int x : filtered_transformed) {
        std::cout << x << " "; // Output: 4 16 36
    }
    return 0;
}

//auto nums_filtered = std::views::filter(nums, [](int x) { return x % 2 == 0; })