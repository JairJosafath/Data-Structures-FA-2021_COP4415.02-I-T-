#include <iostream>
#include "../classes/BabySteps.h"

int main() {

    std::cout<<"Assignment One Test One"<<std::endl;

    BabySteps *b = new BabySteps(10);
    std::cout<<"the array: "<<std::endl;
    b->print();
    //max
    std::cout<< "the max value in the array is: "<<b->max()<<std::endl;
    //min
    std::cout<< "the min value in the array is: "<<b->min()<<std::endl;

    //getmemyval
    std::cout<<"amount of numbers with value as zero is: "<<b->getMeMyValue()<<std::endl<<std::endl;
    //set vals
    std::cout<<"values changed for =>\nindex:5 value:0\nindex:9 value:0\nindex:4 value:777"<<std::endl;
    b->set(5,0);
    b->set(9,0);
    b->set(4,777);

    //getmemyval
    std::cout<<"now the updated amount of numbers with value as zero is: "<<b->getMeMyValue()<<std::endl;
    //getval
    std::cout<<"get the value at index 7: "<<b->get(7)<<std::endl;

    std::cout<<"the array: "<<std::endl;
    b->print();

    delete b;
    b= nullptr;
    return 0;
}
