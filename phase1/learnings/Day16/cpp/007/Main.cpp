#include <iostream>
#include <iomanip>

#include "HospitalStay.h"
int main() {
    HospitalStay hs1("HS001", 5);
    HospitalStay hs2("HS002", 7);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << hs1.Equals(hs2) << std::endl;          // Output: false
    std::cout << "GreaterThan: " << hs1.GreaterThan(hs2) << std::endl; // Output: false
    std::cout << "LessThanEquals: " << hs1.LessThanEquals(hs2) << std::endl; // Output: true

    return 0;
}
