/**
 * ohhi.cpp
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2017
 *
 * Ryan Hennessey
 * rjhenn
 *
 * 0h h1 (http://www.0hh1.com/) is a sudoku-like logic puzzle.
 * This program allows a user to play and solve an 0h h1 board.
 * This file implements necessary utility functions, validity checks,
 * solving functions, and gameplay functions as described in ohhi.h.
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // set an initial counter to zero, then iterate through the board
    // and add up the number of unknown squares
    int count = 0;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                count++;
            }
        }
    }
    return count;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    // iterate through the row in groups of three, checking to see if all the
    // elements in the group match
    for (int col = 0; col + 2 < size; col++) {
        if (board[row][col] == color && board[row][col + 1] == color
                                     && board[row][col + 2] == color) {
            return false;
        }
    }
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    // iterate through the column in groups of three, checking to see if all the
    // elements in the group match
    for (int row = 0; row + 2 < size; row++) {
        if (board[row][col] == color && board[row + 1][col] == color
                                     && board[row + 2][col] == color) {
            return false;
        }
    }
    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // iterate through each row and check if there are any groups of three
    for (int row = 0; row < size; row++) {
        if (!row_has_no_threes_of_color(board, size, row, RED)) {
            return false;
        }
        if (!row_has_no_threes_of_color(board, size, row, BLUE)) {
            return false;
        }
    }
    // iterate through each column and check if there are any groups of three
    for (int col = 0; col < size; col++) {
        if (!col_has_no_threes_of_color(board, size, col, RED)) {
            return false;
        }
        if (!col_has_no_threes_of_color(board, size, col, BLUE)) {
            return false;
        }
    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    for (int col = 0; col < size; col++) {
        // check to see if any of the elements in either row are unknown
        if (board[row1][col] == UNKNOWN || board[row2][col] == UNKNOWN) {
            return true;
        }
        // check to see if each element matches in the two rows
        else if (board[row1][col] != board[row2][col]) {
            return true;
        }
    }
    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    for (int row = 0; row < size; row++) {
        // check to see if any of the elements in either column are unknown
        if (board[row][col1] == UNKNOWN || board[row][col2] == UNKNOWN) {
            return true;
        }
        // check to see if each element matches in the two columns
        else if (board[row][col1] != board[row][col2]) {
            return true;
        }
    }
    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // iterate through each possible combination of rows
    // and make sure none none match
    for (int row1 = 1; row1 < size; row1++) {
        for (int row2 = 0; row2 < row1; row2++) {
            if (!rows_are_different(board, size, row1, row2)) {
                return false;
            }

        }
    }
    // iterate through each possible combination of columns
    // and make sure none none match
    for (int col1 = 1; col1 < size; col1++) {
        for (int col2 = 0; col2 < col1; col2++) {
            if (!cols_are_different(board, size, col1, col2)) {
                return false;
            }

        }
    }
    return true;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    // iterate through the row in groups of three
    for (int col = 0; col + 2 < size; col++) {
        // mark the next square after two consecutive (if unknown)
        if (board[row][col] == board[row][col + 1]
            && board[row][col] != UNKNOWN) {
            int color = opposite_color(board[row][col]);
            if (board[row][col + 2] == UNKNOWN) {
                mark_square_as(board, size, row, col + 2, color, announce);
            }
        }
        // mark the preceding square before two consecutive (if unknown)
        if (board[row][col + 1] == board[row][col + 2]
            && board[row][col + 1] != UNKNOWN) {
            int color = opposite_color(board[row][col + 1]);
            if ((board[row][col] == UNKNOWN)) {
                mark_square_as(board, size, row, col, color, announce);
            }
        }
        // mark the square in between two matching (if unknown)
        if (board[row][col] == board[row][col + 2]
            && board[row][col] != UNKNOWN) {
            int color = opposite_color(board[row][col]);
            if ((board[row][col + 1] == UNKNOWN)) {
                mark_square_as(board, size, row, col + 1, color, announce);
            }
        }
    }
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    // iterate through the column in groups of three
    for (int row = 0; row + 2 < size; row++) {
        // mark the next square after two consecutive (if unknown)
        if (board[row][col] == board[row + 1][col]
            && board[row][col] != UNKNOWN) {
            int color = opposite_color(board[row][col]);
            if (board[row + 2][col] == UNKNOWN) {
                mark_square_as(board, size, row + 2, col, color, announce);
            }
        }
        // mark the preceding square before two consecutive (if unknown)
        if (board[row + 1][col] == board[row + 2][col]
            && board[row + 1][col] != UNKNOWN) {
            int color = opposite_color(board[row + 1][col]);
            if ((board[row][col] == UNKNOWN)) {
                mark_square_as(board, size, row, col, color, announce);
            }
        }
        // mark the square in between two matching (if unknown)
        if (board[row][col] == board[row + 2][col]
            && board[row][col] != UNKNOWN) {
            int color = opposite_color(board[row][col]);
            if ((board[row + 1][col] == UNKNOWN)) {
                mark_square_as(board, size, row + 1, col, color, announce);
            }
        }
    }
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    // count number of reds in a given row
    int count_red = 0;
    for (int col = 0; col < size; col++) {
        if (board[row][col] == RED) {
            count_red++;
        }
    }
    // fill in blues if half the row consists of red
    if (count_red == size / 2) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, BLUE, announce);
            }
        }
    }

    // count number of blues in a given row
    int count_blue = 0;
    for (int col = 0; col < size; col++) {
        if (board[row][col] == BLUE) {
            count_blue++;
        }
    }
    // fill in reds if half the row consists of blue
    if (count_blue == size / 2) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, RED, announce);
            }
        }
    }
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    // count number of reds in a given column
    int count_red = 0;
    for (int row = 0; row < size; row++) {
        if (board[row][col] == RED) {
            count_red++;
        }
    }
    // fill in blues if half the column consists of red
    if (count_red == size / 2) {
        for (int row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, BLUE, announce);
            }
        }
    }

    // count number of blues in a given column
    int count_blue = 0;
    for (int row = 0; row < size; row++) {
        if (board[row][col] == BLUE) {
            count_blue++;
        }
    }
    // fill in reds if half the column consists of blue
    if (count_blue == size / 2) {
        for (int row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, RED, announce);
            }
        }
    }
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // verify that there are no unknown squares
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                return false;
            }
        }
    }
    // verify that the board satisfies all the rules
    return board_is_valid(board, size);
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // create error message
    string message = "Sorry, that's not a valid input.";
    // check to see if rows are within the bounds
    if (row_input < 1 || row_input > size) {
        cout << message << endl;
        return false;
    }
    // check to see if columns are within bounds
    // allow for uppercase and lowercase
    if ((col_input < 'A' || col_input > 'A' + size - 1)
        && (toupper(col_input) < 'A' || toupper(col_input) > 'A' + size - 1)) {
        cout << message << endl;
        return false;
    }
    // check to see if the color is valid
    // allow for uppercase and lowercase
    if (color_char != RED_LETTER
        && color_char != BLUE_LETTER
        && color_char != UNKNOWN_LETTER
        && toupper(color_char) != RED_LETTER
        && toupper(color_char) != BLUE_LETTER
        && toupper(color_char) != UNKNOWN_LETTER) {
        cout << message << endl;
        return false;
    }
    // assign values to row and col corresponding to 0 indexing
    row = row_input - 1;
    col = toupper(col_input) - 'A';
    return true;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // check if the square was specified in the original board
    if (original_board[row][col] != UNKNOWN) {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
    // create a new board equivalent to the current board
    int board[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = current_board[i][j];
        }
    }
    // add the proposed move to the new board
    mark_square_as(board, size, row, col, color, false);
    // check to see whether the new move violates a rule
    if (!board_is_valid(board, size)) {
        cout << "Sorry, that move violates a rule." << endl;
        return false;
    }
    return true;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    
}
