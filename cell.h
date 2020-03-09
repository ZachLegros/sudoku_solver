#ifndef _CELL_H_
#define _CELL_H_
#include "cellState.h"
#include <list>

class cell{
    private:
        std::list<int> missing;
        cellState state;
        int value;
    public:
        cell(int value);
        std::list<int> getMissing();
        void removeMissing(int value);
        void clearMissing();
        bool isMissing(int value);
        void pushMissing(int value);
        cellState getState();
        void setState(cellState state);
        void toString();
        int getValue();
        void setValue(int value);
        bool test();
};

#endif