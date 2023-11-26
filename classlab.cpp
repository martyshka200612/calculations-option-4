#include <iostream>
#include <stdexcept>

#include "classlab.h"

using namespace std;
properfraction::properfraction(int numerator, int denominator) : num(numerator), den(denominator) {

     if (den == 0) {
        throw invalid_argument("Denominator can't be zero");
    }
    simplify();
}
void properfraction::simplify() {
    int gcd_2 = gcd(num, den);
    num /= gcd_2;
    den /= gcd_2;
    if ((num < 0 && den > 0) || (num > 0 && den < 0)) {
        num = -1 * abs(num);
        den = abs(den);
    }
    else {
        num = abs(num);
        den = abs(den);
    }
} //simplify properfraction

properfraction::properfraction(const properfraction& fraction) : num(fraction.num), den(fraction.den) {}



properfraction properfraction::operator+ (const properfraction& fraction) {
    int newnumerator = num * fraction.den + fraction.num * den;
    int newdenominator = den * fraction.den;
    properfraction result( newnumerator, newdenominator);
    result.simplify();
    return result;
}
properfraction properfraction::operator* (const properfraction& fraction) {
    int newnumerator = num * fraction.num;
    int newdenominator = den * fraction.den;
    properfraction result(newnumerator, newdenominator);
    result.simplify();
    return result;
}

properfraction properfraction::operator/ (const properfraction& fraction) {
    int newNumerator = num * fraction.den;
    int newDenominator = den * fraction.num;
    properfraction result(newNumerator, newDenominator);
    result.simplify();
    return result;
}
void properfraction::print() {
    cout << num << "/" << den;
}
int properfraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}