//
// Created by jairj on 10/10/2021.
//this is the implementation of a Person

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include <iostream>

class Person{
    std::string name;
    uint8_t age; //for the purpose of understanding the main material in this project, I don't feel the need to implement age based on birthdays, unless I have time left

public:
    Person();
    Person( std::string name, uint8_t age);
    const std::string getName() ;
    void setName(const std::string name);
    uint8_t getAge();
    void setAge(const uint8_t age);
    //simple print using different lines
    void print();

};
#endif //UNTITLED_PERSON_H
