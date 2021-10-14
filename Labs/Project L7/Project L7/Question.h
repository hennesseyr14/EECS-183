#ifndef QUESTION_H
#define QUESTION_H

/**
 * Question.h
 *
 * EECS 183: Lab 7
 *
 * Header file for the Question class.
 * Do NOT modify this file.
 */

#include <iostream>
#include <string>

using namespace std;

#include "Answer.h"

// total possible number of choosable answers a Question can have
const int MAX_NUMBER_OF_ANSWERS = 10;


class Question {

public:
    /**
     * Requires: Nothing
     * Modifies: numAnswers, questionPrompt
     * Effects:  Initializes this question to one with an empty prompt
     *           and 0 answers
     */
    Question();


    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the number of answers for this question.
     */
    int getNumAnswers();


    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the prompt of this question.
     */
    string getQuestionPrompt();


    /**
     * Requires: Nothing
     * Modifies: questionPrompt
     * Effects:  Sets the value of prompt of this question to inQuestionPrompt.
     */
    void setQuestionPrompt(string inQuestionPrompt);


    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the answer at index after checking its validity.
     *           If index is invalid, returns a default constructed Answer.
     */
    Answer getAnswer(int index);


    /**
     * Requires: Nothing
     * Modifies: answers and numAnswers
     * Effects:  Adds the inAnswer to the end of the answers array.
     *           If numAnswers >= MAX_NUMBER_OF_ANSWERS, no state is changed.
     */
    void addAnswer(Answer &inAnswer);


    /**
     * Requires: ins is in the good state
     * Modifies: ins, numAnswers, questionPrompt, and answers.
     * Effects:  Initialize numAnswers, questionPrompt, and answers by reading
     *           from ins.
     * Format:   #of answers followed by the question prompt
     *           the next lines are the answers
     *           (remember these are in the format of an Answer)
     * Example:  2What is your favorite color?
     *           5 blue
     *           2 red
     * Note:     You will need to assume that the number of answers and
     *           the number of actual answers match.
     * Note:     You will want to use addAnswer() in this one to make sure
     *           you do not exceed the bounds of the array.
     */
    void read(istream &ins);


    /**
     * Requires: outs is in the good state
     * Modifies: outs
     * Effects:  Prints the question and numbered answers to the output stream.
     * Format:   Do you enjoy EECS183?    <--this is the question prompt
     *           1) Yes                   <--these are the numbered answers
     *           2) No
     * Note: You should call write() on an Answer instance to print it out.
     */
    void write(ostream &outs);


private:
    /**
     * The number of chooseable answers for this question.
     * It must be between 0 and MAX_NUMBER_OF_ANSWERS inclusive.
     */
    int numAnswers;


    /**
     * The prompt, i.e. "What's your favorite color?"
     */
    string questionPrompt;


    /**
     * The array of chooseable Answers to the question.
     */
    Answer answers[MAX_NUMBER_OF_ANSWERS];

};

/**
* Overloading >> and << for reading and writing Question to and from streams.
*/
istream& operator >> (istream& ins, Question& question);
ostream& operator << (ostream& outs, Question question);

#endif
