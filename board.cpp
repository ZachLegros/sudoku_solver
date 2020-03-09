#include "board.h"
#include <iostream>
#include <map>
#include <array>
#include <cmath>

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

cell board::getCell(int x, int y){
    return map.at(getIndex(x, y));
};

int board::getIndex(int x, int y){
    return (y*9)+x;
};

bool board::checkRow(int row, int cellValue){
    return true;

};

bool board::checkCol(int col, int cellValue){
    return true;

};

bool board::checkSquare(int cellX, int cellY){
    return true;
};

void board::toString(){
    using namespace std;
    string characters;
    int val;
    cout << "   0 1 2 3 4 5 6 7 8\n" << "  +-----------------+\n";
    for (int i = 0; i < 9; i++) {
        cout << ' ' << i << '|';
        for(int j=0; j < 9; j++) {
            val = getCell(j, i).getValue();
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



