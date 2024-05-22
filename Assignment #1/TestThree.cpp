//
// Created by Jair on 9/9/2021.
//

//
// Created by Jair on 9/9/2021.
//
#include <iostream>
#include "../classes/BabySteps.h"
#include "../classes/BabySteps2.h"

int main() {

    std::cout<<"Assignment One Test Three"<<std::endl;

    BabySteps *b = new BabySteps2(10);
    std::cout<<"the array: "<<std::endl;
    b->print();
    //max
    std::cout<< "the max value in the array is: "<<b->max()<<std::endl;
    //min
    std::cout<< "the min value in the array is: "<<b->min()<<std::endl;

    //getmemyval
    std::cout<<"amount of numbers with value as ten is: "<<b->getMeMyValue()<<std::endl<<std::endl;
    //set vals
    std::cout<<"values changed for =>\nindex:5 value:10\nindex:9 value:10\nindex:4 value:777"<<std::endl;
    b->set(5,10);
    b->set(9,10);
    b->set(4,777);

    //getmemyval
    std::cout<<"now the updated amount of numbers with value as ten is: "<<b->getMeMyValue()<<std::endl;
    //getval
    std::cout<<"get the value at index 7: "<<b->get(7)<<std::endl;

    std::cout<<"the array: "<<std::endl;
    b->print();

    delete b;
    b= nullptr;
    return 0;
}
