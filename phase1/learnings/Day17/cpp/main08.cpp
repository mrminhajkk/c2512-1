//Examples for static members and non-static members
//         ie class-level members and object-level members
#include <iostream>
#include <iomanip>
#include <string>
//
using std::cout;
using std::endl;
using std::string;
//"************"HospitalStay.h"************
class HospitalStay {
    private:
        string StayID;
        int NumberOfDays;
    public:
        //behaviours
        void print();
        //constructor
        HospitalStay(string p_StayID, int p_NumberOfDays); 
};
//"************"Main.cpp"************
int main() {
    HospitalStay hs1("HS001", 1); 

    hs1.print(); // Output: [StayID: HS001, NumberOfDays: 1]

    return 0;
}
//************"HospitalStay.cpp"************

//behaviours

void HospitalStay::print() {
    cout << "[StayID: " << this->StayID 
         << ", NumberOfDays: " << this->NumberOfDays 
         << "]" << endl;
}
//constructor
HospitalStay::HospitalStay(string StayID, int NumberOfDays) {
    this->StayID = StayID;
    this->NumberOfDays = NumberOfDays;
}
