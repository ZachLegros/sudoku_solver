#include "sudoku.h"
#include <iostream>

int main() {
    int oneD[81] = {7, 0, 8, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 6, 3, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 9, 0, 0, 9, 0, 6, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

    int** init = new int*[9];
    for (int i=0; i<9; i++) {
        init[i] = new int[9];
    }

    for (int y=0; y<9; y++) {
        for(int x=0; x<9; x++) {
            init[y][x] = oneD[(y*9)+x];
        }
    }

    Sudoku game(init);

    // before
    game.toString();
    game.solve();

    return 0;
}