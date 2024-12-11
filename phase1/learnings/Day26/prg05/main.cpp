#include<iostream>
using namespace std;

template<class T>
class Fraction { 
    private:
        T numerator;
        T denominator;
    public:
        ~Fraction();
        Fraction(T numerator, T denominator);
        Fraction();
        Fraction(const Fraction<T>& other);
        Fraction(Fraction<T>&& other);       
        Fraction<T>& operator=(const Fraction<T>& other);
        Fraction<T>& operator=(Fraction<T>&& other);
        template<class U>
        friend ostream& operator<<(ostream& output, const Fraction<U>& fraction);
};

template<class U>
ostream& operator<<(ostream& output, const Fraction<U>& fraction) { //non member op <<
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}

int main() {
    Fraction<short> f1((short)1, (short)2); // Represents 1/2
    cout << f1 << endl;

    Fraction<int> f2(1, 2); // Represents 1/2
    cout << f2 << endl;

    Fraction<long> f3(1L, 2L); // Represents 1/2
    cout << f3 << endl;

    Fraction<long long> f4(1LL, 2LL); // Represents 1/2
    cout << f4 << endl;


    Fraction<short> f21(f1);//Fraction<short> f21=f1;//copy consr 
    cout << "copy consr" << endl;
    cout << "f1=" << f1 << endl;
    cout << "f21=" << f21 << endl;

    Fraction<short> f31(2,3); 
    Fraction<short> f32(move(f31)); //Fraction<short> f32 = move(f31);//move consr
    cout << "move consr" << endl;
    cout << "f31=" << f31 << endl;
    cout << "f32=" << f32 << endl;

    Fraction<short> f41;
    f41 = f1; 
    cout << "copy =" << endl;
    cout << "f1=" << f1 << endl;
    cout << "f41=" << f41 << endl;

    Fraction<short> f51(5,6); 
    Fraction<short> f52;
    f52 = move(f51); 
    cout << "move =" << endl;
    cout << "f51=" << f51 << endl;
    cout << "f52=" << f52 << endl;
    return 0;
}

template<class T>
Fraction<T>::Fraction(T numerator, T denominator) : numerator(numerator), denominator(denominator) 
{

}

template<class T>
Fraction<T>::Fraction() : Fraction<T>(0,1)
{

}

template<class T>
Fraction<T>::~Fraction() 
{

}

template<class T>
Fraction<T>::Fraction(const Fraction<T>& other): Fraction<T>(other.numerator, other.denominator) { 
    cout << "inside copy consr" << endl;
}

template<class T>
Fraction<T>::Fraction(Fraction<T>&& other) : Fraction<T>(other.numerator, other.denominator) { 
    cout << "inside move consr" << endl;
    other.numerator = 0;
    other.denominator = 1;
}

template<class T>  
Fraction<T>& Fraction<T>::operator=(const Fraction<T>& other) {
    cout << "inside copy =" << endl;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    return *this;
}

template<class T>  
Fraction<T>& Fraction<T>::operator=(Fraction<T>&& other) { 
    cout << "inside move =" << endl;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    other.numerator = 0;
    other.denominator = 1;
    return *this;
}