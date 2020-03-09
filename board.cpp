#include "board.h"
#include <iostream>
#include <map>
#include <array>
#include <cmath>
using namespace std;

// assuming the initial board is valid
board::board(std::array<int, 81> init){
    for (int i=0; i<init.size(); i++){
        cell newCell(init[i]);
        if (init[i] != 0){
            newCell.setState(FOUND);
            newCell.clearMissing();
        }

        map.insert(std::pair<int, cell>(i, newCell));
    }
};

cell* board::getCell(int x, int y){
    return &map.at(getIndex(x, y));
};

int board::getIndex(int x, int y){
    return (y*9)+x;
};

// assuming cell not found
bool board::checkRow(int row, int cellValue){
    for (int i=0; i<9; i++) {
        if ((*getCell(i, row)).getValue() == cellValue) {
            return true;
        }
    }
    return false;
};

// assuming cell not found
bool board::checkCol(int col, int cellValue){
    for (int i=0; i<9; i++) {
        if ((*getCell(col, i)).getValue() == cellValue) {
            return true;
        }
    }
    return false;
};

// assuming cell not found
bool board::checkSquare(int cellX, int cellY, int cellValue){
    int flooredX = (floor(cellX/3)*3);
    int flooredY = (floor(cellY/3)*3);
    for (int x = flooredX; x<flooredX+3; x++) {
        for (int y = flooredY; y<flooredY+3; y++) {
            if ((*getCell(x, y)).getValue() == cellValue) {
                return true;
            }
        }
    }
    return false;
};

void board::toString(){
    string characters;
    int val;
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
    cout << characters << "\n";
};

void board::eliminateMissing(int x, int y) {
    cell *currentCell = getCell(x, y);
    list<int> missing = (*currentCell).getMissing();
    for (std::list<int>::iterator it=missing.begin(); it != missing.end(); ++it) {
        if (checkRow(y, *it) == true) {
            (*currentCell).removeMissing(*it);
        } else if (checkCol(x, *it) == true) {
            (*currentCell).removeMissing(*it);
        } else if (checkSquare(x, y, *it)) {
            (*currentCell).removeMissing(*it);
        }
    }
};



