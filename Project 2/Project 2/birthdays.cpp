/**
 * birthdays.cpp
 *
 * Ryan Hennessey
 * rjhenn
 *
 * EECS 183: Project 2
 *
 * Application that identifies the day of the week on which the user was born
 * or prints the next 10 leap years.
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


/**
 * Requires: nothing
 * Modifies: cout
 * Effects: prints out the initial heading for the program
 */
void printHeading();


/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  prints out the final greeting for the program
 */
void printCloser();


/**
 * Requires: nothing
 * Modifies: cout 
 * Effects: prints the menu
 */
void printMenu();


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  prints the menu
 *           reads the input from the user
 *           checks to make sure the input is within range for the menu
 *           If not prints "Invalid menu choice"
 *           continues to print the menu and read an input until a valid one is
 *               entered
 *           returns the users choice of menu options

 */
int getMenuChoice();


/**
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects: returns 'true' if the date is in the limits
 *          of the Gregorian calendar otherwise returns 'false'
 */
bool isGregorianDate(int month, int day, int year);


/**
 * Requires: year is a Gregorian year
 * Modifies: nothing
 * Effects: Returns 'true' if the year is a leap year
 *          otherwise returns 'false'
 */
bool isLeapYear(int year);


/**
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects:  Returns 'true' if the date is valid
 *           otherwise returns 'false'
 *           see the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);


/**
 * Requires: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * Modifies: nothing
 * Effects:  Returns the value that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);


/**
 * Requires: day (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * Modifies: cout
 * Effects:  prints the day you were born on
 *           Sunday, Monday, ..., Saturday
 */
void printDayOfBirth(int day);


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Asks for the Month/day/year of their birth
 *           If the date is valid, it will print the day
 *               of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt
 */
void determineDayOfBirth();


/**
 * Base Project
 * Requires: nothing
 * Modifies: cout
 * Effects: prints "Under Construction"
 *
 * S'more version of this function
 * Requires: nothing
 * Modifies: cout, cin 
 * Effects:  reads the month and day of birthday
 *           loops through 10 years printing the day of the week
 *               the birthday falls on
 *           If the month/day is not valid, it prints nothing
 */
void print10Birthdays();


/**
 * Requires: nothing
 * Modifies: cin, cout
 * Effects:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();


/*int main() {

    printHeading();

    int menuChoice = 0;

    // Prompt user for menu choice, repeating until user decides to finish
    while (menuChoice != 4) {
        menuChoice = getMenuChoice();

        // Execute function based on user's menu choice
        switch (menuChoice) {
        case 1:
            // Determine day of week of a birthday
            determineDayOfBirth();
            break;

        case 2:
            // Produce the next 10 leap years
            print10LeapYears();
            break;

        case 3:
            // Unfinished part of application
            print10Birthdays();
            break;

        case 4:
            // Message for user when they finish
            printCloser();
        }
    }
    
    return 0;
}*/


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
}


void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Determine birthdays for the next 10 years" << endl;
    cout << "4) Finished" << endl << endl;
    
    cout << "Choice --> ";
}

int getMenuChoice() { 
    int menuChoice;
    printMenu();

    // Get user menu choice
    cin >> menuChoice;

    // Check whether menu choice is valid, re-prompt user if necessary
    while (menuChoice < 1 || menuChoice > 4) {
        cout << endl << "Invalid menu choice" << endl;
        printMenu();
        cin >> menuChoice;
    }

    return menuChoice;
}

bool isGregorianDate(int month, int day, int year) {
    // Last date before Gregian Calendar
    const int GREGORIAN_MONTH = 9;
    const int GREGORIAN_DAY = 13;
    const int GREGORIAN_YEAR = 1752;

    // Check whether date is after September 13, 1752
    // Check validity of year first
    if (year > GREGORIAN_YEAR) {
        return true;
    // Check day and month if year is 1752
    } else if (year == GREGORIAN_YEAR) {
        if (month > GREGORIAN_MONTH) {
            return true;
        } else if (month == GREGORIAN_MONTH) {
            if (day > GREGORIAN_DAY) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool isLeapYear(int year) {
    // Check leap year rules
    // Check if year is divisible by 4
    if (year % 4 == 0) {
        // Check if divisible by 100
        if (year % 100 == 0) {
            // Check if divisible by 400
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}


bool isValidDate(int month, int day, int year) {
    // Check whether date is Gregorian
    if (!isGregorianDate(month, day, year)) {
        return false;
    }

    // Make sure month is valid
    if (month < 1 || month > 12) {
        return false;
    }

    // Make sure day in month is valid
    if (day > 31 || day < 1) {
        return false;
    }

    // Check day for months with only thirty days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30)) {
        return false;
    }

    // Check day for February for leap years and non-leap years
    if (month == 2) {
        if (isLeapYear(year) && day > 29) {
            return false;
        }
        if (!isLeapYear(year) && day > 28) {
            return false;
        }
    }

    return true;
}


int determineDay(int month, int day, int year) {
    // Modify month/year for dates in January/February to fit formula
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }

    // Calculate century, moify year to fit formula
    int century = year / 100;
    year %= 100;

    // Zeller's rule to get number for day of the week
    int f = (int)(day + floor(13.0 * (month + 1.0) / 5.0) + year
            + floor(year / 4.0) + floor(century / 4.0) + 5.0 * century) % 7;

    return f;
}


void printDayOfBirth(int day) {
    // convert number into day of the week based on value from Zeller's rule
    switch (day) {
        case 0:
            cout << "Saturday";
            break;

        case 1:
            cout << "Sunday";
            break;

        case 2:
            cout << "Monday";
            break;

        case 3:
            cout << "Tuesday";
            break;

        case 4:
            cout << "Wednesday";
            break;

        case 5:
            cout << "Thursday";
            break;

        case 6:
            cout << "Friday";
            break;
    }
    
    return;
}


void determineDayOfBirth() {
    int month;
    int day;
    int year;
    char slash;
    int dayOfWeek;

    // Prompt user for date of birth
    cout << endl << "Enter your date of birth" << endl;
    cout << "format: month / day / year  --> ";
    cin >> month >> slash >> day >> slash >> year;
    
    // Verify that date meets necessary requirements
    if (!isValidDate(month, day, year)) {
        cout << endl << "Invalid date" << endl;
    } else {
        // Tell user what day of the week they were born on
        dayOfWeek = determineDay(month, day, year);
        cout << endl << "You were born on a: ";
        printDayOfBirth(dayOfWeek);
        cout << endl << endl << "Have a great birthday!!!" << endl;
    }
    return;
}

void print10Birthdays() {
    // Unfinished part of application
    cout << "Under Construction" << endl << endl;
    return;
}

void print10LeapYears() {
    int year;

    // Prompt user for year
    cout << endl << "Enter year  --> ";
    cin >> year;

    // Print nothing if year is not Gregorian
    if (year < 1752) {
        return;
    }

    // Create counter for number of leap years found
    int counter = 0;

    // Iterate through years after the one given,
    // checking whether each is a leap year
    while (counter < 10) {
        year++;
        if (isLeapYear(year)) {
            cout << "Leap year is " << year << endl;
            counter++;
        }
    }
    
    return;
}
