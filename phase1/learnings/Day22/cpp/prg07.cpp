// to find sum of two fractions and compare two fractions
#include <iostream>
#include <cstring>
using namespace std;

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction { //a/b , here a = numerator , b = denominator
    private:
        //attr 
        int numerator;
        int denominator;
    public:
        // constructor 
        Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) { }
        
        //operator
        friend ostream& operator<<(ostream& output, const Fraction& fraction);
        Fraction operator+(const Fraction& other) {
            //cout << "Inside member\n";
            Fraction third(0,1);
            third.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
            third.denominator = this->denominator * other.denominator;
            //
            int gcd = findGCD(third.numerator, third.denominator);
            third.numerator = third.numerator / gcd;
            third.denominator = third.denominator / gcd;
            //
            return third;
        }
        bool operator<(const Fraction& other) {
            return ((float)this->numerator / (float)this->denominator) < ((float)other.numerator / (float)other.denominator);
        }
};

ostream& operator<<(ostream& output, const Fraction& fraction) { //non member op <<
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}

int main() {    
    Fraction f1(1, 2); // Represents 1/2
    Fraction f2(2, 3); // Represents 2/3
    Fraction result = f1 + f2; 
    cout << "sum of " << f1 << " and " << f2 << " is " << result << "." << endl; // Expected output: 7/6 (in reduced form)

    cout << f1 << " < " << f2 << " is " << (f1 < f2) << endl; // Expected output: 1
    return 0;
}