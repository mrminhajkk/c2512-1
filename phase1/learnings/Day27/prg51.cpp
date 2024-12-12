//vector
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() 
{
    vector<double> salaries;
    salaries.push_back(10000.0);
    salaries.push_back(30000.0);
    salaries.push_back(20000.0);
    salaries.push_back(10000.0);      
    salaries.push_back(20000.0);

    cout << "salaries:";
    for(auto e : salaries) {
        cout << e << " ";
    }
    cout << endl;

    map<double, int> freq;
    for(auto e : salaries) {
        if(freq.find(e) != freq.end()) {
            freq[e]++;
        } else {
            freq[e] = 1;
        }
    }

    cout << "freq:";
    for(auto [k,v] : freq) {
        cout << k << ":" << v << ", ";
    }
    cout << endl;

    cout << "freq:";
    for(auto p : freq) {
        cout << p.first << ":" << p.second << ", ";
    }
    cout << endl;


    return 0;
}