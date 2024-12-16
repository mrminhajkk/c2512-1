// Lambda Function as arg or return value in another function : HOF - higher order function 
#include<iostream>
#include<functional>
using namespace std;

double calc(double first, double second, function<double(double,double)> operation) {
    return operation(first, second);
}

int main() 
{
    auto findSum = [] (double first, double second) -> double {
        return first + second;
    };
    auto findDifference = [] (double first, double second) -> double {
        return first - second;
    };
    
    cout << calc(2.0, 3.0, findSum) << endl;
    cout << calc(12.0, 3.0, findDifference) << endl;
    cout << calc(14.0, 3.0, [] (double a, double b) -> double { return a / b; }) << endl;
    cout << calc(14.0, 3.0, [] (double a, double b) { return a / b; }) << endl;
    return 0;
}