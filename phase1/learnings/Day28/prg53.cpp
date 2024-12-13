#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
// For given temperatures (in vector<float>),                   temperatures
// Sort temperatures in ascending order (use: set<float>)       sorted_temperatures
// Sort temperatures in descending order (use: stack<float>)    rsorted_temperatures
// Find frequence of occurences for each temperature (use: map<float,int>) frequency
// Sort temperatures by frequency (use: multimap<float,int>)    sorted_frequency
// Sort temperatures by frequency in descending order (use: stack<pair<int,float>>) rsorted_frequency

int main() 
{
    // For given temperatures (in vector<float>),                   temperatures
    vector<float> temperatures= {2, 4, 2, 3, 4, 2, 2, 4, 5, 1}; 
    cout << "input:"; 
    for(auto e: temperatures) { 
        cout << e << " ";  
    } 
    cout << endl;

    // Sort temperatures in ascending order (use: set<float>)       sorted_temperatures
    set<float> sorted_temperatures; 
    for(auto e: temperatures) { 
        sorted_temperatures.insert(e); 
    }  
    cout << "after sort no-duplicate:"; 
    for(auto e: sorted_temperatures) { 
        cout << e << " "; 
    }   
    cout << endl;  

    // Sort temperatures in descending order (use: stack<float>)    rsorted_temperatures 
    stack<float> rsorted_temperatures;    
    for(auto e: sorted_temperatures) { 
        rsorted_temperatures.push(e); 
    } 
    
    cout << "desc order:"; 
    while(!rsorted_temperatures.empty()) { 
        cout << rsorted_temperatures.top() << " "; 
        rsorted_temperatures.pop(); 
    } 
    cout << endl;
    // Find frequence of occurences for each temperature (use: map<float,int>) frequency
    map<float,int> frequency;
    for(auto e: temperatures) { frequency[e]++; }
    
    cout << "Temp : Freq:";
    for(auto [k,v] : frequency) {
        cout << k << ":" << v << ",";
    }
    cout << endl;
    
    // Sort temperatures by frequency (use: multimap<float,int>)    sorted_frequency
    multimap<float,int> sorted_frequency;
    for(auto [k,v] : frequency) {
        sorted_frequency.insert({v,k});
    }
    
    cout << "Freq : Temp (Sort by freq):";
    for(auto [k,v] : sorted_frequency) {
        cout << k << ":" << v << ",";
    }
    cout << endl;
    
    // Sort temperatures by frequency in descending order (use: stack<pair<int,float>>) rsorted_frequency
    stack<pair<int,float>> rsorted_frequency;
    for(auto [k,v] : sorted_frequency) {
        rsorted_frequency.push({k,v});
    }

    cout << "Freq : Temp (Sort by freq desc):";    
    while(!rsorted_frequency.empty())
    { 
        auto [k,v] = rsorted_frequency.top();
        cout << k << ":" << v << ", "; rsorted_frequency.pop(); 
    }
    cout << endl;
    
    return 0;
}