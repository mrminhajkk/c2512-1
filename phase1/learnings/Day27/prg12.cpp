//vector
#include<iostream>
#include<map>
using namespace std;

template <class T>
void print(T container, const char* caption) {
    cout << caption << ":";
    for(auto [k,v] : container) {
        cout << k << ":" << v << ", ";
    }
    cout << endl;
}

int main() 
{
    map<double,int> salaries;
    salaries[10000.0] = 1;    
    salaries[30000.0] = 1;    
    salaries[20000.0] = 1;
    salaries[10000.0] = 2;
    salaries[20000.0] = 2;

    print<map<double,int>>(salaries, "Salaries");

    cout << "size:" << salaries.size() << endl;
    cout << "max_size:" << salaries.max_size() << endl;

    cout << endl;
    

    auto ITER =salaries.find(30000.0);    
    salaries.erase(ITER);
    print<map<double,int>>(salaries, "After remove 30000.0,\n\tSalaries");

    cout << endl;
    cout << "salaries(using iterator):";
    for( auto ITER = salaries.begin() ; ITER != salaries.end() ; ITER++ ) { 
        auto [k,v] = *ITER;
        cout << k << " " << v << ", ";
    }
    cout << endl;

    cout << endl ;
    cout << "salaries(using reverse iterator):";
    for( auto ITER = salaries.rbegin() ; ITER != salaries.rend() ; ITER++ ) { 
        auto [k,v] = *ITER;
        cout << k << " " << v << ", ";
    }
    cout << endl;

    salaries.clear();
    print<map<double,int>>(salaries, "After clear,\n\tSalaries");
    return 0;
}