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
        static int count;

        string StayID;
        int NumberOfDays;
    public:
        static int getCount(); //declaration [forward declaration - deferring mem alloc]
        //behaviours
        void print();
        //constructor
        HospitalStay(string p_StayID, int p_NumberOfDays); 
};
//"************"Main.cpp"************
int main() {
    HospitalStay hs1("HS001", 1); 
    HospitalStay hs2("HS002", 2);
    HospitalStay hs3("HS003", 3);

    hs1.print(); // Output: [StayID: HS001, NumberOfDays: 1]
    hs2.print(); // Output: [StayID: HS002, NumberOfDays: 2]
    hs3.print(); // Output: [StayID: HS003, NumberOfDays: 3]
    cout << "Total HospitalStay objects created: " << HospitalStay::getCount() << endl; 
    // Output: Total HospitalStay objects created: 3
    
    return 0;
}
//************"HospitalStay.cpp"************
int HospitalStay::count = 0; // definition [mem allocated]
//behaviours
int HospitalStay::getCount()
{
    return count;
}
void HospitalStay::print() {
    cout << "[StayID: " << StayID 
         << ", NumberOfDays: " << NumberOfDays 
         << "]" << endl;
}
//constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;

    HospitalStay::count++;
}
