#include<iostream>
#include<complex>
using namespace std;

template <class T, class U, class V>
V findAdd(T first, U second);

int main()
{
    
    cout << "findAdd(1, 2) = " << findAdd<int, int, int>(1, 2) << endl;

    cout << "findAdd(1.0f, 2.0) = " << findAdd<float, double, double>(1.0f, 2.0) << endl;
    
    cout << "findAdd(complex<int>(2,3), complex<int>(3,4)) = " << findAdd<complex<int>,complex<int>,complex<int>>(complex<int>(2,3), complex<int>(3,4)) << endl;
    return 0;
}

template <class T, class U, class V>
V findAdd(T first, U second) {
    V result = first + second;
    return result;
}