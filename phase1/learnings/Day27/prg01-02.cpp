//Read N salaries using vector and print them on console. Note: use for-each loop and c-like for loop
#include<iostream>
#include<vector>
using namespace std;

int main() {
   int N;
   cout << "Enter number of salareis:"; cin >> N;
   vector<double> salaries;
   cout << "Enter salaries one by one:" << endl;
   
   for(int I = 0; I < N; I++) {
       double sal;
       cout << "Salary at " << I << ":"; cin >> sal;
       salaries.push_back(sal);
   }
   
   cout << "Salaries are:";
   for(auto s : salaries) {
       cout << s << " ";
   } 
   cout << endl;
   
   cout << "Salaries are:";
   for(int I = 0; I < N; I++) {
       cout << salaries[I] << " ";
   } 
   cout << endl;
   
    return 0;
}