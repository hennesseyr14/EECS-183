/**
 * test.cpp
 *
 * EECS 183
 * Lab 4: loops exercises
 *
 * Ryan Hennessey
 * rjhenn
 *
 * Test suite for functions
 */

#include "loops.h"

#include <iostream>
using namespace std;

void test_print_rectangle();
void test_print_right();
void test_print_right_justified();

int main() {
    
    test_print_rectangle();
    test_print_right();
    test_print_right_justified();

    return 0;
}

void test_print_rectangle() {
    cout << "Testing print_rectangle()" << endl;
    print_rectangle(8, 8);
    print_rectangle(2, 3);
    print_rectangle(5, 4);
    print_rectangle(1, 1);
}

void test_print_right() {
    cout << "Testing print_right()" << endl;
    print_right(1);
    print_right(3);
    print_right(4);
    print_right(7);
}

void test_print_right_justified() {
    cout << "Testing print_right_justified()" << endl;
    print_right_justified(1);
    print_right_justified(3);
    print_right_justified(4);
    print_right_justified(9);
}




