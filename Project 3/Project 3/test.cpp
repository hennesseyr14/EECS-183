/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2017
 *
 * Ryan Hennessey
 * rjhenn
 *
 * Test suite fof functions in ohhi.cpp.
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

int main() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"OXOX",
                             "OOXX",
                             "XXOO",
                             "XOOO"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;

    // test case 3
    string test_board_3[] = {"----",
                             "----",
                             "----",
                             "----"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;

}


void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_1 = 4;
    int row_1 = 1;
    int color_1 = RED;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, row_1, color_1) << endl;

    // test case 2
    string test_board_2[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_2 = 4;
    int row_2 = 2;
    int color_2 = RED;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, row_2, color_2) << endl;

    // test case 3
    string test_board_3[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_3 = 4;
    int row_3 = 1;
    int color_3 = BLUE;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, row_3, color_3) << endl;

    // test case 4
    string test_board_4[] = {"----",
                             "OOO-",
                             "O-OO",
                             "--X-"};
    int size_4 = 4;
    int row_4 = 1;
    int color_4 = BLUE;
    read_board_from_string(board, test_board_4, size_4);
    cout << row_has_no_threes_of_color(board, size_4, row_4, color_4) << endl;

    // test case 5
    string test_board_5[] = {"----",
                             "OOO-",
                             "O-OO",
                             "--X-"};
    int size_5 = 4;
    int row_5 = 2;
    int color_5 = BLUE;
    read_board_from_string(board, test_board_5, size_5);
    cout << row_has_no_threes_of_color(board, size_5, row_5, color_5) << endl;

    // test case 6
    string test_board_6[] = {"----",
                             "OOO-",
                             "O-OO",
                             "--X-"};
    int size_6 = 4;
    int row_6 = 1;
    int color_6 = RED;
    read_board_from_string(board, test_board_6, size_6);
    cout << row_has_no_threes_of_color(board, size_6, row_6, color_6) << endl;

}

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_1 = 4;
    int col_1 = 1;
    int color_1 = RED;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, col_1, color_1) << endl;

    // test case 2
    string test_board_2[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_2 = 4;
    int col_2 = 2;
    int color_2 = RED;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, col_2, color_2) << endl;

    // test case 3
    string test_board_3[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_3 = 4;
    int col_3 = 2;
    int color_3 = BLUE;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, col_3, color_3) << endl;

    // test case 4
    string test_board_4[] = {"-XX-",
                             "OOX-",
                             "-OX-",
                             "-XX-"};
    int size_4 = 4;
    int col_4 = 2;
    int color_4 = RED;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, col_4, color_4) << endl;

    size_4 = 4;
    col_4 = 2;
    color_4 = BLUE;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, col_4, color_4) << endl;

    size_4 = 4;
    col_4 = 1;
    color_4 = RED;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, col_4, color_4) << endl;

    size_4 = 4;
    col_4 = 3;
    color_4 = BLUE;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, col_4, color_4) << endl;


}


