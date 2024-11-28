//Examples for constructors and destructors
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
        HospitalStay(); //no arg constructor
        HospitalStay(string p_StayID, int p_NumberOfDays); //args constructor
        HospitalStay(const HospitalStay& hs); //copy constructor
        HospitalStay(HospitalStay&& hs); //move constructor
        //destructor
        ~HospitalStay();
};
//"************"Main.cpp"************
int main() {
    HospitalStay hs1("HS001", 1); 
    HospitalStay hs2; // how to call no arg constructor // IMPORTANT
    HospitalStay hs3("HS003", 3);
    HospitalStay hs4(hs3);
    HospitalStay hs5("HS005", 5);
    HospitalStay hs6(std::move(hs5)); //move semantics 


    hs1.print(); // Output: [StayID: HS001, NumberOfDays: 1]
    hs2.print(); // Output: [StayID: , NumberOfDays: 0]
    hs3.print(); // Output: [StayID: HS003, NumberOfDays: 3]
    hs4.print(); // Output: [StayID: HS003, NumberOfDays: 3]
    hs5.print(); // Output: [StayID: , NumberOfDays: 0]
    hs6.print(); // Output: [StayID: HS005, NumberOfDays: 5]
    return 0;
}
//************"HospitalStay.cpp"************
//behaviours
void HospitalStay::print() {
    cout << "[StayID: " << StayID 
         << ", NumberOfDays: " << NumberOfDays 
         << "]" << endl;
}
//constructor
HospitalStay::HospitalStay() {
    StayID = "";
    NumberOfDays = 0;
    cout << "[No Args Constructor]Constructed of StayID=" << StayID << endl;
}

HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
    cout << "[Args Constructor]Constructed of StayID=" << StayID << endl;
}

HospitalStay::HospitalStay(const HospitalStay& other) {
    StayID = other.StayID;
    NumberOfDays = other.NumberOfDays;
    cout << "[Copy Constructor]Constructed of StayID=" << StayID << endl;
}

HospitalStay::HospitalStay(HospitalStay&& other) {
    StayID = other.StayID;
    NumberOfDays = other.NumberOfDays;
    other.StayID = "";
    other.NumberOfDays = 0;
    cout << "[Move Constructor]Constructed of StayID=" << StayID << endl;
}

HospitalStay::~HospitalStay() {
    cout << "[Destructor]Destroying of StayID=" << StayID << endl;
}