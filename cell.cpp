#include <iostream>
#include "cell.h"
#include <algorithm>

/* std::list<int> missing;
cellState state; */

cell::cell(){
    missing = {1,3,4,5,7};
    state = NOTFOUND;
};

bool cell::isMissing(int val){
   std::list<int>::iterator it = std::find(missing.begin(), missing.end(), val);
   if(it != missing.end()){
       return true;
   }
   else {
       return false;
   }
};

void cell::removeMissing(int val){
   std::list<int>::iterator it = std::find(missing.begin(), missing.end(), val);
   if(it != missing.end()){
       missing.erase(it);
   }
};

void cell::pushMissing(int val){
    missing.push_back(val);
};

cellState cell::getState(){
    return state;
};

void cell::setState(cellState state){
    this->state = state;
};

void cell::toString(){
    std::list<int>::iterator it;
    for(it = missing.begin(); it != missing.end(); it++){
        std::cout << ' ' << *it;
    }

    std::cout << '\n';
}

