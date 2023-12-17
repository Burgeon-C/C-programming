
#include <iostream>
#include <iomanip>
using namespace std;
#include "RationalNumber.h"
#include "RationalNumber.cpp"


int main()
{
    // RationalNumber c( 1, 3 ), d( 2, 4 ), x;
    RationalNumber c, d, x;

    // test overloaded stream extraction operator
    cout << "Enter a Rational Number (n/d): ";
    cin >> c;
    cout << "Enter a Rational Number (n/d): ";
    cin >> d;

  //  x = c + d; // test overloaded operators + and =
    cout << c << " + " << d << " = " << x << endl;

//    x = c - d; // test overloaded operators - and =
    cout << c << " - " << d << " = " << x << endl;

//    x = c * d; // test overloaded operators * and =
    cout << c << " * " << d << " = " << x << endl;

//    x = c / d; // test overloaded operators / and =
    cout << c << " / " << d << " = " << x << endl;

    // test overloaded > operator
    cout << c << ( ( c > d ) ? " > " : " <= " ) << d
         << " according to the overloaded > operator\n";

    // test overloaded >= operator
    cout << c << ( ( c >= d ) ? " >= " : " < " ) << d
         << " according to the overloaded >= operator\n";

    // test overloaded < operator
    cout << c << ( ( c < d ) ? " < " : " >= " ) << d
         << " according to the overloaded < operator\n";

    // test overloaded <= operator
    cout << c << ( ( c <= d ) ? " <= " : " > " ) << d
         << " according to the overloaded <= operator\n";

    // test overloaded == operator
    cout << c << ( ( c == d ) ? " == " : " != " ) << d
         << " according to the overloaded == operator\n";

    // test overloaded != operator
    cout << c << ( ( c != d ) ? " != " : " == " ) << d
         << " according to the overloaded != operator\n";

    return 0;
} // end main