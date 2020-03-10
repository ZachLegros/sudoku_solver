#include "board.h"
#include "cellState.h"
#include <iostream>
#include <map>
#include <array>
#include <cmath>
#include <list>
using namespace std;

// assuming the initial board is valid
board::board(std::array<int, 81> init){
    for (int i=0; i<init.size(); i++){
        cell newCell(init[i]);
        if (init[i] != 0){
            newCell.setState(FOUND);
            newCell.clearMissing();
            found += 1;
        }
        map.insert(std::pair<int, cell>(i, newCell));
    }
    cout << "Board initialized with " << found << " values found.\n";
};

board::board(std::map<int, cell> init, std::list<cell> missingIndex, int found) {
    map = init;
    this->missingIndex = missingIndex;
    this->found = found;
}

cell* board::getCell(int x, int y){
    return &map.at(getIndex(x, y));
};

int board::getIndex(int x, int y){
    return (y*9)+x;
};

void board::toString(){
    string characters;
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
    cout << characters << "\n";
};

void board::eliminateMissing() {
    int value;
    int compareFound = this->found;
    for (int y=0; y<9; y++) {
        for (int x=0; x<9; x++) {
            if ((*getCell(x, y)).getState() == cellState::FOUND) {
                value = (*getCell(x, y)).getValue();
                clearMissingRow(y, value);
                clearMissingCol(x, value);
                clearMissingSquare(x, y, value);
            }
        }
    }
    if (compareFound != this->found && this->found < 81) {
        eliminateMissing();
    } else if (this->found == 81) {
        solved = true;
    }
}

void board::clearMissingRow(int y, int value) {
    for (int x=0; x<9; x++) {
        if ((*getCell(x, y)).getState() != cellState::FOUND && (*getCell(x, y)).isMissing(value) == true) {
            (*getCell(x, y)).removeMissing(value);
            if ((*getCell(x, y)).getMissingSize() == 0) {
                (*getCell(x, y)).setState(FOUND);
                this->found += 1;
                (*getCell(x, y)).setValue(value);
                missingIndex.remove((*getCell(x, y)));
            }
        }
    }
}

void board::clearMissingCol(int x, int value) {
    for (int y=0; y<9; y++) {
        if ((*getCell(x, y)).getState() != cellState::FOUND && (*getCell(x, y)).isMissing(value) == true) {
            (*getCell(x, y)).removeMissing(value);
            if ((*getCell(x, y)).getMissingSize() == 0) {
                (*getCell(x, y)).setState(FOUND);
                this->found += 1;
                (*getCell(x, y)).setValue(value);
                missingIndex.remove((*getCell(x, y)));
            }
        }
    }
}

void board::clearMissingSquare(int cellX, int cellY, int cellValue){
    int flooredX = (floor(cellX/3)*3);
    int flooredY = (floor(cellY/3)*3);
    for (int x = flooredX; x<flooredX+3; x++) {
        for (int y = flooredY; y<flooredY+3; y++) {
            if ((*getCell(x, y)).getState() != cellState::FOUND && (*getCell(x, y)).isMissing(cellValue) == true) {
                (*getCell(x, y)).removeMissing(cellValue);
                if ((*getCell(x, y)).getMissingSize() == 0) {
                    (*getCell(x, y)).setState(FOUND);
                    this->found += 1;
                    (*getCell(x, y)).setValue(cellValue);
                    missingIndex.remove((*getCell(x, y)));
                }
            }
        }
    }
};

bool board::isSolved() {
    return solved;
}