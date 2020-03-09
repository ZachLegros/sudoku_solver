#include <iostream>
#include "cell.h"
#include "board.h"
#include <array>

int main(){
    std::array<int, 81> INIT = {7, 0, 8, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 6, 3, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 9, 0, 0, 9, 0, 6, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};   
    board sudoku(INIT);
    sudoku.toString();
    
    return 0;
}