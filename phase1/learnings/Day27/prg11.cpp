//vector
#include<iostream>
#include<set>
using namespace std;

template <class T>
void print(T container, const char* caption) {
    cout << caption << ":";
    for(auto e : container) {
        cout << e << " ";
    }
    cout << endl;
}

int main() 
{
    set<double> salaries;
    salaries.insert(10000.0);
    salaries.insert(30000.0);
    salaries.insert(20000.0);
    salaries.insert(10000.0);      
    salaries.insert(20000.0);

    print<set<double>>(salaries, "Salaries");

    cout << "size:" << salaries.size() << endl;
    cout << "max_size:" << salaries.max_size() << endl;

    cout << endl;
    

    auto ITER =salaries.find(30000.0);    
    salaries.erase(ITER);
    print<set<double>>(salaries, "After remove 30000.0,\n\tSalaries");

    cout << endl;
    cout << "salaries(using iterator):";
    for( auto ITER = salaries.begin() ; ITER != salaries.end() ; ITER++ ) { 
        cout << *ITER << " ";
    }
    cout << endl;

    cout << endl ;
    cout << "salaries(using reverse iterator):";
    for( auto ITER = salaries.rbegin() ; ITER != salaries.rend() ; ITER++ ) { 
        cout << *ITER << " ";
    }
    cout << endl;

    salaries.clear();
    print<set<double>>(salaries, "After clear,\n\tSalaries");
    return 0;
}