#include<iostream>
#include<complex>
using namespace std;

template <class T>
T findSum(T arr[], int size);
int main()
{
    //usage 
    int nums [4] = {2,3,5,6};
    int nums_sum = findSum<int>(nums, 4);

    //usage 
    float salaries [4] = {2.0f,3.0f,5.0f,6.0f};
    float salaries_sum = findSum<float>(salaries, 4);

    //usage 
    complex<int> cnums [4] = {complex<int>(2,3), complex<int>(3,4), 
                         complex<int>(5,6), complex<int>(6,7)};
    complex<int> cnums_sum = findSum<complex<int>>(cnums, 4);


    cout << "nums_sum = " << nums_sum << endl;
    cout << "salaries_sum = " << salaries_sum << endl;
    cout << "cnums_sum = " << cnums_sum << endl;

    return 0;
}
template <class T>
T findSum(T arr[], int size) {
    T result = {};
    for(int I = 0; I < size; I++) {
        result = result + arr[I];
    }
    return result;
}