// For given temperatures (in vector<float>),                   temperatures
// Sort temperatures in ascending order (use: set<float>)       sorted_temperatures
// Sort temperatures in descending order (use: stack<float>)    rsorted_temperatures    
// Find frequence of occurences for each temperature (use: map<float,int>) frequency
// Sort temperatures by frequency (use: multimap<float,int>)    sorted_frequency
// Sort temperatures by frequency in descending order (use: stack<pair<int,float>>) rsorted_frequency

#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

int main() 
{
    vector<float> temperatures= {2, 4, 2, 3, 4, 2, 2, 4, 5, 1}; 
    set<float> sorted_temperatures;  
    stack<float> rsorted_temperatures;
    cout << "input:"; 
    for(auto e: temperatures) { 
        cout << e << " "; 
        sorted_temperatures.insert(e); 
    } 
    cout << endl;
    
    cout << "after sort no-duplicate:"; 
    for(auto e: sorted_temperatures) { 
        cout << e << " "; 
        rsorted_temperatures.push(e); 
    } 
    cout << endl;
    
    cout << "desc order:"; 
    while(!rsorted_temperatures.empty()) { 
        cout << rsorted_temperatures.top() << " "; 
        rsorted_temperatures.pop(); 
    } 
    cout << endl;
    
    map<float,int> frequency;
    for(auto e: temperatures) { frequency[e]++; }
    
    cout << "Temp its Freq:";
    for(auto [k,v] : frequency) {
        cout << k << ":" << v << ",";
    }
    cout << endl;
    
    multimap<float,int> sorted_frequency;
    for(auto [k,v] : frequency) {
        sorted_frequency.insert({v,k});
    }
    
    cout << "Temp its Freq (Sort by freq):";
    for(auto [k,v] : sorted_frequency) {
        cout << k << ":" << v << ",";
    }
    cout << endl;
    
    
    stack<pair<int,float>> rsorted_frequency;
    for(auto [k,v] : sorted_frequency) {
        rsorted_frequency.push({k,v});
    }
    cout << "Temp its Freq (Sort by freq desc):";
    
    while(!rsorted_frequency.empty())
    { 
        auto [k,v] = rsorted_frequency.top();
        cout << k << ":" << v << ", "; rsorted_frequency.pop(); 
    }
    cout << endl;
    
    return 0;
}