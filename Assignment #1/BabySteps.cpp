//
// Created by Jair on 9/9/2021.
//

#include "BabySteps.h"
#include <stdlib.h>

BabySteps::BabySteps(int val) {
    uint16_array = new uint16_t [val];
    size=val;
    //populate the array with random numbers.
    for(int i = 0; i < val; i++){
        *(uint16_array+i)= ((rand() % 1000));
    }

}
uint16_t BabySteps::max() {
    uint16_t max_index=0;
    for(int i =0;i<size;i++){
        if(*(uint16_array+max_index)<*(uint16_array+i)) max_index =i;
    }

    return *(uint16_array+max_index);
}

uint16_t BabySteps::min() {
    uint16_t min_index=0;
    for(int i =0;i<size;i++){
        if(*(uint16_array+min_index)>*(uint16_array+i)) min_index =i;
    }

    return *(uint16_array+min_index);
}

uint32_t BabySteps::getMeMyValue() {
    uint16_t sum=0;
    for(int i=0;i<size;i++){
        if(*(uint16_array+i)==0)sum++;
    }
    return sum;
}

void BabySteps::set(uint32_t index, uint16_t value) {
    *(uint16_array+index)=value;
}

uint16_t BabySteps:: get(uint32_t index){
    return *(uint16_array+index);
}

void BabySteps::print() {
    //print array uppon construction
    for(int i = 0; i < size; i++){
        std::cout<<"[index :"<<i<<" |value :"<<*(uint16_array+i)<<"]"<<std::endl;
    }
}

uint16_t BabySteps::getSize() {
    return size;
}
uint16_t* BabySteps::getArray() {
    return uint16_array;
}
BabySteps::~BabySteps() {
    delete uint16_array;
    uint16_array= nullptr;
}

