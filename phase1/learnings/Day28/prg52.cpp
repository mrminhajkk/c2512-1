#include<iostream>
#include<utility> //pair 
#include<tuple>   //tuple, get<>(tuple)
#include<string>
using namespace std;

pair<double,int> getSalaryFreq() {
    return {20000.0, 2};//make_pair<double,int>(20000.0, 2);
}

tuple<double, char, std::string> getMultiData() {
    return {1.0, 'P', "Name"};
}

int main() 
{
    //pair<double,int> p1 = make_pair<double,int>(20000.0, 2);
    //pair<double,int> p1 = getSalaryFreq();
    //cout << p1.first << " " << p1.second << endl;

    //auto [sal, freq] = p1;
    auto [sal, freq] = getSalaryFreq();
    cout << sal << " " << freq << endl;
    //tuple<double, char, std::string> t1 = {1.0, 'P', "Name"};
    //tuple<double, char, std::string> t1 = make_tuple<double, char, std::string>(1.0, 'P', "Name");
    //tuple<double, char, std::string> t1 = getMultiData();
    //cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;
    
    
    auto [num, ch, name] = getMultiData();
    cout << num << " " << ch << " " << name << endl; 
    return 0;
}