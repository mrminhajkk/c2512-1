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
        HospitalStay();
        HospitalStay(string p_StayID, int p_NumberOfDays); 
};
//"************"Main.cpp"************
int main() {
    HospitalStay hs1("HS001", 1); 
    HospitalStay hs2; 

    hs1.print(); // Output: [StayID: HS001, NumberOfDays: 1]
    hs2.print(); // Output: [StayID: , NumberOfDays: 0]
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
HospitalStay::HospitalStay(string StayID, int NumberOfDays) : StayID {StayID}, NumberOfDays {NumberOfDays}   {
    cout << "Inside arg constr of " << this->StayID << endl;
}

HospitalStay::HospitalStay() : HospitalStay("",0) {
    cout << "Inside no arg constr of " << this->StayID << endl;
}
