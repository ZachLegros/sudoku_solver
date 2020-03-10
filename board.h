#ifndef _BOARD_H_
#define _BOARD_H_
#include "cell.h"
#include <map>
#include <array>
#include <list>

class board{
    private:
        std::map<int, cell> map;
        std::list<int> missingIndex = {};
        int found = 0;
        bool solved = false;
    public:
        board(std::array<int, 81>);
        board(std::map<int, cell> init, std::list<int> missingIndex, int found);
        cell* getCell(int x, int y);
        void toString();
        int getIndex(int x, int y);
        void eliminateMissing(int found);
        void clearMissingSquare(int x, int y, int value);
        void clearMissingRow(int y, int value);
        void clearMissingCol(int x, int value);
        void solve();
};

#endif
