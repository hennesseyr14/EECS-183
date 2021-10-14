/**
 * Answer.cpp
 *
 * EECS 183: Lab 7
 *
 * Implementation for Answer class functions.
 * Do NOT implement these functions for Lab 7.
 */

#include "Answer.h"

Answer::Answer() {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
}

Answer::Answer(int inWeight, string inText) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
}

int Answer::getWeight() {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return 0;
}

void Answer::setWeight(int inWeight) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}

string Answer::getText() {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return "";
}

void Answer::setText(string inText) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}


void Answer::read(istream &ins) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}


void Answer::write(ostream &outs) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}

/**
* Overloading >> and << for reading and writing Answer to and from streams.
*/
istream& operator >> (istream& ins, Answer& answer)
{
    answer.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Answer answer)
{
    answer.write(outs);
    return outs;
}


