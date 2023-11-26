#include "classlab.h"
#include <iostream>
#include <stdexcept>

using namespace std;
int main()
{
    int x, y;
    cout << " x: " << endl;
    cin >> x;
    cout << " y: " << endl;
    cin >> y;
    properfraction a(x, y);

    int v, z;
    cout << " v: " << endl;
    cin >> v;
    cout << " z: " << endl;
    cin >> z;
    properfraction b(v, z);

    cout << "fraction 1: ";
    a.print();
    cout << endl;

    cout << "fraction 2: ";
    b.print();
    cout << endl;

    properfraction sum = a + b;
    properfraction product = a * b;
    properfraction quotient = a / b;


    cout << "a + b = ";
    sum.print();
    cout << endl;

    cout << "a * b = ";
    product.print();
    cout << endl;

    cout << "a / b = ";
    quotient.print();
    cout << endl;

    return 0;
}