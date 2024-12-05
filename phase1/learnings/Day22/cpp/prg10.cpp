// to find sum of 3 fractions in the dynamic array of 3 fractions 
// and to find smallest of 3 fractions 
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
    Fraction* fractions = new Fraction[3] {Fraction(1, 2), Fraction(1, 4), Fraction(3, 4)}; //[1/2,1/4,3/4] sum()=6/4=3/2,min=1/4

    Fraction sum(0,1);
    for (int i = 0; i < 3; i++) {
        sum = sum + fractions[i];
    }

    cout << "sum of fractions is " << sum << "." << endl; // Expected output: 6/4 (in reduced form)

    Fraction min = fractions[0];
    for (int i = 1; i < 3; i++) {
        if (fractions[i] < min) {
            min = fractions[i];
        }
    }
    cout << "smallest fraction is " << min << "." << endl; // Expected output: 1/4

    delete[] fractions; fractions = nullptr;
    return 0;
}