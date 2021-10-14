/**
* test.cpp
*
* EECS 183, Fall 2017
* Project 4: CoolPics
*
* Ryan Hennessey
* rjhenn
*
* Test suite for classes.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Point.h"
#include "Color.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

void test_point(ifstream& input_file, ofstream& output_file);
void test_color(ifstream& input_file, ofstream& output_file);
void test_graphics(ifstream& input_file, ofstream& output_file);
void test_line(ifstream& input_file, ofstream& output_file);
void test_circle(ifstream& input_file, ofstream& output_file);
void test_triangle(ifstream& input_file, ofstream& output_file);
void test_rectangle(ifstream& input_file, ofstream& output_file);

int main()
{
    ifstream input_file;
    input_file.open("data1.txt");
    ofstream output_file;
    output_file.open("data2.txt");
    test_point(input_file, output_file);
    test_color(input_file, output_file);
    test_graphics(input_file, output_file);
    test_line(input_file, output_file);
    test_circle(input_file, output_file);
    test_triangle(input_file, output_file);
    test_rectangle(input_file, output_file);

    return 0;
}

void test_point(ifstream& input_file, ofstream& output_file)
{

    cout << "POINT TESTING" << endl << endl;

    // Test 1
    Point pt1;

    pt1.setX(15);

    cout << "pt1 is: " << pt1 << endl;
    cout << pt1.getX() << " " << endl;
    cout << pt1.getY() << " " << endl;

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
    Point pt5(100, 100);

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

    // Test 11
    pt1.write(output_file);
    output_file << endl << endl;

    cout << endl << endl << endl;

    return;
}


void test_color(ifstream& input_file, ofstream& output_file)
{
    
    cout << "COLOR TESTING" << endl << endl;
    
    Color c1;
    cout << c1 << endl;

    c1.setRed(15);
    c1.setGreen(20);
    c1.setBlue(25);
    cout << c1 << endl;
    cout << c1.getRed() << " ";
    cout << c1.getGreen() << " ";
    cout << c1.getBlue() << endl;

    c1.setRed(-1);
    c1.setGreen(-1);
    c1.setBlue(-1);
    cout << c1 << endl;

    c1.setRed(256);
    c1.setGreen(256);
    c1.setBlue(256);
    cout << c1 << endl;

    c1.setRed(0);
    c1.setGreen(0);
    c1.setBlue(0);
    cout << c1 << endl;

    c1.setRed(255);
    c1.setGreen(255);
    c1.setBlue(255);
    cout << c1 << endl;

    c1.read(input_file);
    cout << "c1: " << c1 << endl;

    c1.write(output_file);
    output_file << endl << endl;

    c1.read(input_file);
    cout << "c1: " << c1 << endl;

    c1.read(input_file);
    cout << "c1: " << c1 << endl;

    Color c2(100, 150, 200);
    cout << c2 << endl;

    Color c3(-100, -150, -200);
    cout << c3 << endl;

    Color c4(300, 300, 300);
    cout << c4 << endl;

    cout << endl << endl << endl;

    return;
}

void test_graphics(ifstream& input_file, ofstream& output_file)
{
    
    cout << "GRAPHICS TESTING" << endl << endl;

    Graphics g1;
    g1.writeFile("GTest1.bmp");

    Color c1(255, 0, 0);
    g1.setPixel(50, 50, c1);
    g1.writeFile("GTest2.bmp");

    g1.clear();
    g1.writeFile("GTest3.bmp");

    g1.setPixel(100, 100, c1);
    g1.setPixel(-1, -1, c1);
    g1.writeFile("GTest4.bmp");

    g1.setPixel(99, 99, c1);
    g1.setPixel(0, 0, c1);
    g1.writeFile("GTest5.bmp");

    cout << endl << endl << endl;

    return;
}

void test_line(ifstream& input_file, ofstream& output_file)
{
    cout << "LINE TESTING" << endl << endl;
    
    Line l1;

    Point p1(25, 25);
    Point p2(75, 75);
    Color c1(200, 200, 200);
    Line l2(p1, p2, c1);
    cout << l2 << endl;

    Color c2(0, 255, 0);
    l1.setStart(p2);
    l1.setEnd(p1);
    l1.setColor(c2);
    cout << l1.getStart() << " " 
         << l1.getEnd() << " " << l1.getColor() << endl;

    Line l3;
    l3.read(input_file);
    cout << l3 << endl;

    l3.write(output_file);
    output_file << endl << endl;

    cout << endl << endl << endl;

    // more test cases
    // may need to test draw
    // perhaps change tests for default constructor

    return;
}

void test_circle(ifstream& input_file, ofstream& output_file)
{
    cout << "CIRCLE TESTING" << endl << endl;

    Circle C1;
    
    Point p1(50, 50);
    int r1 = 20;
    Color c1(0, 0, 255);
    C1.setCenter(p1);
    C1.setRadius(r1);
    C1.setColor(c1);
    cout << C1.getCenter() << " " << C1.getRadius()
         << " " << C1.getColor() << endl;
    cout << C1 << endl;

    C1.setRadius(-20);
    cout << C1.getRadius();

    C1.setRadius(0);
    cout << C1.getRadius();

    C1.setRadius(-1);
    cout << C1.getRadius();

    Circle C2(p1, 10, c1);
    cout << C2 << endl;

    Circle C3(p1, -25, c1);
    cout << C3 << endl;

    Circle C4(p1, -1, c1);
    cout << C4 << endl;

    Circle C5(p1, 0, c1);

    C1.read(input_file);
    cout << C1 << endl;

    C1.write(output_file);
    output_file << endl << endl;

    cout << endl << endl << endl;
    
    // more test cases
    // may need to test draw
    // perhaps change tests for default constructor
    
    return;
}

void test_triangle(ifstream& input_file, ofstream& output_file)
{
    cout << "TRIANGLE TESTING" << endl << endl;

    Triangle t1;
    Point p1(25, 25);
    Point p2(75, 25);
    Point p3(25, 75);
    Color c(255, 255, 255);
    t1.setVertexOne(p1);
    t1.setVertexTwo(p2);
    t1.setVertexThree(p3);
    t1.setColor(c);
    cout << t1 << endl;

    Color c1(255, 0, 0);
    Color c2(0, 255, 0);
    Color c3(0, 0, 255);
    t1.setVertexOneColor(c1);
    t1.setVertexTwoColor(c2);
    t1.setVertexThreeColor(c3);
    cout << t1.getVertexOne() << " " << t1.getVertexTwo() << " "
        << t1.getVertexThree() << "  " << t1.getVertexOneColor() << " "
        << t1.getVertexTwoColor() << " " << t1.getVertexThreeColor() << endl;
    cout << t1 << endl;

    Triangle t2(p1, p2, p3, c);
    cout << t2 << endl;

    Triangle t3(p1, c1, p2, c2, p3, c3);
    cout << t3 << endl;

    t1.read(input_file);
    cout << t1 << endl;

    t2.read(input_file);
    cout << t2 << endl;

    t2.write(output_file);
    output_file << endl << endl;

    cout << endl << endl << endl;

    // more test cases
    // may need to test draw
    // perhaps change tests for default constructor

    return;
}

void test_rectangle(ifstream& input_file, ofstream& output_file)
{
    
    cout << "RECTANGLE TESTING" << endl << endl;

    Rectangle r1;
    Point p1(25, 25);
    Point p2(50, 75);
    Color c(100, 100, 100);
    r1.setStart(p1);
    r1.setEnd(p2);
    r1.setColor(c);
    cout << r1 << endl;

    Color c1(50, 50, 50);
    Color c2(100, 100, 100);
    Color c3(150, 150, 150);
    Color c4(200, 200, 200);
    r1.setColorTopLeft(c1);
    r1.setColorTopRight(c2);
    r1.setColorBottomRight(c3);
    r1.setColorBottomLeft(c4);
    cout << r1.getStart() << " " << r1.getEnd() << " "
        << r1.getColorTopLeft() << " " << r1.getColorTopRight() << " "
        << r1.getColorBottomRight() << " " << r1.getColorBottomLeft() << endl;
    cout << r1 << endl;

    Rectangle r2(p1, p2, c);
    cout << r2 << endl;

    Rectangle r3(p1, p2, c1, c2, c3, c4);
    cout << r3 << endl;
    
    r1.read(input_file);
    cout << r1 << endl;

    r2.read(input_file);
    cout << r2 << endl;
    
    r3.read(input_file);
    cout << r3 << endl;

    r1.write(output_file);
    output_file << endl << endl;
    
    cout << endl << endl << endl;

    // more test cases
    // may need to test draw
    // perhaps change tests for default constructor

    return;
}