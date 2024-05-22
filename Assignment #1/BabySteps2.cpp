//
// Created by Jair on 9/9/2021.
//

#include "BabySteps2.h"
BabySteps2::BabySteps2(int val): BabySteps(val){
    // this constructor sends the value to the base class, so the base class constructor can use it
}
uint32_t BabySteps2::getMeMyValue() {
    uint16_t sum=0;
    for(int i=0;i<getSize();i++){
        if(*(getArray()+i)==10)sum++;
    }
    return sum;
}