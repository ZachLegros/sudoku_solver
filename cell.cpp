#include <iostream>
#include "cell.h"
#include <algorithm>

cell::cell(int value){
    missing = {1,2,3,4,5,6,7,8,9};
    state = NOTFOUND;
    this->value = value;
};

std::list<int> cell::getMissing(){
    return missing;
};

void cell::removeMissing(int val){
   std::list<int>::iterator it = std::find(missing.begin(), missing.end(), val);
   if(it != missing.end()){
       missing.erase(it);
   }
};

bool cell::isMissing(int val) {
    std::list<int>::iterator it = std::find(missing.begin(), missing.end(), val);
    if(it != missing.end()){
        return true;
    }
    return false;
}

void cell::clearMissing(){
    missing.clear();
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
        std::cout << *it << " ";
    }

    std::cout << '\n';
};

int cell::getValue(){
    return value;
};

void cell::setValue(int val){
    value = val;
};

int cell::getMissingSize() {
    return missing.size();
}