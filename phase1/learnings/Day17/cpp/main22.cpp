//dynamic memory to single data
#include <iostream>
#include <iomanip>
#include <string>
//
using std::cout;
using std::endl;
using std::string;
//"************"Main.cpp"************
int main() {
    string* ptr_StayID = new string {""};
    int* ptr_NumberOfDays = new int {0};

    cout << "Address of StayID: " << ptr_StayID << endl;
    cout << "Address of NumberOfDays: " << ptr_NumberOfDays << endl;

    cout << "StayID: " << *ptr_StayID << endl;
    cout << "NumberOfDays: " << *ptr_NumberOfDays << endl;

    *ptr_StayID = "HS001";
    *ptr_NumberOfDays = 1;
    
    cout << "StayID: " << *ptr_StayID << endl;
    cout << "NumberOfDays: " << *ptr_NumberOfDays << endl;

    delete ptr_StayID;
    delete ptr_NumberOfDays;

    return 0;
}

/*
The pointers
ptr_StayID holds addr of StayID
ptr_NumberOfDays holds addr of NumberOfDays

Now, you can use pointers ptr_StayID and ptr_NumberOfDays
to read or write from or into StayID and NumberOfDays respectively
using *ptr_StayID and *ptr_NumberOfDays.
Here * is called 'dereference' operator.
And & is called 'address-of' operator.

 */