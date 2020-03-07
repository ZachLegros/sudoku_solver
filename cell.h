#ifndef _CELL_H_
#define _CELL_H_
#include "coordinates.h"
#include "cellState.h"
#include <list>

class cell{
    private:
        std::list<int> missing;
        cellState state;
    public:
        cell();
        bool isMissing(int value);
        void removeMissing(int value);
        void pushMissing(int value);
        cellState getState();
        void setState(cellState state);
        void toString();
};

#endif