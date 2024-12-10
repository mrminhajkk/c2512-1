#include<iostream>
#include<complex>
using namespace std;

template <class T>
T findAdd(T first, T second);

int main()
{
    cout << "(int)findAdd((char)5, (char)2) = " << (int)findAdd<char>((char)5, (char)2) << endl;
    cout << "findAdd((short)5, (short)2) = " << findAdd<short>((short)5, (short)2) << endl;
    cout << "findAdd(1, 2) = " << findAdd<int>(1, 2) << endl;
    cout << "findAdd(1L, 2L) = " << findAdd<long>(1L, 2L) << endl;

    cout << "findAdd(1LL, 2LL) = " << findAdd<long long>(1LL, 2LL) << endl;
    cout << "findAdd(1.0f, 2.0f) = " << findAdd<float>(1.0f, 2.0f) << endl;
    cout << "findAdd(1.0, 2.0) = " << findAdd<double>(1.0, 2.0) << endl;
    cout << "findAdd(1.0L, 2.0L) = " << findAdd<long double>(1.0L, 2.0L) << endl;
    
    cout << "findAdd(complex<int>(2,3), complex<int>(3,4)) = " << findAdd<complex<int>>(complex<int>(2,3), complex<int>(3,4)) << endl;
    return 0;
}

template <class T>
T findAdd(T first, T second) {
    T result = first + second;
    return result;
}