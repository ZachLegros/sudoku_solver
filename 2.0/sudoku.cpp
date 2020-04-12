#include "sudoku.h"
#include <cmath>

Sudoku::Sudoku(int** init) {
    grid = init;
}

bool Sudoku::isPossible(int x, int y, int n) {
    if(this->grid[y][x] != 0) {
        return false;
    }
    for (int i=0; i<9; i++) {
        if (this->grid[y][i] == n) {
            return false;
        }
    }
    for (int j=0; j<9; j++) {
        if (this->grid[j][x] == n) {
            return false;
        }
    }
    int flooredX = (floor(x/3)*3);
    int flooredY = (floor(y/3)*3);
    for (int x = flooredX; x<flooredX+3; x++) {
        for (int y = flooredY; y<flooredY+3; y++) {
            if(this->grid[y][x] == n) {
                return false;
            }
        }
    }
    return true;
}

void Sudoku::solve() {
    for (int y = 0; y<9; y++) {
        for (int x = 0; x<9; x++) {
            if (this->grid[y][x] == 0) {
                for (int n=1; n<10; n++) {
                    if (isPossible(x, y, n)) {
                        grid[y][x] = n;
                        solve();
                        grid[y][x] = 0;
                    }
                }
                return;
            }
        }
    }
    toString();
}

void Sudoku::toString() {
/*     string characters;
    int val;
    cout << "Found " << found << " values.\n"; 
    cout << "   0 1 2 3 4 5 6 7 8\n" << "  +-----------------+\n";
    for (int i = 0; i < 9; i++) {
        cout << ' ' << i << '|';
        for(int j=0; j < 9; j++) {
            val = (*getCell(j, i)).getValue();
            if (val == 0){
                if (j==8) {
                    cout << "□";
                } else {
                    cout << "□ ";
                }
            } else {
                if (j==8) {
                    cout << val;
                } else {
                    cout << val << " ";
                }
            }
        }
        cout << "|\n";
    }
    cout << "  +-----------------+\n";
    cout << characters << "\n"; */
}

