#include <iostream>
#include <iomanip>
#include <string>
//
using std::string;

//"************"HospitalStay.h"************
class HospitalStay {
    private:
        string StayID;
        int NumberOfDays;
    public:
        //constructor
        HospitalStay(string p_StayID, int p_NumberOfDays);
        //friends
        friend class Comparisons;
};
//"************"Comparisons.h"************
class Comparisons {
    public:
        static bool LessThan(const HospitalStay& first, const HospitalStay& second);
};
//"************"Main.cpp"************
int main() {
    HospitalStay hs1("HS001", 5); HospitalStay hs2("HS002", 7);

    std::cout << std::boolalpha;
    std::cout << "LessThan: " << Comparisons::LessThan(hs1,hs2) << std::endl; // Output: true
    return 0;
}
//************"HospitalStay.cpp"************
//constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}
//"************"Comparisons.cpp"************
bool Comparisons::LessThan(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays < second.NumberOfDays);
}