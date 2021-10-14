/**
 * lab1.cpp
 * 
 * Ryan Hennessey
 * rjhenn
 * 
 * EECS 183:Lab 1
 *
 * Calculates number of flowers remaining in greenhouse.
 */

#include <iostream>
using namespace std;

int main() {
    int greenhouseFlowers = 20;
    int pickedFlowers = 0;

    cout << "Flower Picking Program" << endl;
    cout << "How many flowers do you want to pick? ";
    cin  >> pickedFlowers;
    greenhouseFlowers -= pickedFlowers;
    cout << "Flowers remaining: " << greenhouseFlowers;
    return 0;
}

