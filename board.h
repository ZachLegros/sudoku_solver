#ifndef _BOARD_H_
#define _BOARD_H_
#include "cell.h"
#include <map>
#include <array>

class board{
    private:
        std::map<int, cell> map;
    public:
        board(std::array<int, 81>);
        cell* getCell(int x, int y);
       // bool checkRow(int row, int cellValue);
       // bool checkCol(int col, int cellValue);
       // bool checkSquare(int cellX, int cellY, int cellValue);
        void toString();
        int getIndex(int x, int y);
        void eliminateMissing();
        void clearMissingSquare(int x, int y, int value);
        void clearMissingRow(int y, int value);
        void clearMissingCol(int x, int value);
};

#endif
