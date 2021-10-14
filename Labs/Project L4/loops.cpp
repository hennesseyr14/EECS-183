/**
 * loops.cpp
 *
 * EECS 183
 * Lab 4: Loops exercises
 *
 * Ryan Hennessey
 * rjhenn
 *
 * Prints shapes made of asterisks
 */

#include "loops.h"
#include <iostream>

using namespace std;


void print_rectangle(int rows, int cols) {
    for (int r = 1; r <= rows; r++) {
        for (int c = 1; c <= cols; c++) {
            cout << "*";
        }
        cout << endl;
    }
    
}

void print_right(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
}

void print_right_justified(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > (n - i)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    
}

