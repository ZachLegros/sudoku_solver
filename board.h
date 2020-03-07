#ifndef _BOARD_H_
#define _BOARD_H_
#include "cell.h"
#include <map>
#include "coordinates.h"
#include <array>

class board{
    private:
        std::map<coordinates, cell> map;
    public:
        board(std::array<int, 81>);
        cell getCell(int x, int y);
        bool checkRow(int row, int cellValue);
        bool checkCol(int col, int cellValue);
        bool checkSquare(int cellX, int cellY);
        
};

#endif
