//ptr to dynamic blocks ie dynamic array 
#include <iostream>
using namespace std;

int main() {
    int* ids = new int[4] {101, 102, 110, 112}; 

    cout << "\n\nusing ptr arithmetic\n";
    cout << "value ids[0]=" << *(ids+0) << endl;
    cout << "value ids[1]=" << *(ids+1) << endl;
    cout << "value ids[2]=" << *(ids+2) << endl;
    cout << "value ids[3]=" << *(ids+3) << endl;


    cout << "\n\nusing subscripted operator\n";
    cout << "value ids[0]=" << ids[0] << endl;
    cout << "value ids[1]=" << ids[1] << endl;
    cout << "value ids[2]=" << ids[2] << endl;
    cout << "value ids[3]=" << ids[3] << endl;

    cout << "\n\nusing loop\n";
    for(int I = 0; I < 4; I++) {
        cout << "value ids[" << I << "]=" << ids[I] << endl;
    }

   

    cout << "\n\naddr of dynamic array\n";
    cout << "ids=" << ids << endl;
    cout << "addr ids[0]=" << &ids[0] << endl;
    cout << "addr ids[1]=" << &ids[1] << endl;
    cout << "addr ids[2]=" << &ids[2] << endl;
    cout << "addr ids[3]=" << &ids[3] << endl;

    delete[] ids;
    ids = nullptr;
    return 0;
}