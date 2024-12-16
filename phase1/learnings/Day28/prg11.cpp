//Say Hi to Lambda Functions
#include<iostream>
using namespace std;
/*
double findSum(double first, double second) {
    return first + second;
}
*/
/*
auto findSum(double first, double second) -> double {
    return first + second;
} */
int main() 
{
    auto findSum = [] (double first, double second) -> double {
        return first + second;
    };
    cout << findSum(2.0, 3.0) << endl;
        
    return 0;
}