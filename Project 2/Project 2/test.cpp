/**
 * test.cpp
 *
 * Ryan Hennessey
 * rjhenn
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************

bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you 
// to recieve full points when submitting test.cpp
//************************************************************************

static void test_isLeapYear() {
    cout << "Begin testing isLeapYear() " << endl;

    cout << isLeapYear(2000) << " correct value is: 1" << endl;
    cout << isLeapYear(1900) << " correct value is: 0" << endl;
    cout << isLeapYear(1996) << " correct value is: 1" << endl;
    cout << isLeapYear(1995) << " correct value is: 0" << endl;

    cout << "End testing isLeapYear() " << endl << endl;
}

void test_isGregorianDate() {
    cout << "Begin testing isGregorianDate() " << endl;

    cout << isGregorianDate(8, 19, 2016) << " correct value is: 1" << endl;
    cout << isGregorianDate(3, 12, 1234) << " correct value is: 0" << endl;
    cout << isGregorianDate(9, 13, 1752) << " correct value is: 0" << endl;
    cout << isGregorianDate(9, 14, 1752) << " correct value is: 1" << endl;
    cout << isGregorianDate(10, 13, 1752) << " correct value is: 1" << endl;
    cout << isGregorianDate(10, 14, 1752) << " correct value is: 1" << endl;
    cout << isGregorianDate(9, 13, 1753) << " correct value is: 1" << endl;
    cout << isGregorianDate(9, 14, 1753) << " correct value is: 1" << endl;
    cout << isGregorianDate(9, 13, 1750) << " correct value is: 0" << endl;
    cout << isGregorianDate(9, 14, 1750) << " correct value is: 0" << endl;
    cout << isGregorianDate(10, 13, 1750) << " correct value is: 0" << endl;
    cout << isGregorianDate(10, 14, 1750) << " correct value is: 0" << endl;
    cout << isGregorianDate(10, 13, 1753) << " correct value is: 1" << endl;
    cout << isGregorianDate(10, 14, 1753) << " correct value is: 1" << endl;
    cout << isGregorianDate(8, 13, 1752) << " correct value is: 0" << endl;
    cout << isGregorianDate(8, 14, 1752) << " correct value is: 0" << endl;
    cout << isGregorianDate(8, 13, 1754) << " correct value is: 1" << endl;
    cout << isGregorianDate(8, 14, 1754) << " correct value is: 1" << endl;
    cout << isGregorianDate(11, 1, 1995) << " correct value is: 1" << endl;


    cout << "End testing isGregorianDate() " << endl << endl;
}
   
static void test_isValidDate() {
    cout << "Begin testing isValidDate() " << endl;

    cout << isValidDate(8, 19, 2016) << " correct value is: 1" << endl;
    cout << isValidDate(13, 12, 1994) << " correct value is: 0" << endl;
    cout << isValidDate(9, 13, 1750) << " correct value is: 0" << endl;
    cout << isValidDate(9, 14, 1752) << " correct value is: 1" << endl;
    cout << isValidDate(0, 13, 1776) << " correct value is: 0" << endl;
    cout << isValidDate(9, 31, 2004) << " correct value is: 0" << endl;
    cout << isValidDate(4, 31, 2004) << " correct value is: 0" << endl;
    cout << isValidDate(11, 31, 2004) << " correct value is: 0" << endl;
    cout << isValidDate(6, 31, 2004) << " correct value is: 0" << endl;
    cout << isValidDate(8, 32, 2004) << " correct value is: 0" << endl;
    cout << isValidDate(2, 29, 2004) << " correct value is: 1" << endl;
    cout << isValidDate(2, 29, 2003) << " correct value is: 0" << endl;
    cout << isValidDate(1, 31, 2005) << " correct value is: 1" << endl;
    cout << isValidDate(1, 0, 2005) << " correct value is: 0" << endl;
    cout << isValidDate(0, 1, 2015) << " correct value is: 0" << endl;
    cout << isValidDate(1, 1, 1005) << " correct value is: 0" << endl;

    cout << "End testing isValidDate() " << endl << endl;
}

static void test_determineDay() {
    cout << "Begin testing determineDay() " << endl;

    cout << determineDay(10, 6, 2017) << " correct value is: 6" << endl;
    cout << determineDay(11, 1, 1995) << " correct value is: 4" << endl;
    cout << determineDay(1, 29, 2064) << " correct value is: 3" << endl;
    cout << determineDay(2, 5, 2017) << " correct value is: 1" << endl;

    cout << "End testing determineDay() " << endl << endl;
}


int main(int argc, char *argv[]) {
    test_isLeapYear();
    test_isGregorianDate();
    test_isValidDate();
    test_determineDay();
}

