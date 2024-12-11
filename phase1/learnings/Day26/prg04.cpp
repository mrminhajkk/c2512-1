// Fraction having short member data 
// Fraction having int member data 
// Fraction having long member data 
// Fraction having long long member data 
#include<iostream>
using namespace std;

class Fraction { 
    private:
        short numerator;
        short denominator;
    public:
        Fraction(short numerator, short denominator);
        Fraction();
        ~Fraction();
        friend ostream& operator<<(ostream& output, const Fraction& fraction);
};

ostream& operator<<(ostream& output, const Fraction& fraction) { //non member op <<
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}

int main() {
    Fraction f1((short)1, (short)2); // Represents 1/2
    cout << f1 << endl;
    return 0;
}

Fraction::Fraction(short numerator, short denominator) : numerator(numerator), denominator(denominator) 
{

}
Fraction::Fraction() : numerator(0), denominator(1) 
{

}
Fraction::~Fraction() 
{

}