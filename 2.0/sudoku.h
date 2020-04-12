#ifndef _SUDOKU_H_
#define _SUDOKU_H_

class Sudoku

{
    private:
        int** grid;
    public:
        Sudoku(int** grid);
        bool isPossible(int x, int y, int n);
        void solve();
        void toString();
};

#endif