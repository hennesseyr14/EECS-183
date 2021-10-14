/**
 * test.cpp
 *
 * EECS 183
 * Lab 7
 *
 * Ryan Hennessey
 * rjhenn
 *
 * Test suite for EECS Harmony.
 */

#include <iostream>
#include <fstream>
#include "Question.h"
#include "Answer.h"

void test_Question_constructor();
void test_Question(ifstream& input_file);
void test_Answer(ifstream& input_file);

/**
 * Declare more test functions here
 * It is a good idea to test all getters and setters
 * It is a good idea to test constructors
 */

int main() {
    test_Question_constructor();

    ifstream input_file;
    input_file.open("data1.txt");
    test_Question(input_file);
    test_Answer(input_file);
    // Add calls to test functions that you create here

    return 0;
}


void test_Question_constructor() {
    Question q1;

    // expected to return 0
    if (q1.getNumAnswers() != 0) {
        cout << "bug in Question default constructor: numAnswers" << endl;
    }

    // expected to return empty string
    if (q1.getQuestionPrompt() != "") {
        cout << "bug in Question default constructor: questionPrompt" << endl;
    }
}

// define more test functions here

void test_Question(ifstream& input_file) {
    Question q1;
    q1.setQuestionPrompt("Question?");
    cout << q1.getQuestionPrompt();
    cout << q1 << endl;

    Answer a1(11, "ans");
    Answer a2(12, "ans2");
    q1.addAnswer(a1);
    q1.addAnswer(a2);
    cout << q1.getAnswer(0) << endl;
    cout << q1.getAnswer(1) << endl;
    cout << q1.getAnswer(2) << endl;
    cout << q1.getAnswer(3) << endl;
    cout << q1.getNumAnswers() << endl;
    cout << q1 << endl;

    Question q2;
    input_file >> q2;
    cout << q2 << endl;
    
    return;
}
void test_Answer(ifstream& input_file) {
    Answer a1;
    cout << a1.getText() << endl;
    cout << a1.getWeight() << endl;

    a1.setWeight(25);
    cout << a1.getWeight() << endl;

    a1.setText("Yeeee");
    cout << a1.getText() << endl;

    Answer a2(12, "Yo");
    cout << a2.getText() << " " << a2.getWeight();

    Answer a3;
    input_file >> a3;
    cout << a3.getText() << " " << a3.getWeight();

    return;
}