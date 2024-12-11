#include <iostream>
#include <vector>    // For vector 
#include <algorithm>
using namespace std;

template<class T>
void print(vector<T>& temperatures, const string& caption)
{
    cout << caption << endl << "\t"; 
    for_each(temperatures.begin(), temperatures.end(), [](T temperature){cout << temperature << " ";}); 
    cout << endl;
}

int main()
{
    vector<float> temperatures1 {88.0f, 79.0f, 90.0f, 93.0f, 83.0f};
    vector<float> temperatures2 {88.0f, 79.0f, 90.0f, 93.0f, 83.0f};
    vector<float> temperatures3 {88.0f, 79.0f, 90.0f, 93.0f, 83.0f};

    //temperatures1 copy to temperatures11 via copy constructor
    vector<float> temperatures11(temperatures1);
    //temperatures1 copy to temperatures21 via copy assignment operator 
    vector<float> temperatures21;
    temperatures21 = temperatures1; //copy assignment operator
    //temperatures2 move to temperatures32 via move constructor 
    vector<float> temperatures32(move(temperatures2));
    

    print(temperatures1, "Temperatures1(copied twice to 11 & 21 copy consr copy =):");
    print(temperatures2, "Temperatures2(moved to 32 via move cons):");
    print(temperatures3, "Temperatures3(moved to 43 via move =):");
    print(temperatures11, "Temperatures11(copied from 1 via copy consr):");
    print(temperatures21, "Temperatures21(copied from 1) via copy=:");
    print(temperatures32, "Temperatures32(moved from 2 via move consr):");
    //temperatures3 move to temperatures43 via move assignment operator 
    vector<float> temperatures43;
    temperatures43 = move(temperatures3);//move assignment operator
    /*
    if(( temperatures43 = move(temperatures3) ).begin() != temperatures43.end()){
        cout << "as source temperatures3 is not empty.\nwe moved temperatures3 to temperatures43." << endl;
    }
    */
    print(temperatures43, "Temperatures43(moved from 3) via move=:");
    return 0;
}

/*
    vector( const vector& other ); //copy constructor
    vector( vector&& other );       //move constructor
    vector& operator=( const vector& other ); //copy assignment operator
    vector& operator=( vector&& other );    //move assignment operator

    // discussion
    temperatures43 = move(temperatures3); //temperatures43.operator=(move(temperatures3));
*/