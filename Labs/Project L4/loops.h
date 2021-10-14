#ifndef loops_h
#define loops_h

#include <string>
using namespace std;


//////////////////////////////////////////////////////////////////////
// STUDENT-IMPLEMENTED UTILITY FUNCTIONS                            //
// -------------------------------------                            //
// You will need to implement these.                                //
//////////////////////////////////////////////////////////////////////


// NOTE for every function
// The last line should end with an 'endl'
// There should be no blank lines printed at the beginning
// nor at the end



/**
 * Requires: rows must be > 0,
 *           cols must be > 0
 * Effects: prints a rectangle of *'s
 *          Prints an endl at the end of each row
 *
 * Example: printRectangle(3,2);
 *          cout << endl;
 *          printRectangle(1,3);
 *          cout << endl;
 * Note:  no spaces at the end of lines
 *        In the example below '|' indicates the left-hand edge
 *        The blank lines below are printed by test.cpp NOT by print_rectangle()
 *              |**
 *              |**
 *              |**
 *              |
 *              |**
 *              |
 */
void print_rectangle(int rows, int cols);
 
 
 
/**
 * Requires: n must be > 0
 * Modifies: nothing
 * Effects: prints a right triangle
 *          Prints an endl at the end of each row
 *
 * Example:  printRight(3);
 * Note: no spaces at the end of lines
 *      In the example below '|' indicates the left-hand edge
 *             |*
 *             |**
 *             |***
 */
void print_right(int n);
 


/**
 * Requires: n must be > 0
 * Modifies: nothing
 * Effects: prints a right justified triangle
 *          Prints an endl at the end of each row
 *
 * Example:  printRight(3);
 * Note: no spaces at the end of lines
 *      In the example below '|' indicates the left-hand edge
 *             |  *
 *             | **
 *             |***
 */
void print_right_justified(int n);

#endif
