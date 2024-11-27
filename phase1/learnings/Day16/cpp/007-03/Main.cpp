#include <iostream>
#include <iomanip>

#include "HospitalStay.h"
int main() {
    HospitalStay hs1("HS001", 5);
    HospitalStay hs2("HS002", 7);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << StayComparison::Equals(hs1, hs2) << std::endl;          // Output: false
    std::cout << "GreaterThan: " << StayComparison::GreaterThan(hs1, hs2) << std::endl; // Output: false
    std::cout << "LessThanEquals: " << StayComparison::LessThanEquals(hs1, hs2) << std::endl; // Output: true

    return 0;
}