void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_threes(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2) << endl;

    string test_board_3[] = {"----",
                           "----",
                           "----",
                           "----"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_threes(board, size_3) << endl;

    string test_board_4[] = {"XXOO",
                           "XOXO",
                           "OOXX",
                           "OXOX"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_threes(board, size_4) << endl;

    string test_board_5[] = {"XXXX",
                           "OOOO",
                           "XXXX",
                           "----"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_threes(board, size_5) << endl;

    string test_board_6[] = {"X-OO",
                           "X-XO",
                           "X-XX",
                           "O-OX"};
    int size_6 = 4;
    read_board_from_string(board, test_board_6, size_6);
    cout << board_has_no_threes(board, size_6) << endl;
}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOOX",
                             "XOOX",
                             "----",
                             "----"};
    int size_1 = 4;
    int row1_1 = 0;
    int row2_1 = 1;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, row1_1, row2_1) << endl;

    // test case 2
    string test_board_2[] = {"XOOX",
                             "XXOO",
                             "----",
                             "----"};
    int size_2 = 4;
    int row1_2 = 0;
    int row2_2 = 1;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, row1_2, row2_2) << endl;

    // test case 3
    string test_board_3[] = {"XO-X",
                             "XOOX",
                             "----",
                             "----"};
    int size_3 = 4;
    int row1_3 = 0;
    int row2_3 = 1;
    read_board_from_string(board, test_board_3, size_3);
    cout << rows_are_different(board, size_3, row1_3, row2_3) << endl;

    // test case 4
    string test_board_4[] = {"XO-X",
                             "XOOX",
                             "----",
                             "----"};
    int size_4 = 4;
    int row1_4 = 2;
    int row2_4 = 3;
    read_board_from_string(board, test_board_4, size_4);
    cout << rows_are_different(board, size_4, row1_4, row2_4) << endl;

    // test case 5
    string test_board_5[] = {"XO-X",
                             "XO-X",
                             "----",
                             "----"};
    int size_5 = 4;
    int row1_5 = 0;
    int row2_5 = 1;
    read_board_from_string(board, test_board_5, size_5);
    cout << rows_are_different(board, size_5, row1_5, row2_5) << endl;

    string test_board[] = {"XO-X",
                           "XO-X",
                           "----",
                           "----"};
    int size = 4;
    int row1 = 2;
    int row2 = 3;
    read_board_from_string(board, test_board_4, size);
    cout << rows_are_different(board, size, row1, row2) << endl;

    string test_board_6[] = {"XOXO",
                           "XOX-",
                           "----",
                           "----"};
    size = 4;
    row1 = 2;
    row2 = 3;
    read_board_from_string(board, test_board_5, size);
    cout << rows_are_different(board, size, row1, row2) << endl;
}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XX--",
                             "OO--",
                             "OO--",
                             "XX--"};
    int size_1 = 4;
    int col1_1 = 0;
    int col2_1 = 1;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, col1_1, col2_1) << endl;

    // test case 2
    string test_board_2[] = {"XX--",
                             "OX--",
                             "OO--",
                             "XO--"};
    int size_2 = 4;
    int col1_2 = 0;
    int col2_2 = 1;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, col1_2, col2_2) << endl;

    // test case 3
    string test_board_3[] = {"XX--",
                             "OO--",
                             "-O--",
                             "XX--"};
    int size_3 = 4;
    int col1_3 = 0;
    int col2_3 = 1;
    read_board_from_string(board, test_board_3, size_3);
    cout << cols_are_different(board, size_3, col1_3, col2_3) << endl;

    // test case 4
    string test_board_4[] = {"XX--",
                             "OO--",
                             "-O--",
                             "XX--"};
    int size_4 = 4;
    int col1_4 = 2;
    int col2_4 = 3;
    read_board_from_string(board, test_board_4, size_4);
    cout << cols_are_different(board, size_4, col1_4, col2_4) << endl;

    // test case 5
    string test_board_5[] = {"XX--",
                             "OO--",
                             "----",
                             "XX--"};
    int size_5 = 4;
    int col1_5 = 0;
    int col2_5 = 1;
    read_board_from_string(board, test_board_5, size_5);
    cout << cols_are_different(board, size_5, col1_5, col2_5) << endl;

    // test case 6
    string test_board_6[] = {"XX--",
                             "OO--",
                             "----",
                             "XX--"};
    int size_6 = 4;
    int col1_6 = 2;
    int col2_6 = 3;
    read_board_from_string(board, test_board_6, size_6);
    cout << cols_are_different(board, size_6, col1_6, col2_6) << endl;

    // test case 7
    string test_board_7[] = {"XX--",
                             "OX--",
                             "XO--",
                             "XX--"};
    int size_7 = 4;
    int col1_7 = 0;
    int col2_7 = 1;
    read_board_from_string(board, test_board_7, size_7);
    cout << cols_are_different(board, size_7, col1_7, col2_7) << endl;

    
}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"OO--",
                             "XXOO",
                             "XXO-",
                             "O-X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"OO--",
                             "XXOO",
                             "XXOO",
                             "O-O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;

    // test case 3
    string test_board_3[] = {"O-",
                             "O-"};
    int size_3 = 2;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_duplicates(board, size_3) << endl;

    // test case 4
    string test_board_4[] = {"OXXO",
                             "XOXO",
                             "OXOX",
                             "XOOX"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_duplicates(board, size_4) << endl;

    // test case 5
    string test_board_5[] = {"----",
                             "----",
                             "----",
                             "----"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_duplicates(board, size_5) << endl;

    // test case 6
    string test_board_6[] = {"XXX-",
                             "XXX-",
                             "----",
                             "----"};
    int size_6 = 4;
    read_board_from_string(board, test_board_6, size_6);
    cout << board_has_no_duplicates(board, size_6) << endl;

}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    int row_1 = 0;
    bool announce_1 = true;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, row_1, announce_1);

    // test case 2
    string test_board_2[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_2 = 4;
    int row_2 = 2;
    bool announce_2 = true;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board, size_2, row_2, announce_2);

    // test case 3
    string test_board_3[] = {"----",
                             "X-X-",
                             "----",
                             "--X-"};
    int size_3 = 4;
    int row_3 = 1;
    bool announce_3 = true;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board, size_3, row_3, announce_3);

    // test case 4
    string test_board_4[] = {"OO",
                             "XX" };
    int size_4 = 2;
    int row_4 = 1;
    bool announce_4 = true;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_row(board, size_4, row_4, announce_4);

    // test case 5
    string test_board_5[] = {"----",
                             "XXX-",
                             "----",
                             "--X-"};
    int size_5 = 4;
    int row_5 = 1;
    bool announce_5 = true;
    read_board_from_string(board, test_board_5, size_5);
    solve_three_in_a_row(board, size_5, row_5, announce_5);
}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    int col_1 = 3;
    bool announce_1 = true;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, size_1, col_1, announce_1);

    // test case 2
    string test_board_2[] = {"----",
                             "X-X-",
                             "----",
                             "--X-"};
    int size_2 = 4;
    int col_2 = 2;
    bool announce_2 = true;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, col_2, announce_2);

    
    // test case 3
    string test_board_3[] = {"----",
                             "O-O-",
                             "----",
                             "--O-"};
    int size_3 = 4;
    int col_3 = 2;
    bool announce_3 = true;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_column(board, size_3, col_3, announce_3);

    // test case 4
    string test_board_4[] = {"--O-",
                             "O-O-",
                             "----",
                             "----"};
    int size_4 = 4;
    int col_4 = 3;
    bool announce_4 = true;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_column(board, size_4, col_4, announce_4);

    // test case 5
    string test_board_5[] = {"XO",
                             "XO"};
    int size_5 = 2;
    int col_5 = 0;
    bool announce_5 = true;
    read_board_from_string(board, test_board_5, size_5);
    solve_three_in_a_column(board, size_5, col_5, announce_5);

    // test case 6
    string test_board_6[] = {"-O--",
                             "-O--",
                             "----",
                             "----"};
    int size_6 = 4;
    int col_6 = 0;
    bool announce_6 = true;
    read_board_from_string(board, test_board_6, size_6);
    solve_three_in_a_column(board, size_6, col_6, announce_6);

    // test case 7
    string test_board_7[] = {"-O--",
                             "-O--",
                             "O---",
                             "----"};
    int size_7 = 4;
    int col_7 = 0;
    bool announce_7 = true;
    read_board_from_string(board, test_board_7, size_7);
    solve_three_in_a_column(board, size_7, col_7, announce_7);

    // test case 8
    string test_board_8[] = {"XO--",
                             "XO--",
                             "O---",
                             "O---"};
    int size_8 = 4;
    int col_8 = 0;
    bool announce_8 = true;
    read_board_from_string(board, test_board_8, size_8);
    solve_three_in_a_column(board, size_8, col_8, announce_8);


}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    int row_1 = 1;
    bool announce_1 = true;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, size_1, row_1, announce_1);

    // test case 2
    string test_board_2[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_2 = 4;
    int row_2 = 2;
    bool announce_2 = true;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, row_2, announce_2);

    // test case 3
    string test_board_3[] = {"----",
                             "XX--",
                             "-XX-",
                             "O-O-"};
    int size_3 = 4;
    int row_3 = 3;
    bool announce_3 = true;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board, size_3, row_3, announce_3);

    // test case 4
    string test_board_4[] = {"----",
                             "XX--",
                             "-XX-",
                             "O--O"};
    int size_4 = 4;
    int row_4 = 3;
    bool announce_4 = true;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_row(board, size_4, row_4, announce_4);

    // test case 5
    string test_board_5[] = {"----",
                             "XX--",
                             "-XX-",
                             "OXXO"};
    int size_5 = 4;
    int row_5 = 3;
    bool announce_5 = true;
    read_board_from_string(board, test_board_5, size_5);
    solve_balance_row(board, size_5, row_5, announce_5);

    // test case 6
    string test_board_6[] = {"----",
                             "XX--",
                             "-XX-",
                             "O---"};
    int size_6 = 4;
    int row_6 = 3;
    bool announce_6 = true;
    read_board_from_string(board, test_board_6, size_6);
    solve_balance_row(board, size_6, row_6, announce_6);

    // test case 7
    string test_board_7[] = {"----",
                             "XX--",
                             "-XX-",
                             "----"};
    int size_7 = 4;
    int row_7 = 3;
    bool announce_7 = true;
    read_board_from_string(board, test_board_7, size_7);
    solve_balance_row(board, size_7, row_7, announce_7);

    // test case 8
    string test_board_8[] = {"----",
                             "XX--",
                             "-XX-",
                             "OOXX"};
    int size_8 = 4;
    int row_8 = 3;
    bool announce_8 = true;
    read_board_from_string(board, test_board_8, size_8);
    solve_balance_row(board, size_8, row_8, announce_8);

    // test case 9
    string test_board_9[] = {"--",
                             "X-"};
    int size_9 = 2;
    int row_9 = 1;
    bool announce_9 = true;
    read_board_from_string(board, test_board_9, size_9);
    solve_balance_row(board, size_9, row_9, announce_9);
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    int col_1 = 1;
    bool announce_1 = true;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, col_1, announce_1);

    // test case 2
    string test_board_2[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_2 = 4;
    int col_2 = 2;
    bool announce_2 = true;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_column(board, size_2, col_2, announce_2);

    // test case 3
    string test_board_3[] = {"----",
                             "XX--",
                             "-X--",
                             "--O-"};
    int size_3 = 4;
    int col_3 = 2;
    bool announce_3 = true;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_column(board, size_3, col_3, announce_3);

    // test case 4
    string test_board_4[] = {"--X-",
                             "XXX-",
                             "-XO-",
                             "--O-"};
    int size_4 = 4;
    int col_4 = 2;
    bool announce_4 = true;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_column(board, size_4, col_4, announce_4);

    // test case 5
    string test_board_5[] = {"--X-",
                             "XXX-",
                             "-XO-",
                             "--O-"};
    int size_5 = 4;
    int col_5 = 3;
    bool announce_5 = true;
    read_board_from_string(board, test_board_5, size_5);
    solve_balance_column(board, size_5, col_5, announce_5);

}

