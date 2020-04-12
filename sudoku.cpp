#include "sudoku.h"
#include <cmath>
#include <iostream>

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
                        this->grid[y][x] = n;
                        solve();
                        this->grid[y][x] = 0;
                    }
                }
                return;
            }
        }
    }
    toString();
}

void Sudoku::toString() {
    std::string characters;
    int val;
    std::cout << "   0 1 2 3 4 5 6 7 8\n" << "  +-----------------+\n";
    for (int i = 0; i < 9; i++) {
        std::cout << ' ' << i << '|';
        for(int j=0; j < 9; j++) {
            val = this->grid[i][j];
            if (val == 0){
                if (j==8) {
                    std::cout << "□";
                } else {
                    std::cout << "□ ";
                }
            } else {
                if (j==8) {
                    std::cout << val;
                } else {
                    std::cout << val << " ";
                }
            }
        }
        std::cout << "|\n";
    }
    std::cout << "  +-----------------+\n";
    std::cout << characters << "\n";
}

