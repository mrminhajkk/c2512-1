// array of doctors
// findSum, findMinInFirstHalf, findMaxInSecondHalf
#include <climits>

#include <iostream>

#include <string>
#include <vector>

#include "type.h"
#include "doctor.h"

years_t findSum(std::vector<Doctor>& doctors) {
    years_t sum = 0;
    for(auto doctor : doctors) {
        sum += doctor.getYearsOfExperience();
    }
    return sum;
}

years_t findMinInFirstHalf(std::vector<Doctor>& doctors) {
    years_t min = SHRT_MAX;
    int half = doctors.size() / 2;
    for(int I =0 ; I < half; I++) {
        if(doctors[I].getYearsOfExperience() < min) {
            min = doctors[I].getYearsOfExperience();
        }
    }
    return min;
}

years_t findMaxInSecondHalf(std::vector<Doctor>& doctors) {
    years_t max = SHRT_MIN;
    int half = doctors.size() / 2;
    for(int I =half ; I < doctors.size(); I++) {
        if(doctors[I].getYearsOfExperience() > max) {
            max = doctors[I].getYearsOfExperience();
        }
    }
    return max;
}

int main() {
    std::vector<Doctor> doctors {        
        Doctor("D001", 5),
        Doctor("D002", 4),
        Doctor("D003", 3),
        Doctor("D004", 2),
        Doctor("D005", 1)
    };

    years_t sum = findSum(doctors);
    years_t min = findMinInFirstHalf(doctors);
    years_t max = findMaxInSecondHalf(doctors);

    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Min = " << min << std::endl;
    std::cout << "Max = " << max << std::endl;

    return 0;
}