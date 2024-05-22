//
// Created by Jair on 9/22/2021.
//

//I tried for past 2 days to split the class
// in a .h and .cpp file, I could not figure out
// how to avoid the errors, So i created it in one class instead
#include <cstdint>

template <typename T>

class DynamicArray
{
    T *array= nullptr;
    uint16_t size=0;

public:

    void create(uint16_t size) {
        this->size=size;
        array=new T[size];
        for(int i = 0; i < size; i++){
            *(array + i)= NULL;
        }
    }

    void clear() {

        //the array is not destroyed but the elements are removed
        for(int i = 0; i < size; i++){
            *(array + i)= NULL;
        }
    }

    bool isEmpty() {
        for(int i = 0; i < size; i++){
            //just learned that it automatically checks if its null or not
            if(*(array + i))return false;
        }
        return true;
    }

    void copy(T object, uint16_t index) {
        *(array+index)=object;
    }

    T *getArray() const {
        return array;
    }

    uint16_t getSize() const {
        return size;
    }
};
