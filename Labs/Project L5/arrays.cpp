/**
 * arrays.cpp
 *
 * EECS 183
 * Lab 5: Array exercises
 *
 * Ryan Hennessey
 * rjhenn
 *
 * A few functions to manipulate arrays.
 */

#include <iostream>

using namespace std;

/**
 * Requires: size > 0 and size is the number of elements in array
 * Modifies: cout
 * Effects : Prints the elements in the given array, delimited by curly
 *           braces and separated by commas.
 */
void print_array(const int array[], int size);

/**
 * Requires: size > 0 and size is the number of elements in array
 * Modifies: array
 * Effects : Negates each element in array.
 */
void negate_all(int array[], int size);

/**
 * Requires: size > 0 and size is the number of elements in array
 * Modifies: Nothing.
 * Effects : Returns true if the elements in array are in order from
 *           smallest to largest, with duplicates allowed.
 */
bool is_sorted(const int array[], int size);

/**
 * Requires: size > 0 and size is the number of elements in source
 *           and target
 * Modifies: target
 * Effects : First, initializes all values in target to 0. 
 *           Then, copies the positive elements from source into adjacent
 *           locations in target.
 */
void copy_positive_elements(const int source[], int target[], int size);

int main() {
    // testing negate_all()
    int values[5] = { 1, -2, 3, -4, 5 };
    negate_all(values, 5);
    print_array(values, 5);

    // testing is_sorted()
    int values1[5] = { 1, -2, 3, -4, 5 };
    int values2[6] = { 1, 2, 3, 3, 4, 5 };
    cout << is_sorted(values1, 5) << endl;
    cout << is_sorted(values2, 6) << endl;

    // testing copy_positive_elements()
    int values3[5] = { 1, -2, 3, -4, 5 };
    int values4[5] = { 2, 0, 8, 5, 1 };
    copy_positive_elements(values3, values4, 5);
    print_array(values4, 5);
    return 0;
}

void print_array(const int array[], int size) {
    cout << "{ " << array[0];
    for (int i = 1; i < size; i++) {
        cout << ", " << array[i];
    }
    cout << " }" << endl;
}

void negate_all(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = -array[i];
    }
}

bool is_sorted(const int array[], int size) {
    for (int i = 0; i + 1 < size; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void copy_positive_elements(const int source[], int target[], int size) {
    for (int i = 0; i < size; i++) {
        target[i] = 0;
    }
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (source[i] > 0) {
            target[counter] = source[i];
            counter++;
        }
    }
}
