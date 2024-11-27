#include <iostream>
#include <iomanip>

#include "HospitalStay.h"
int main() {
    HospitalStay hs1("HS001", 5);
    HospitalStay hs2("HS002", 7);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << Equals(hs1, hs2) << std::endl;          // Output: false
    std::cout << "GreaterThan: " << GreaterThan(hs1, hs2) << std::endl; // Output: false
    std::cout << "LessThanEquals: " << LessThanEquals(hs1, hs2) << std::endl; // Output: true

    return 0;
}