void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_is_solved(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"OXOX",
                             "OOXX",
                             "XXOO",
                             "XOXO"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_is_solved(board, size_2) << endl;

    // test case 3
    string test_board_3[] = {"OXXX",
                             "OOXX",
                             "XXOO",
                             "XOXO"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_is_solved(board, size_3) << endl;

    // test case 4
    string test_board_4[] = {"OXOX",
                             "OXOX",
                             "XOXO",
                             "XOXO"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_is_solved(board, size_4) << endl;
}

void test_check_valid_input() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int size_1 = 4;
    int row_input_1 = 2;
    char col_input_1 = 'd';
    char color_char_1 = 'X';
    int row_1 = -1;
    int col_1 = -1;
    read_board_from_string(board, test_board_1, size_1);
    cout << check_valid_input(size_1, row_input_1, col_input_1,
                              color_char_1, row_1, col_1) << endl;
    cout << row_1 << " " << col_1 << endl;

    // test case 2
    string test_board_2[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int size_2 = 4;
    int row_input_2 = 2;
    char col_input_2 = 'e';
    char color_char_2 = 'X';
    int row_2 = -1;
    int col_2 = -1;
    read_board_from_string(board, test_board_2, size_2);
    cout << check_valid_input(size_2, row_input_2, col_input_2,
                              color_char_2, row_2, col_2) << endl;
    cout << row_2 << " " << col_2 << endl;

    // test case 3
    string test_board_3[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int size_3 = 4;
    int row_input_3 = 3;
    char col_input_3 = 'D';
    char color_char_3 = 'O';
    int row_3 = -1;
    int col_3 = -1;
    read_board_from_string(board, test_board_3, size_3);
    cout << check_valid_input(size_3, row_input_3, col_input_3,
                              color_char_3, row_3, col_3) << endl;
    cout << row_3 << " " << col_3 << endl;

    // test case 4
    string test_board_4[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int size_4 = 4;
    int row_input_4 = 3;
    char col_input_4 = 'B';
    char color_char_4 = 'o';
    int row_4 = -1;
    int col_4 = -1;
    read_board_from_string(board, test_board_4, size_4);
    cout << check_valid_input(size_4, row_input_4, col_input_4,
                              color_char_4, row_4, col_4) << endl;
    cout << row_4 << " " << col_4 << endl;

    // test case 5
    string test_board_5[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int size_5 = 4;
    int row_input_5 = 3;
    char col_input_5 = 'B';
    char color_char_5 = '-';
    int row_5 = -1;
    int col_5 = -1;
    read_board_from_string(board, test_board_5, size_5);
    cout << check_valid_input(size_5, row_input_5, col_input_5,
                              color_char_5, row_5, col_5) << endl;
    cout << row_5 << " " << col_5 << endl;
}

void test_check_valid_move() {
    int original_board[MAX_SIZE][MAX_SIZE];
    int current_board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_original_1[] = {"----",
                                "XXO-",
                                "-XO-",
                                "--X-"};
    string test_current_1[] = {"---X",
                               "XXOO",
                               "XXO-",
                               "--X-"};
    int size_1 = 4;
    int row_1 = 3;
    int col_1 = 2;
    int color_1 = BLUE;
    read_board_from_string(original_board, test_original_1, size_1);
    read_board_from_string(current_board, test_current_1, size_1);
    cout << check_valid_move(original_board, current_board, size_1,
                             row_1, col_1, color_1) << endl;

    // test case 2
    string test_original_2[] = {"----",
                                "XXO-",
                                "-XO-",
                                "--X-"};
    string test_current_2[] = {"---X",
                               "XXOO",
                               "XXO-",
                               "--X-"};
    int size_2 = 4;
    int row_2 = 2;
    int col_2 = 3;
    int color_2 = BLUE;
    read_board_from_string(original_board, test_original_2, size_2);
    read_board_from_string(current_board, test_current_2, size_2);
    cout << check_valid_move(original_board, current_board, size_2,
                             row_2, col_2, color_2) << endl;

    // test case 3
    string test_original_3[] = {"----",
                                "XXO-",
                                "-XO-",
                                "--X-"};
    string test_current_3[] = {"---X",
                               "XXOO",
                               "XXO-",
                               "--X-"};
    int size_3 = 4;
    int row_3 = 0;
    int col_3 = 0;
    int color_3 = BLUE;
    read_board_from_string(original_board, test_original_3, size_3);
    read_board_from_string(current_board, test_current_3, size_3);
    cout << check_valid_move(original_board, current_board, size_3,
                             row_3, col_3, color_3) << endl;

    // test case 4
    string test_original_4[] = {"----",
                                "XXO-",
                                "-XO-",
                                "--X-"};
    string test_current_4[] = {"---X",
                               "XXOO",
                               "XXO-",
                               "--X-"};
    int size_4 = 4;
    int row_4 = 1;
    int col_4 = 3;
    int color_4 = UNKNOWN;
    read_board_from_string(original_board, test_original_4, size_4);
    read_board_from_string(current_board, test_current_4, size_4);
    cout << check_valid_move(original_board, current_board, size_4,
                             row_4, col_4, color_4) << endl;

    // test case 5
    string test_original_5[] = {"----",
                                "XXO-",
                                "-XO-",
                                "--X-"};
    string test_current_5[] = {"---X",
                               "XXOO",
                               "XXO-",
                               "--X-"};
    int size_5 = 4;
    int row_5 = 0;
    int col_5 = 3;
    int color_5 = BLUE;
    read_board_from_string(original_board, test_original_5, size_5);
    read_board_from_string(current_board, test_current_5, size_5);
    cout << check_valid_move(original_board, current_board, size_5,
                             row_5, col_5, color_5) << endl;
}

