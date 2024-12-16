//g++ prg11.cpp --std=c++20
#include <concepts>
#include <iostream>

// A function constrained by requires
template <typename T>
requires std::integral<T> // || std::floating_point<T> // Requires T to be an integral type
T square(T value) {
    return value * value;
}


/*

std::integral auto square1(std::integral auto value) {
    return value * value;
}
*/
int main() {
    std::cout << square(5) << '\n'; // Valid: int is integral
    //std::cout << square(3.5) << '\n'; // Error: double is not integral
}