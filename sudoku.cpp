#include <bits/stdc++.h>
#include <ctime>
#include "sudoku.h"
using namespace std;

sudoku::sudoku(): grid{0} {
}

sudoku::sudoku(int grid[9][9]): grid{0} {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            this->grid[i][j] = grid[i][j]; 
}

pair<int, int> sudoku::findUnassigned() const {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] == 0)
                return make_pair(i, j);

    return make_pair(-1, -1);
}

bool sudoku::isValid(int number, int row, int col) const {
    // verify row and col
    for (int j = 0, i = 0; j < 9 && i < 9; j++, i++)
        if (grid[row][j] == number || grid[i][col] == number)
            return false;
    
    // verify sub-grid
    int subGridStartI = row - row % 3;
    int subGridStartJ = col - col % 3; 
    for (int i = subGridStartI; i < 3 + subGridStartI; i++)
        for (int j = subGridStartJ; j < 3 + subGridStartJ; j++)
            // if (grid[subGridStartI][subGridStartJ] == number)
            if (grid[i][j] == number)
                return false;
    
    return true;
}

bool sudoku::processSudoku() {

    // findUnassigned returns i,j of unassigned square
    pair<int, int> index = findUnassigned();
    if (index.first == -1 && index.second == -1)
        return true;    // all squares are assigned and sudoku is solved

    for (int i = 1; i <= 9; i++) {
        if (isValid(i, index.first, index.second)) {

            grid[index.first][index.second] = i;    // assign number i to square
            if (processSudoku())
                return true;

            grid[index.first][index.second] = 0;
        }
    }

    return false;
}

void sudoku::printGrid() const {
    for (int i = 0; i < 9; ++i) {
        if (i != 0) cout << '\n';
            if (i % 3 == 0 && i != 0)
                cout << '\n';
        for (int j = 0; j < 9; ++j) {
            if (j == 3 || j == 6 || j == 9)
                cout << "  ";
            cout << grid[i][j] << " ";
        }
    }
    cout << '\n';
}