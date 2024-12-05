// to find sum of two fractions [as dynamic blocks] and compare two fractions
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
    Fraction* pf1 = new Fraction(1, 2); // Represents 1/2
    Fraction* pf2 = new Fraction(2, 3); // Represents 2/3
    Fraction result = (*pf1) + (*pf2); 
    cout << "sum of " << *pf1 << " and " << *pf2 << " is " << result << "." << endl; // Expected output: 7/6 (in reduced form)

    cout << *pf1 << " < " << *pf2 << " is " << ((*pf1) < (*pf2)) << endl; // Expected output: 1

    delete pf1; pf1 = nullptr;
    delete pf2; pf2 = nullptr;
    return 0;
}