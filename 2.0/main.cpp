#include "sudoku.h"

int main() {
    int** init = new int*[9];
    for (int i=0; i<9; i++) {
        init[i] = new int[9];
    }

    Sudoku game(init);

    return 0;
}