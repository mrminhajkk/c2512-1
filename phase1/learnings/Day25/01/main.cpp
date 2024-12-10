#include<iostream>
using namespace std;

char findAdd(char first, char second);
short findAdd(short first, short second);
int findAdd(int first, int second);
long findAdd(long first, long second);

long long findAdd(long long first, long long second);
float findAdd(float first, float second);
double findAdd(double first, double second);
long double findAdd(long double first, long double second);

int main()
{
    cout << "(int)findAdd((char)5, (char)2) = " << (int)findAdd((char)5, (char)2) << endl;
    cout << "findAdd((short)5, (short)2) = " << findAdd((short)5, (short)2) << endl;
    cout << "findAdd(1, 2) = " << findAdd(1, 2) << endl;
    cout << "findAdd(1L, 2L) = " << findAdd(1L, 2L) << endl;

    cout << "findAdd(1LL, 2LL) = " << findAdd(1LL, 2LL) << endl;
    cout << "findAdd(1.0f, 2.0f) = " << findAdd(1.0f, 2.0f) << endl;
    cout << "findAdd(1.0, 2.0) = " << findAdd(1.0, 2.0) << endl;
    cout << "findAdd(1.0L, 2.0L) = " << findAdd(1.0L, 2.0L) << endl;
    
    return 0;
}

char findAdd(char first, char second) {
    cout << "char findAdd(char first, char second)" << endl;
    return first + second;
}
short findAdd(short first, short second) {
    cout << "short findAdd(short first, short second)" << endl;
    return first + second;
}
int findAdd(int first, int second) {
    cout << "int findAdd(int first, int second)" << endl;
    return first + second;
}
long findAdd(long first, long second) {
    cout << "long findAdd(long first, long second)" << endl;
    return first + second;
}

long long findAdd(long long first, long long second) {
    cout << "long long findAdd(long long first, long long second)" << endl;
    return first + second;
}
float findAdd(float first, float second)  {
    cout << "float findAdd(float first, float second)" << endl;
    return first + second;
}
double findAdd(double first, double second)  {
    cout << "double findAdd(double first, double second)" << endl;
    return first + second;
}
long double findAdd(long double first, long double second)  {
    cout << "long double findAdd(long double first, long double second)" << endl;
    return first + second;
}