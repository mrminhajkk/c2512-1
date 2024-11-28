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
        //friends   syntax: friend <non_member_fn_declaration>;
        friend bool LessThan(const HospitalStay& first, const HospitalStay& second);
};
//"************"Comparisons.h"************
bool LessThan(const HospitalStay& first, const HospitalStay& second);
//"************"Main.cpp"************
int main() {
    HospitalStay hs1("HS001", 5); HospitalStay hs2("HS002", 7);

    std::cout << std::boolalpha;
    std::cout << "LessThan: " << LessThan(hs1, hs2) << std::endl; // Output: true
    return 0;
}
//************"HospitalStay.cpp"************
//constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}
//"************"Comparisons.cpp"************
bool LessThan(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays < second.NumberOfDays);
}
