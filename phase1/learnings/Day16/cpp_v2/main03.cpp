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
        friend bool LessThan(const HospitalStay& first, const HospitalStay& second);
};
//"************"HospitalStayComparisons.h"************
bool LessThan(const HospitalStay& first, const HospitalStay& second);
//"************"Medication.h"************
class Medication {
    private:
        string MedicationID;
        double DosagePerDay;
    public:
        //constructor
        Medication(string p_MedicationID, double p_DosagePerDay);
        //friends
        friend bool LessThan(const Medication& first, const Medication& second);
};
//"************"MedicationComparisons.h"************
bool LessThan(const Medication& first, const Medication& second);
//"************"Main.cpp"************
int main() {
    HospitalStay hs1("HS001", 5); HospitalStay hs2("HS002", 7);
    Medication m1("M001", 100.0); Medication m2("M002", 150.0);
    std::cout << std::boolalpha;
    std::cout << "HospitalStay LessThan: " << LessThan(hs1, hs2) << std::endl; // Output: true
    std::cout << "Medication LessThan: " << LessThan(m1, m2) << std::endl; // Output: true
    return 0;
}
//************"HospitalStay.cpp"************
//constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}
//************"Medication.cpp"************
//constructor
Medication::Medication(string p_MedicationID, double p_DosagePerDay) {
    MedicationID = p_MedicationID;
    DosagePerDay = p_DosagePerDay;
}
//"************"HospitalStayComparisons.cpp"************
bool LessThan(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays < second.NumberOfDays);
}
//"************"MedicationComparisons.cpp"************
bool LessThan(const Medication& first, const Medication& second) {
    return (first.DosagePerDay < second.DosagePerDay);
}
