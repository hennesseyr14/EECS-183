/**
 * Point.cpp
 *
 * EECS 183, Fall 2017
 * Project 4: CoolPics
 *
 * Ryan Hennessey
 * rjhenn
 *
 * Implementations of member functions and constructors for Point class.
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal)
{
    x = checkRange(xVal);
    y = checkRange(yVal);
}


void Point::setX(int xVal)
{
    x = checkRange(xVal);
    return;
}

int Point::getX()
{
    return x;
}

void Point::setY(int yVal)
{
    y = checkRange(yVal);
    return;
}

int Point::getY()
{
    return y;
}

void Point::read(istream& ins)
{
    // create dummy variable to read in parentheses and comma
    char dummyChar;

    // read in chars and data, verifying that data is within range
    ins >> dummyChar;
    ins >> x;
    x = checkRange(x);
    ins >> dummyChar;
    ins >> y;
    y = checkRange(y);
    ins >> dummyChar;
    return;
}

void Point::write(ostream& outs)
{
    outs << "(" << x << ", " << y << ")";
    return;
}

int Point::checkRange(int val)
{
    if (val < 0)
    {
        return 0;
    }
    else if (val >= DIMENSION)
    {
        return DIMENSION - 1;
    }
    else
    {
        return val;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
