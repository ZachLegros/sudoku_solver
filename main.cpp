#include <iostream>
#include "cell.h"

int main(){
    //cell test
    cell myCell;
    myCell.toString();
    myCell.pushMissing(9);
    myCell.removeMissing(3);
    myCell.toString();

    std::cout << myCell.getState() << '\n';
    myCell.setState(FOUND);
    std::cout << myCell.getState() << '\n';

    std::cout << myCell.isMissing(5) << ' ' << myCell.isMissing(3) << '\n';

    return 0;
}