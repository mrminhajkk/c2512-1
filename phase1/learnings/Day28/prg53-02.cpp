#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
// 1 For given temperatures (in vector<float>),                   temperatures
void printTemperatures(vector<float> &temperatures);

// 2 Sort temperatures in ascending order (use: set<float>)       sorted_temperatures
set<float> sortTemperatures(vector<float> &temperatures);
//--PrintSortedTemperatures
void printSortedTemperatures(set<float> &sorted_temperatures);

// 3 Sort temperatures in descending order (use: stack<float>)    rsorted_temperatures
stack<float> sortTemperaturesDesc(set<float> &sorted_temperatures);
//--PrintSortedTemperaturesDesc
void printSortedTemperaturesDesc(stack<float> &rsorted_temperatures);

// 4 Find frequence of occurences for each temperature (use: map<float,int>) frequency
map<float,int> findFrequency(vector<float> &temperatures);
//--PrintFrequency
void printFrequency(map<float,int> &frequencies);

// 5 Sort temperatures by frequency (use: multimap<int,float>)    sorted_frequency
multimap<int,float> sortFrequency(map<float,int> &frequencies);
//--PrintSortedFrequency
void printSortedFrequency(multimap<int,float> &sorted_frequencies);

// 6 Sort temperatures by frequency in descending order (use: stack<pair<int,float>>) rsorted_frequency
stack<pair<int,float>> sortFrequencyDesc(multimap<int,float> &sorted_frequencies);
//--PrintSortedFrequencyDesc
void printSortedFrequencyDesc(stack<pair<int,float>> &rsorted_frequencies);


int main() 
{
    // 1  temperatures
    vector<float> temperatures= {2, 4, 2, 3, 4, 2, 2, 4, 5, 1}; 
    printTemperatures(temperatures);
    
    // 2 sorted_temperatures
    set<float> sorted_temperatures = sortTemperatures(temperatures);
    printSortedTemperatures(sorted_temperatures);

    // 3 rsorted_temperatures
    stack<float> rsorted_temperatures = sortTemperaturesDesc(sorted_temperatures);
    printSortedTemperaturesDesc(rsorted_temperatures);

    // 4 frequency
    map<float,int> frequencies = findFrequency(temperatures);
    printFrequency(frequencies);

    // 5 sorted_frequency
    multimap<int,float> sorted_frequencies = sortFrequency(frequencies);
    printSortedFrequency(sorted_frequencies);

    // 6 rsorted_frequency
    stack<pair<int,float>> rsorted_frequencies = sortFrequencyDesc(sorted_frequencies);
    printSortedFrequencyDesc(rsorted_frequencies);
        
    return 0;
}

// 1  temperatures
void printTemperatures(vector<float> &temperatures) {
    cout << "temperatures:"; 
    for(auto e: temperatures) { 
        cout << e << " ";  
    } 
    cout << endl;
}
// 2 sorted_temperatures
set<float> sortTemperatures(vector<float> &temperatures) {
    set<float> sorted_temperatures; 
    for(auto e: temperatures) { 
        sorted_temperatures.insert(e); 
    }  
    return sorted_temperatures;
}
//
void printSortedTemperatures(set<float> &sorted_temperatures) {
    cout << "Sorted temperatures:"; 
    for(auto e: sorted_temperatures) { 
        cout << e << " "; 
    }   
    cout << endl;  
}
// 3 rsorted_temperatures
stack<float> sortTemperaturesDesc(set<float> &sorted_temperatures) {
    stack<float> rsorted_temperatures;    
    for(auto e: sorted_temperatures) { 
        rsorted_temperatures.push(e); 
    } 
    return rsorted_temperatures;
}
//--PrintSortedTemperaturesDesc
void printSortedTemperaturesDesc(stack<float> &rsorted_temperatures) {
    cout << "Sorted temperatures in descending:";
    while(!rsorted_temperatures.empty()) { 
        cout << rsorted_temperatures.top() << " "; 
        rsorted_temperatures.pop(); 
    } 
    cout << endl;
}    
// 4 frequency
map<float,int> findFrequency(vector<float> &temperatures) {
    map<float,int> frequency;
    for(auto temp: temperatures) { frequency[temp]++; }
    return frequency;
}
//
void printFrequency(map<float,int> &frequencies) {
    cout << "Temp : Freq:";
    for(auto [temp, freq] : frequencies) {
        cout << temp << " degree:" << freq << " times,"; 
    }
    cout << endl;
}

// 5 sorted_frequency
multimap<int,float> sortFrequency(map<float,int> &frequencies) {
    multimap<int,float> sorted_frequencies;
    for(auto [temp, freq] : frequencies) {
        sorted_frequencies.insert({freq,temp});
    }
    return sorted_frequencies;
}
//
void printSortedFrequency(multimap<int,float> &sorted_frequencies) {
    cout << "Freq : Temp (Sort by freq):";
    for(auto [freq, temp] : sorted_frequencies) {
        cout << freq << " times:" << temp << " degree,"; 
    }
    cout << endl;
}

// 6 rsorted_frequency
stack<pair<int,float>> sortFrequencyDesc(multimap<int,float> &sorted_frequencies) {
    stack<pair<int,float>> rsorted_frequencies;
    for(auto [freq, temp] : sorted_frequencies) {
        rsorted_frequencies.push({freq,temp});
    }
    return rsorted_frequencies;
}
//--PrintSortedFrequencyDesc
void printSortedFrequencyDesc(stack<pair<int,float>> &rsorted_frequencies) {
    cout << "Freq : Temp (Sort by freq desc):";    
    while(!rsorted_frequencies.empty())
    { 
        auto [freq, temp] = rsorted_frequencies.top();
        cout << freq << " times:" << temp << " degree, "; 
        
        rsorted_frequencies.pop(); 
    }
    cout << endl;
}