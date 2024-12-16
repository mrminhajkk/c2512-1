#include <iostream>
#include <vector>
#include <optional>

std::optional<int> findElement(const std::vector<int>& vec, int value) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) {
            return static_cast<int>(i); // Return index
        }
    }
    return std::nullopt; // No value found
}

void optionalExample() {
    std::vector<int> nums = {1, 2, 3, 4};
    auto result = findElement(nums, 3);

    if (result) {
        std::cout << "Found at index: " << *result << std::endl; // Output: Found at index: 2
    } else {
        std::cout << "Element not found." << std::endl;
    }
}

int main()
{
    optionalExample();
}