#ifndef SUDOKU_H
#define SUDOKU_H

#include <bits/stdc++.h>

using namespace std;

class sudoku {
    int grid[9][9];
    bool solved;

public:
    // sudoku();                   // generate random sudoku board
    sudoku(int grid[9][9]);     // initialize grid from given grid
    pair<int, int> findUnassigned() const;  // returns random unassigned square
    bool isValid(int, int, int) const;      // make sure number doesn't break the board rules
    bool processSudoku();             // return true if sudoku has solution
    void printGrid() const;     // prints grid
};

#endif