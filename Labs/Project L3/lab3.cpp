/**
 * lab3.cpp
 *
 * Ryan Hennessey
 * rjhenn
 *
 * EECS 183: Lab 3
 *
 * <#description#>
 */

#include <iostream>
using namespace std;

/**
 * Note: You will not implement this function as part of the lab
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects: returns 'true' if the date is in the limits
 *          of the Gregorian calendar otherwise returns 'false'
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note: You will not implement this function as part of the lab
 *
 * Requires: year is a Gregorian year
 * Modifies: nothing
 * Effects: Returns 'true' if the year is a leap year
 *          otherwise returns 'false'
 */
bool isLeapYear(int year);

void test_isGregorianDate();
void test_isLeapYear();

int main() {

    test_isGregorianDate();
    test_isLeapYear();
    
    return 0;
}


void test_isGregorianDate() {
    cout << "Testing -- isGregorianDate()" << endl;
    
    cout << isGregorianDate(8, 19, 2016) << " correct value is: 1" << endl;
    cout << isGregorianDate(3, 12, 1234) << " correct value is: 0" << endl;
    cout << isGregorianDate(9, 13, 1752) << " correct value is: 0" << endl;
    cout << isGregorianDate(9, 14, 1752) << " correct value is: 1" << endl;

    cout << "Finished testing -- isGregorianDate()" << endl << endl;

}


void test_isLeapYear() {
    cout << "Testing -- isLeapYear()" << endl;
    
    cout << isLeapYear(2015) << " correct value is: 0" << endl;
    cout << isLeapYear(2016) << " correct value is: 1" << endl;
    cout << isLeapYear(1900) << " correct value is: 0" << endl;
    cout << isLeapYear(2000) << " correct value is: 1" << endl;

    cout << "Finished testing -- isLeapYear()" << endl;

}

// DO NOT ALTER THE CODE BELOW THIS LINE IN ANY WAY
// WRITE YOUR CODE IN THE FUNCTIONS ABOVE

#if defined(DEBUG) || defined(_DEBUG)
bool isGregorianDate(int month, int day, int year) {
    
    // this (incorrect) implementation returns false to avoid compile error
    // you DO NOT need to implement this function as part of the lab
    return false;
}


bool isLeapYear(int year) {
    
    // this (incorrect) implementation returns false to avoid compile error
    // you DO NOT need to implement this function as part of the lab
    return false;
}
#endif
