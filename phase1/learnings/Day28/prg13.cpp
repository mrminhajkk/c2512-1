//Function pointer as parameter to another function 
// what is Higher Order Function ?
//      Higher Order Function is a function that takes another function as a parameter or returns a function as a result.    
#include<iostream>
using namespace std;

double findSum(double first, double second) {
    return first + second;
}

double findDifference(double first, double second) {
    return first - second;
}


double calc(double first, double second, double (*operation) (double, double) ) {
    return operation(first, second);
}

int main() 
{
    /*
    // function pointer 
    double (*calc1) (double , double) = findSum;
    
    cout << calc1(2.0, 3.0) << endl; // call findSum via pointer 'calc1' to findSum
    
    calc1 = findDifference;
    cout << calc1(12.0, 3.0) << endl; // call findDifference via pointer 'calc1' to findDifference
    */
    
    cout << calc(2.0, 3.0, findSum) << endl;
    cout << calc(12.0, 3.0, findDifference) << endl;
    
    
    return 0;
}