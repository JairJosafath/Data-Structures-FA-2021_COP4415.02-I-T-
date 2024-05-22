#ifndef BABYSTEPS_H
#define BABYSTEPS_H

#include <cstdint>
#include <iostream>

class BabySteps {
    uint16_t size;
    uint16_t *uint16_array;

protected:
    uint16_t getSize();
    uint16_t* getArray ();
public:
    BabySteps(int val = 1);
    ~BabySteps();
    uint16_t max();
    uint16_t min();

    virtual uint32_t getMeMyValue();
    void set(uint32_t index, uint16_t value);

    uint16_t get(uint32_t index);
    void print();

};

#endif BABYSTEPS_H