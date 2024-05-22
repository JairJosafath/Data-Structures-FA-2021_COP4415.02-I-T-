#include <iostream>
#include "DynamicArray.cpp"

int main() {
    //DynamicArray<uint16_t> arr(4);

    auto arr= new DynamicArray<uint16_t>;
    arr->create(12);
    for(int i=0;i<arr->getSize();i++){
        std::cout<<*(arr->getArray()+i)<<std::endl;
    }
    std::cout<<"--------"<<std::endl;
    std::cout<<"array is empty:"<<arr->isEmpty()
    <<std::endl;
    arr->copy(32,4);
    for(int i=0;i<arr->getSize();i++){
        std::cout<<*(arr->getArray()+i)<<std::endl;
    }
    std::cout<<"--------"<<std::endl;
    std::cout<<"array is empty:"<<arr->isEmpty()
             <<std::endl;
    arr->clear();

    for(int i=0;i<arr->getSize();i++){
        std::cout<<*(arr->getArray()+i)<<std::endl;
    }
    std::cout<<"--------"<<std::endl;
    std::cout<<"array is empty:"<<arr->isEmpty()
             <<std::endl;

    return 0;
}
