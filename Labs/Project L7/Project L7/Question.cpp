/**
 * Question.cpp
 *
 * EECS 183: Lab 7
 *
 * Implementation for Question class functions.
 * Do NOT implement these functions for Lab 7.
 */

#include "Question.h"

Question::Question() {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
}

int Question::getNumAnswers() {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return 0;
}

string Question::getQuestionPrompt() {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return "";
}

void Question::setQuestionPrompt(string inQuestionPrompt) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}

Answer Question::getAnswer(int index) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    Answer nonAnswer;
    return nonAnswer;
}

void Question::addAnswer(Answer &inAnswer) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}

void Question::read(istream &ins) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}


void Question::write(ostream &outs) {
    // Intentionally left blank
    // You do not need to implement the Answer class functions for Lab 7
    return;
}

/**
* Overloading >> and << for reading and writing Question to and from streams.
*/
istream& operator >> (istream& ins, Question& question)
{
    question.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Question question)
{
    question.write(outs);
    return outs;
}
