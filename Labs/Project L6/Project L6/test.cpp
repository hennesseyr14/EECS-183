/**
 * test.cpp
 *
 * EECS 183
 * Lab 6: Classes and File I/O
 *
 * Ryan Hennessey
 * rjhenn
 *
 * <#Description#>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"

void test_point();

int main() {
    test_point();

    return 0;
}

void test_point() {
    // Test 1
    Point pt1;
    
    pt1.setX(15);
    
    cout << "pt1 is: " << pt1 << endl;
    cout << pt1.getX() << " " << endl;
    cout << pt1.getY() << " " << endl;

    ifstream input_file;
    input_file.open("data1.txt");
    pt1.read(input_file);
    cout << "pt1 is: " << pt1 << endl;

    // Test 2
    Point pt2;

    pt2.setY(15);
    cout << "pt2 is: " << pt2 << endl;

    pt2.read(input_file);
    cout << "pt2 is: " << pt2 << endl;
  
    // Test 3
    Point pt3;

    pt3.setY(105);
    pt3.setX(101);
    cout << "pt3 is: " << pt3 << endl;

    // Test 4
    Point pt4;

    pt4.setY(-5);
    pt4.setX(-7);
    cout << "pt4 is: " << pt4 << endl;

    // Test 5
    Point pt5(100,100);

    cout << "pt5 is: " << pt5 << endl;

    // Test 6
    Point pt6(-1, -1);

    cout << "pt6 is: " << pt6 << endl;

    // Test 7
    Point pt7(0, 0);

    cout << "pt7 is: " << pt7 << endl;

    // Test 8
    pt1.read(input_file);
    cout << "pt1 is: " << pt1 << endl;

    // Test 9
    pt1.read(input_file);
    cout << "pt1 is: " << pt1 << endl;

    // Test 10
    pt1.read(input_file);
    cout << "pt1 is: " << pt1 << endl;

    return;
}
