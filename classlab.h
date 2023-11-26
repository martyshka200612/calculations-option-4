#pragma once
class properfraction {
private:
    int num;
    int den;

    int gcd(int i, int j);

    void simplify();

public:
    properfraction(int numerator, int denominator);
    properfraction(const properfraction& fraction);


    properfraction operator+ (const properfraction& fraction);

    properfraction operator* (const properfraction& fraction);

    properfraction operator/ (const properfraction& fraction);


    int getnumerator() {
        return num;
    }

    int getdenominator() {
        return den;
    }

    void print();
};