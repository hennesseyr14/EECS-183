#ifndef ANSWER_H
#define ANSWER_H

/**
 * Answer.h
 *
 * EECS 183: Lab 7
 *
 * Header file for the Answer class.
 * Do NOT modify this file.
 */

#include <iostream>
#include <string>

using namespace std;

class Answer {

public:
    /**
    * Requires: Nothing
    * Modifies: weight, text
    * Effects:  Default constructor
    *           Initializes weight to 0, text to an empty string
    */
    Answer();

    /**
     * Requires: Nothing
     * Modifies: weight, text
     * Effects:  Non-Default constructor
     *           Initializes weight to inWieght, text to inText 
     */
    Answer(int inWeight, string inText);

    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the text of this answer
     */
    string getText();


    /**
     * Requires: Nothing
     * Modifies: text
     * Effects:  Set the answer text to the inText
     */
    void setText(string inText);


    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the text of this answer
     */
    int getWeight();


    /**
     * Requires: Nothing
     * Modifies: text
     * Effects:  Set the answer text to the inText
     */
    void setWeight(int inWeight);


    /**
     * Requires: ins to be in the good state
     * Modifies: ins, weight, text
     * Effects:  Initializes private data member from the input stream.
     * Effects:  Sets the values of this answer
     *           weight and text by reading values from the ins.
     */
    void read(istream &ins);


    /**
     * Requires: outs to be in the good state
     * Modifies: outs
     * Effects:  Writes the answer text to the output stream outs.
     *           Does not write the weight.     
     */
    void write(ostream &outs);


private:
    // The text for this answer
    string text;

    // the weight factor for this answer
    int weight;

};

/**
* Overloading >> and << for reading and writing Answer to and from streams.
*/
istream& operator >> (istream& ins, Answer& answer);
ostream& operator << (ostream& outs, Answer Answer);

#endif
