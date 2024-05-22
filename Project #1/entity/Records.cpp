//
// Created by jairj on 10/11/2021.
//
#include "Records.h"

Records::Records() {
    students= nullptr;
    numberOfStudents=0;
    averageGPA=0;
}
Records::Records(JLinkedList<Student> *students) {
    this->students=students;
    this->numberOfStudents= getNumberOfStudents();
    this->averageGPA=getAverageGpa();
}

uint32_t Records::getNumberOfStudents() {
    return students->getSize();
}

void Records::setNumberOfStudents(uint32_t numberOfStudents) {
    Records::numberOfStudents = numberOfStudents;
}

double Records::getAverageGpa(){
    auto *p = students->getHead();
    double totalGPA=0;
    while(p){
        totalGPA += p->getData().getGpa();
        p=p->getNext();
    }
    averageGPA = totalGPA/students->getSize();
    return averageGPA;
}

void Records::setAverageGpa(double averageGpa) {
    averageGPA = averageGpa;
}

JLinkedList<Student> *Records::getStudents() const {
    return students;
}

void Records::setStudents(JLinkedList<Student> *students) {
    Records::students = students;
}

