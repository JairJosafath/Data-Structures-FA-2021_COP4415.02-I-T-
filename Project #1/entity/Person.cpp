//
// Created by jairj on 10/11/2021.
//
#include "Person.h"
#include "iostream"


Person::Person(){
    name="";
    age=0;
}


Person::Person(std::string name, uint8_t age) {
    this->age=age;
    this->name=name;
}

const std::string Person::getName() {
    return name;
} ;

void Person ::setName(const std::string name){
    this->name=name;
};

uint8_t Person:: getAge(){
    return age;
};
void  Person::setAge(const uint8_t age){
    this->age=age;
};
void Person:: print(){
    std::cout<<"Name: "<<name<<
    "\nAge: "<<unsigned(age)<<std::endl;
};