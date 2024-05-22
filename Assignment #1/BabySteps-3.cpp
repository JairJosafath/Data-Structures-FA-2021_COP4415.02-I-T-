//
// Created by Jair on 9/9/2021.
//

#include "BabySteps.h"
#include <stdlib.h>

BabySteps::BabySteps(int val) {
    N = new uint16_t [val];
    size=val;
    //populate the array with random numbers.
    for(int i = 0; i < val; i++){
        *(N + i)= ((rand() % 1000));
    }

}
uint16_t BabySteps::max() {
    uint16_t max_index=0;
    for(int i =0;i<size;i++){
        if(*(N + max_index) < *(N + i)) max_index =i;
    }

    return *(N + max_index);
}

uint16_t BabySteps::min() {
    uint16_t min_index=0;
    for(int i =0;i<size;i++){
        if(*(N + min_index) > *(N + i)) min_index =i;
    }

    return *(N + min_index);
}

uint32_t BabySteps::getMeMyValue() {
    uint16_t sum=0;
    for(int i=0;i<size;i++){
        if(*(N + i) == 0)sum++;
    }
    return sum;
}

void BabySteps::set(uint32_t index, uint16_t value) {
    *(N + index)=value;
}

uint16_t BabySteps:: get(uint32_t index){
    return *(N + index);
}

void BabySteps::print() {
    //print array uppon construction
    for(int i = 0; i < size; i++){
        std::cout << "[index :" << i << " |value :" << *(N + i) << "]" << std::endl;
    }
}

uint16_t BabySteps::getSize() {
    return size;
}
uint16_t* BabySteps::getArray() {
    return N;
}
BabySteps::~BabySteps() {
    delete N;
    N= nullptr;
}

