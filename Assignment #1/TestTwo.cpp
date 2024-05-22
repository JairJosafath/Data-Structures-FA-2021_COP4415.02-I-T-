//
// Created by Jair on 9/9/2021.
//
#include "../classes/BabySteps.h"
#include <iomanip>
#include <iostream>

void control(BabySteps *b, int choice){

    int index=0;
    int value=0;
    switch (choice) {
        case 0:return;
        case 1:
            b->print();
            break;
        case 2:
            std::cout<< "the max value in the array is: "<<b->max()<<std::endl;
            break;
        case 3:
            std::cout<< "the min value in the array is: "<<b->min()<<std::endl;
            break;
        case 4:
            std::cout<<"amount of numbers with value as zero is: "<<b->getMeMyValue()<<std::endl<<std::endl;
            break;
        case 5:
            std::cout<<"change value at index: "<<std::endl;
            std::cin>>index;
            std::cout<<"new value: "<<std::endl;
            std::cin>>value;
            b->set(index,value);
            std::cout<<"value changed at => index: "<<index<<" to "<<value<<std::endl;
            break;
        case 6:
            std::cout<<"get value at index: "<<std::endl;
             std::cin>>index;
            std::cout<<"value: "<<b->get(index)<<std::endl;
            break;
        default:std::cout<<"please choose one of the given options.."<<std::endl;

    }

}
int main(){
    std::cout<<"Assignment One Test Two"<<std::endl;
    int size;
    std::cout<<"number of values in the array: "<<std::endl;
    std::cin>> size;

    BabySteps *b = new BabySteps(size);

    int choice = 0;
    do{
        bool correctInput = false;
        while(!correctInput) {
            std::cout << "\nplease choose an option\n1 : show array\n2 : max value\n3 : min value"
                         "\n4 : with value equal to 0\n5 : change value in array"
                         "\n6 : get value in array\n0 : to end program" << std::endl;
            std::cin >> choice;
            if (choice < 7&&choice>=0)correctInput = true;
        }if(choice==0)break;
        control(b,choice);
    }while(choice!=0);
    return 0;
}